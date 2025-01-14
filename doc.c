https://www.flipcode.com/archives/The_Art_of_Demomaking-Issue_11_Particle_Systems.shtml



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
    int i = 0;
    int fd[2];
    int prev_fd = -1;
    pid_t pid;

    if (argc < 2)
        return 0;

    while (argv[i] != NULL)
    {
        while (argv[i] && (strcmp(argv[i], "|") == 0 || strcmp(argv[i], ";") == 0))
            i++;
        if (!argv[i])
            break;
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
        if (is_builtin(cmd[0]))
        {
            if (exec_builtin(cmd))
                werror("error: fatal\n");
            free(cmd);
            i += cmd_len;
            continue;
        }
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
        pid = fork();
        if (pid == -1)
        {
            werror("error: fatal\n");
            free(cmd);
            exit(EXIT_FAILURE);
        }

        if (pid == 0)
        {
            if (prev_fd != -1)
            {
                dup2(prev_fd, STDIN_FILENO);
                close(prev_fd);
            }
            if (fd[1] != -1)
            {
                dup2(fd[1], STDOUT_FILENO);
                close(fd[0]);
                close(fd[1]);
            }
            execve(cmd[0], cmd, envp);
            werror("error: cannot execute executable_that_failed\n");
            free(cmd);
            exit(EXIT_FAILURE);
        }
        else
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