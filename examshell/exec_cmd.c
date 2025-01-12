

#include "examshell.h"

void	exec_cmd(t_params *params)
{
	int		fd[2];
	int		status;
	t_cmd	*current;
	int		tab;

	status = 0;
	params->pid_tab = malloc(sizeof(pid_t) * ft_get_pid_nbr(params));
	if (!params->pid_tab)
	{
		perror("malloc");
		cleanup_and_exit(params, EXIT_FAILURE);
	}
	ft_memset(params->pid_tab, 0, sizeof(pid_t) * ft_get_pid_nbr(params));
	if (call_exec_builtins(params))
	{
		free(params->pid_tab);
		return;
	}
	current = params->command;
	tab = 0;
	while (current != NULL)
	{
		if (ft_check_continue(params, &current))
			continue;
		check_pipe_error(current, fd, params);
		params->pid_tab[tab] = fork();
		check_fork_error(params, current, tab, fd);
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
				run_builtins(current->cmd, params);
			else if (!check_cmd_not_found(params, current->cmd[0]))
				execve(current->cmd[0], current->cmd, params->envp);
			cleanup_and_exit(params, params->last_exit_code);
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
				params->prev_pipe_read = -1;
		}
		tab++;
		params->rank_cmd++;
		current = current->next;
	}
	tab = 0;
	current = params->command;
	while (current != NULL)
	{
		if (current->cmd[0] && !ft_strcmp(current->cmd[0], "|"))
		{
			current = current->next;
			continue;
		}
		waitpid(params->pid_tab[tab], &status, 0);
		if (WIFEXITED(status))
			params->last_exit_code = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			params->last_exit_code = 128 + WTERMSIG(status);
		tab++;
		current = current->next;
	}
	free(params->pid_tab);
	dup2(params->fd_in, STDIN_FILENO);
	dup2(params->fd_out, STDOUT_FILENO);
}
