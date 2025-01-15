https://www.flipcode.com/archives/The_Art_of_Demomaking-Issue_11_Particle_Systems.shtml
https://www.youtube.com/watch?v=0Dbp_VrrL3Q
https://www.youtube.com/watch?v=6b6kE4jC2UY


void werror(char *error)
{
    write(2, error, strlen(error));
}

int	ft_get_pid_nbr(char **argv)
{
	int		nbr;
    int     i;

	nbr = 0;
    i = 0;
	while (argv[i] != NULL)
	{
		if (argv[i] && (strcmp(argv[i], "|") == 0 || strcmp(argv[i], ";") == 0))
		{
			i++;
			continue ;
		}
		i++;
		nbr++;
	}
	return (nbr);
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

int	main(int argc, char **argv, char **envp)
{
	if (argc == 1)
    {
        werror("error: fatal\n");
        return 1;
    }
    int	status;
    pid_t *pid_tab;
	status = 0;
    int i = 1;

	pid_tab = malloc(sizeof(pid_t) * ft_get_pid_nbr(argv));
	if (!pid_tab)
	{
		werror("error: fatal\n");
		exit(1);
	}
	memset(pid_tab, 0, sizeof(pid_t) * ft_get_pid_nbr(argv));
    if (argv[1] && argv[1][0] != '\0'
		&& !strcmp(argv[1], "cd") && argv[3] == NULL)
	{
		status = cd(argv, i);
        free(pid_tab);
        return (status);
	}
	else
	{
        int     i;
        int		fd[2];
        int		tab;
        int     prev_pipe_read;
        char *cmd[256];

        i = 0;
        tab = 0;
        while (argv[i] != NULL)
        {
            while (argv[i] != NULL && (strcmp(argv[i], "|") == 0 || strcmp(argv[i], ";") == 0))
                i++;
            if (argv[i] != NULL)
            {
                copy_cmd(cmd, argv, &i);
                if (cmd[0] && !strcmp(cmd[0], "|"))
                {
                    if (pipe(fd) == -1)
                    {
                        werror("error: fatal\n");
                        if (prev_pipe_read != -1)
                            close(prev_pipe_read);
                        free(pid_tab);
                        exit(EXIT_FAILURE);
                    }
                }
                pid_tab[tab] = fork();
                if (pid_tab[tab] == -1)
                {
                    werror("error: fatal\n");
                    if (prev_pipe_read != -1)
                        close(prev_pipe_read);
                    if (argv[i])
                    {
                        close(fd[0]);
                        close(fd[1]);
                    }
                    free(pid_tab);
                    exit(EXIT_FAILURE);
                }
                if (pid_tab[tab] == 0)
                {
                    if (prev_pipe_read != -1)
                    {
                        dup2(prev_pipe_read, STDIN_FILENO);
                        close(prev_pipe_read);
                    }
                    if (argv[i] && !strcmp(argv[i], "|"))
                    {
                        dup2(fd[1], STDOUT_FILENO);
                        close(fd[1]);
                        close(fd[0]);
                    }
                    if (!strcmp(cmd[0], "cd"))
                    {
                        free(pid_tab);
                        exit(EXIT_FAILURE);
                    }
                    if (execve(cmd[0], cmd, envp) == -1)
                    {
                        werror("error: fatal\n");
                        free(pid_tab);
                        exit(EXIT_FAILURE);
                    }
                }
                else
                {
                    if (prev_pipe_read != -1)
                        close(prev_pipe_read);
                    if (argv[i] && !strcmp(argv[i], "|"))
                    {
                        close(fd[1]);
                        prev_pipe_read = fd[0];
                    }
                    else
                    {
                        prev_pipe_read = -1;
                    }
                }
                tab++;
                i++;
                if (argv[i] && !strcmp(argv[i], "|"))
                    i++;
            }
            //wait_pid
            tab = 0;
            while (argv[i] != NULL)
            {
                if (argv[i] && (!strcmp(argv[i], "|") || !strcmp(argv[i], ";")))
                {
                    i++;
                    continue ;
                }
                waitpid(pid_tab[tab], &status, 0);
                if (WIFEXITED(status) || WIFSIGNALED(status))
                return (WIFEXITED(status) && WEXITSTATUS(status));
                i++;
                tab++;
            }
            while (argv[i] != NULL && (strcmp(argv[i], "|") == 0 || strcmp(argv[i], ";") == 0))
                i++;
        }
	}
	free(pid_tab);
    return (WIFEXITED(status) && WEXITSTATUS(status));
}