#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

void err(char *str)
{
    while (*str)
        write(2, str++, 1);
}

int cd(char **argv, int i)
{
    if (i != 2)
    {
        err("error: cd: bad arguments\n");
        return 1;
    }
    if (chdir(argv[1]) < 0)
    {
        err("error: cd: cannot change directory to ");
        err(argv[1]);
        err("\n");
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
            err("error: dup2 failed\n");
            exit(1);
        }
        if (close(fd[0]) == -1 || close(fd[1]) == -1)
        {
            err("error: close failed\n");
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
        err("error: pipe failed\n");
        exit(1);
    }

    if ((pid = fork()) == -1)
    {
        err("error: fork failed\n");
        exit(1);
    }

    if (pid == 0)
    {
        if (has_pipe)
            set_pipe(has_pipe, fd, 1);
        execve(*argv, argv, envp);
        err("error: cannot execute ");
        err(*argv);
        err("\n");
        exit(127);
    }

    waitpid(pid, &status, 0);
    if (has_pipe)
        set_pipe(has_pipe, fd, 0);

    return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    int i = 0;
    int status = 0;

    while (argv[i])
    {
        int cmd_len = 0;
        while (argv[i + cmd_len] && strcmp(argv[i + cmd_len], "|") != 0 && strcmp(argv[i + cmd_len], ";") != 0)
            cmd_len++;

        if (cmd_len == 0)
        {
            i++;
            continue;
        }

        char **cmd = malloc((cmd_len + 1) * sizeof(char *));
        if (!cmd)
        {
            err("error: fatal\n");
            exit(EXIT_FAILURE);
        }

        for (int j = 0; j < cmd_len; j++)
            cmd[j] = strdup(argv[i + j]);
        cmd[cmd_len] = NULL;

        status = exec(cmd, cmd_len, envp);
        free_array(cmd);

        i += cmd_len;
        if (argv[i] && (strcmp(argv[i], "|") == 0 || strcmp(argv[i], ";") == 0))
            i++;
    }
    return status;
}


