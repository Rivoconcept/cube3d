#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

void werror(char *error)
{
    write(2, error, ft_strlen(error));
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
        return (1);
    }
    return (0);
}

void copy_cmd(char **cmd, char **argv, int *i)
{
    int j = 0;
    while (argv[*i] && strcmp(argv[*i], "|") != 0 && strcmp(argv[*i], ";") != 0)
    {
        cmd[j++] = argv[*i];
        (*i)++;
    }
    cmd[j] = NULL;
}

int main(int argc, char **argv, char **envp)
{
    if (argc < 2)
    {
        werror("error: fatal\n");
        return (1);
    }
    int i = 1;
    int status = 0;
    int prev_pipe_read = -1;
    int token_pipe;
    int fd[2];
    char *cmd[256];
    pid_t pid;
    while (argv[i])
    {
        while (argv[i] && (strcmp(argv[i], "|") == 0 || strcmp(argv[i], ";") == 0))
            i++;
        if (argv[i] == NULL)
            break;
        copy_cmd(cmd, argv, &i);
        if (strcmp(cmd[0], "cd") == 0)
        {
            if (cd(cmd))
                status = 1;
            continue;
        }
        token_pipe = (argv[i] && strcmp(argv[i], "|") == 0);
        if (token_pipe && pipe(fd) == -1)
        {
            werror("error: fatal\n");
            return 1;
        }
        pid = fork();
        if (pid == -1)
        {
            werror("error: fatal\n");
            return 1;
        }
        if (pid == 0)
        {
             if (prev_pipe_read != -1)
            {
                dup2(prev_pipe_read, STDIN_FILENO);
                close(prev_pipe_read);
            }
            if (token_pipe)
            {
                dup2(fd[1], STDOUT_FILENO);
                close(fd[1]);
                close(fd[0]);
            }
            if (execve(cmd[0], cmd, envp) == -1)
            {
                werror("error: cannot execute ");
                werror(cmd[0]);
                werror("\n");
                exit(1);
            }
        }
        else
        {
            if (prev_pipe_read != -1)
                close(prev_pipe_read);
            if (token_pipe)
            {
                close(fd[1]);
                prev_pipe_read = fd[0];
            }
            else
                prev_pipe_read = -1;

            waitpid(pid, &status, 0);
            if (WIFEXITED(status))
                status = WEXITSTATUS(status);
        }
        if (argv[i] && strcmp(argv[i], "|") == 0)
            i++;
    }
    return status;
}


