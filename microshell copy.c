#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

#include <errno.h>


void werror(char *error)
{
    write(2, error, strlen(error));
}

int get_nbr_pipe(char **argv)
{
    int i = 0;
    int j = 0;
    while (argv[i] != NULL)
    {
        if (strcmp(argv[i], "|") == 0)
            j++;
        i++;
    }
    return j;
}

int get_cmd_length(char **argv, int i)
{
    int len = 0;
    while (argv[i] != NULL && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
    {
        len++;
        i++;
    }
    return len;
}

int cd(char **argv, int i)
{
    if (i != 2)
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

void set_pipe(int has_pipe, int *fd, int end)
{
    if (has_pipe)
    {
        if (dup2(fd[end], end) == -1)
        {
            werror("error: dup2 failed\n");
            exit(1);
        }
        if (close(fd[0]) == -1 || close(fd[1]) == -1)
        {
            werror("error: close failed\n");
            exit(1);
        }
    }
}

void free_array(char **cmd)
{
    int i = 0;
    if (!cmd)
        return;
    while (cmd[i] != NULL)
    {
        free(cmd[i]);
        cmd[i] = NULL;
        i++;
    }
    free(cmd);
}

int exec(char **argv, int i, char **envp)
{
    int has_pipe = 0;
    int fd[2];
    int pid;
    int status;

    if (argv[i] != NULL && strcmp(argv[i], "|") == 0)
        has_pipe = 1;

    if (!has_pipe && strcmp(*argv, "cd") == 0)
        return cd(argv, i);

    if (has_pipe && pipe(fd) == -1)
    {
        werror("error: pipe failed\n");
        return 1;
    }

    if ((pid = fork()) == -1)
    {
        werror("error: fork failed: ");
        werror(strerror(errno));
        werror("\n");
        return 1;
    }

    if (pid == 0) // Processus enfant
    {
        if (has_pipe)
            set_pipe(has_pipe, fd, 1);
        execve(*argv, argv, envp);
        werror("error: cannot execute ");
        werror(*argv);
        werror("\n");
        exit(127);
    }

    // Processus parent
    if (has_pipe)
        set_pipe(has_pipe, fd, 0);

    waitpid(pid, &status, 0); // Attendre le processus enfant
    return WIFEXITED(status) && WEXITSTATUS(status);
}


void copy_cmd(char **cmd, char **argv, int *i)
{
    int j = 0;
    while (argv[*i] != NULL && strcmp(argv[*i], "|") != 0 && strcmp(argv[*i], ";") != 0)
    {
        cmd[j] = argv[*i];
        j++;
        (*i)++;
    }
    cmd[j] = NULL;
}

int main(int argc, char **argv, char **envp)
{
    if (argc == 1)
    {
        werror("error: fatal\n");
        return 1;
    }

    int i = 0;
    int status = 0;
    char *cmd[256];

    while (argv[i] != NULL)
    {
        // Sauter les séparateurs initiaux
       /* while (argv[i] != NULL && (strcmp(argv[i], "|") == 0 || strcmp(argv[i], ";") == 0))
            i++;*/

        if (argv[i] != NULL)
        {
            copy_cmd(cmd, argv, &i);
            status = exec(cmd, 0, envp);

            // Sauter les séparateurs restants après une commande
            while (argv[i] != NULL && (strcmp(argv[i], "|") == 0 || strcmp(argv[i], ";") == 0))
                i++;
        }
    }

    return status;
}




