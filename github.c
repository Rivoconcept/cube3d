void err(char *str)
{
	while (*str)
		write(2, str++, 1);
}

int cd(char **argv, int i)
{
	if (i != 2)
		return err("error: cd: bad arguments\n"), 1;
	if (chdir(argv[1]) < 0)
		return err("error: cd: cannot change directory to "), err(argv[1]), err("\n"), 1;
	return 0;
}

void set_pipe(int has_pipe, int *fd, int end)
{
	if (has_pipe && (dup2(fd[end], end) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		err("error: fatal\n"), exit(1);
}

int	exec(char **argv, int i, char **envp)
{
	int has_pipe, fd[2], pid, status;
	has_pipe = argv[i] && !strcmp(argv[i], "|");

	if (!has_pipe && !strcmp(*argv, "cd"))
		return cd(argv, i);
	if (has_pipe && pipe(fd) == -1)
		err("error: fatal\n"), exit(1);
	if ((pid = fork()) == -1)
		err("error: fatal\n"), exit(1);
	if (!pid)
	{
		argv[i] = 0;
		set_pipe(has_pipe, fd, 1);
		if (!strcmp(*argv, "cd"))
			exit(cd(argv, i));
		execve(*argv, argv, envp);
		err("error: cannot execute "), err(*argv), err("\n"), exit(1);
	}
	waitpid(pid, &status, 0);
	set_pipe(has_pipe, fd, 0);
	return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	int i = 0, status = 0;

	while (argv[i])
	{
		argv += i + 1;
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (i)
			status = exec(argv, i, envp);
	}
	return status;
}

/***************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>

void werror(char *error)
{
    write(2, error, strlen(error));
}

int cd(char **argv)
{
    if (!argv[1] || argv[2])
    {
        werror("error: cd: bad arguments\n");
        return 1;
    }
    if (chdir(argv[1]) < 0)
    {
        werror("error: cd: cannot change directory to ");
        werror(argv[1]);
        werror("\n");
        return 1;
    }
    return 0;
}

int is_builtin(char *cmd)
{
    return (strcmp(cmd, "cd") == 0);
}

int exec_builtin(char **argv)
{
    if (strcmp(argv[0], "cd") == 0)
        return cd(argv);
    return 0;
}

int main(int argc, char **argv, char **envp)
{
    int i = 1;
    int fd[2];
    int prev_fd = -1;
    pid_t pid;

    if (argc < 2)
        return 0;

    while (argv[i] != NULL)
    {
        // Ignorer les séparateurs "|", ";"
        while (argv[i] && (strcmp(argv[i], "|") == 0 || strcmp(argv[i], ";") == 0))
            i++;
        if (!argv[i])
            break;

        // Récupérer la commande et ses arguments
        int cmd_len = 0;
        while (argv[i + cmd_len] && strcmp(argv[i + cmd_len], "|") != 0 && strcmp(argv[i + cmd_len], ";") != 0)
            cmd_len++;
        char **cmd = malloc((cmd_len + 1) * sizeof(char *));
        if (!cmd)
        {
            werror("error: fatal\n");
            exit(EXIT_FAILURE);
        }
        for (int j = 0; j < cmd_len; j++)
            cmd[j] = argv[i + j];
        cmd[cmd_len] = NULL;

        // Exécuter les commandes intégrées
        if (is_builtin(cmd[0]))
        {
            if (exec_builtin(cmd))
            {
                free(cmd);
                return 1;
            }
            free(cmd);
            i += cmd_len;
            continue;
        }

        // Gestion du pipe
        if (argv[i + cmd_len] && strcmp(argv[i + cmd_len], "|") == 0)
        {
            if (pipe(fd) == -1)
            {
                werror("error: fatal\n");
                free(cmd);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            fd[0] = -1;
            fd[1] = -1;
        }

        // Fork et exécution
        pid = fork();
        if (pid == -1)
        {
            werror("error: fatal\n");
            free(cmd);
            exit(EXIT_FAILURE);
        }

        if (pid == 0) // Processus enfant
        {
            if (prev_fd != -1)
            {
                if (dup2(prev_fd, STDIN_FILENO) == -1)
                {
                    werror("error: fatal\n");
                    exit(EXIT_FAILURE);
                }
                close(prev_fd);
            }
            if (fd[1] != -1)
            {
                if (dup2(fd[1], STDOUT_FILENO) == -1)
                {
                    werror("error: fatal\n");
                    exit(EXIT_FAILURE);
                }
                close(fd[0]);
                close(fd[1]);
            }
            execve(cmd[0], cmd, envp);
            werror("error: cannot execute ");
            werror(cmd[0]);
            werror("\n");
            free(cmd);
            exit(EXIT_FAILURE);
        }
        else // Processus parent
        {
            if (prev_fd != -1)
                close(prev_fd);
            if (fd[1] != -1)
            {
                close(fd[1]);
                prev_fd = fd[0];
            }
            else
            {
                prev_fd = -1;
            }
            waitpid(pid, NULL, 0);
        }

        free(cmd);
        i += cmd_len;
    }
    return 0;
}
