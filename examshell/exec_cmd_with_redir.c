#include "examshell.h"

void	ft_handle_child(t_params *params)
{
	int		fd[2];
	t_cmd	*current;
	int		tab;

	current = params->command;
	tab = 0;
	while (current != NULL)
	{
        if (current->cmd[0] && !ft_strcmp(current->cmd[0], "|"))
        {
            current = current->next;
            params->rank_cmd++;
            continue ;
        }
        if (current->next && !ft_strcmp(current->next->cmd[0], "|"))
        {
            if (pipe(fd) == -1)
            {
                perror("pipe");
                if (params->prev_pipe_read != -1)
                    close(params->prev_pipe_read);
                free(params->pid_tab);
                cleanup_and_exit(params, EXIT_FAILURE);
            }
        }
		params->pid_tab[tab] = fork();
        if (params->pid_tab[tab] == -1)
        {
            perror("fork");
            if (params->prev_pipe_read != -1)
                close(params->prev_pipe_read);
            if (current->next)
            {
                close(fd[0]);
                close(fd[1]);
            }
            cleanup_and_exit(params, EXIT_FAILURE);
        }
        if (params->pid_tab[tab] == 0)
        {
            close(params->fd_in);
            close(params->fd_out);
            if (params->prev_pipe_read != -1)
            {
                dup2(params->prev_pipe_read, STDIN_FILENO);
                close(params->prev_pipe_read);
            }
            if (current->next && !ft_strcmp(current->next->cmd[0], "|"))
            {
                dup2(fd[1], STDOUT_FILENO);
                close(fd[1]);
                close(fd[0]);
            }
            signal(SIGQUIT, SIG_DFL);
            input_r(current, params->rank_cmd, params, 1);
            output(current, params);
            if (isbuiltins(current->cmd[0]))
            {
                run_builtins(current->cmd, params);
                cleanup_and_exit(params, params->last_exit_code);
            }
            if (check_cmd_not_found(params, current->cmd[0]))
                cleanup_and_exit(params, params->last_exit_code);
            if (execve(current->cmd[0], current->cmd, params->envp) == -1)
            {
                perror_msg(": command not found\n", NULL);
                cleanup_and_exit(params, 127);
            }
        }
        else
        {
            if (params->prev_pipe_read != -1)
                close(params->prev_pipe_read);
            if (current->next && !ft_strcmp(current->next->cmd[0], "|"))
            {
                close(fd[1]);
                params->prev_pipe_read = fd[0];
            }
            else
            {
                params->prev_pipe_read = -1;
            }
        }
		tab++;
		params->rank_cmd++;
		current = current->next;
		if (current && !ft_strcmp(current->cmd[0], "|"))
		{
			params->rank_cmd++;
			current = current->next;
		}
	}
}



void	exec_cmd(t_params *params)
{
	int	status;
	t_cmd	*current;

	current = params->command;
	status = 0;
	if (params->envp)
		free_array(params->envp);
	params->envp = put_envp(params);
	params->pid_tab = malloc(sizeof(pid_t) * ft_get_pid_nbr(params));
	if (!params->pid_tab)
	{
		perror("malloc");
		cleanup_and_exit(params, EXIT_FAILURE);
	}
	ft_memset(params->pid_tab, 0, sizeof(pid_t) * ft_get_pid_nbr(params));
    if (current && current->cmd && current->cmd[0] && current->cmd[0][0] != '\0'
		&& isbuiltins(current->cmd[0]) && current->next == NULL)
	{
		exec_builtins(params, current);
		current = current->next;
	}
	else
	{
        int		fd[2];
        t_cmd	*current;
        int		tab;

        current = params->command;
        tab = 0;
        while (current != NULL)
        {
            if (current->cmd[0] && !ft_strcmp(current->cmd[0], "|"))
            {
                current = current->next;
                params->rank_cmd++;
                continue ;
            }
            if (current->next && !ft_strcmp(current->next->cmd[0], "|"))
            {
                if (pipe(fd) == -1)
                {
                    perror("pipe");
                    if (params->prev_pipe_read != -1)
                        close(params->prev_pipe_read);
                    free(params->pid_tab);
                    cleanup_and_exit(params, EXIT_FAILURE);
                }
            }
            params->pid_tab[tab] = fork();
            if (params->pid_tab[tab] == -1)
            {
                perror("fork");
                if (params->prev_pipe_read != -1)
                    close(params->prev_pipe_read);
                if (current->next)
                {
                    close(fd[0]);
                    close(fd[1]);
                }
                cleanup_and_exit(params, EXIT_FAILURE);
            }
            if (params->pid_tab[tab] == 0)
            {
                close(params->fd_in);
                close(params->fd_out);
                if (params->prev_pipe_read != -1)
                {
                    dup2(params->prev_pipe_read, STDIN_FILENO);
                    close(params->prev_pipe_read);
                }
                if (current->next && !ft_strcmp(current->next->cmd[0], "|"))
                {
                    dup2(fd[1], STDOUT_FILENO);
                    close(fd[1]);
                    close(fd[0]);
                }
                signal(SIGQUIT, SIG_DFL);
                input_r(current, params->rank_cmd, params, 1);
                output(current, params);
                if (isbuiltins(current->cmd[0]))
                {
                    run_builtins(current->cmd, params);
                    cleanup_and_exit(params, params->last_exit_code);
                }
                if (check_cmd_not_found(params, current->cmd[0]))
                    cleanup_and_exit(params, params->last_exit_code);
                if (execve(current->cmd[0], current->cmd, params->envp) == -1)
                {
                    perror_msg(": command not found\n", NULL);
                    cleanup_and_exit(params, 127);
                }
            }
            else
            {
                if (params->prev_pipe_read != -1)
                    close(params->prev_pipe_read);
                if (current->next && !ft_strcmp(current->next->cmd[0], "|"))
                {
                    close(fd[1]);
                    params->prev_pipe_read = fd[0];
                }
                else
                {
                    params->prev_pipe_read = -1;
                }
            }
            tab++;
            params->rank_cmd++;
            current = current->next;
            if (current && !ft_strcmp(current->cmd[0], "|"))
            {
                params->rank_cmd++;
                current = current->next;
            }
        }
        //wait_pid
        int	tab;

        tab = 0;
        while (current != NULL)
        {
            if (params && current->cmd[0] && !ft_strcmp(current->cmd[0], "|"))
            {
                current = current->next;
                continue ;
            }
            waitpid(params->pid_tab[tab], &status, 0);
            if (WIFEXITED(status))
                params->last_exit_code = WEXITSTATUS(status);
            else if (WIFSIGNALED(status))
            {
                if (WTERMSIG(status) == SIGQUIT)
                    perror_msg(": Quit (core dumped)\n", NULL);
                params->last_exit_code = 128 + WTERMSIG(status);
            }
            current = current->next;
            tab++;
        }
	}
	free(params->pid_tab);
	dup2(params->fd_in, STDIN_FILENO);
	dup2(params->fd_out, STDOUT_FILENO);
}