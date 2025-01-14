

#include "examshell.h"

void exec_cmd(t_params *params)
{
    int fd[2];
    int status;
    t_cmd *current;
    int tab;

    status = 0;
    tab = 0;
    params->pid_tab = malloc(sizeof(pid_t) * ft_get_pid_nbr(params));
    if (!params->pid_tab)
    {
        perror("malloc");
        cleanup_and_exit(params, EXIT_FAILURE);
    }
    ft_memset(params->pid_tab, 0, sizeof(pid_t) * ft_get_pid_nbr(params));
    
    current = params->command; // Initialisation de la commande actuelle
    if (!current)
    {
        free(params->pid_tab);
        return; // Rien à exécuter
    }

    // Si une seule commande et qu'elle est un builtin
    if (current->cmd && current->cmd[0] && isbuiltins(current->cmd[0]) && current->next == NULL)
    {
        exec_builtins(params, current);
        free(params->pid_tab);
        return;
    }

    // Boucle pour créer les processus et gérer les pipes
    while (current != NULL)
    {
        if (current->next && pipe(fd) == -1)
        {
            perror("pipe");
            cleanup_and_exit(params, EXIT_FAILURE);
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

        if (params->pid_tab[tab] == 0) // Processus enfant
        {
            if (params->prev_pipe_read != -1)
            {
                dup2(params->prev_pipe_read, STDIN_FILENO);
                close(params->prev_pipe_read);
            }
            if (current->next)
            {
                dup2(fd[1], STDOUT_FILENO);
                close(fd[1]);
                close(fd[0]);
            }
            if (isbuiltins(current->cmd[0]))
                run_builtins(current->cmd, params);
            execve(current->cmd[0], current->cmd, params->envp);
            perror("execve");
            cleanup_and_exit(params, EXIT_FAILURE);
        }
        else // Processus parent
        {
            if (params->prev_pipe_read != -1)
                close(params->prev_pipe_read);
            if (current->next)
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
        current = current->next;
    }

    // Attente de tous les processus enfants
    for (int i = 0; i < tab; i++)
    {
        waitpid(params->pid_tab[i], &status, 0);
        if (WIFEXITED(status))
            params->last_exit_code = WEXITSTATUS(status);
        else if (WIFSIGNALED(status))
            params->last_exit_code = 128 + WTERMSIG(status);
    }

    free(params->pid_tab);
    dup2(params->fd_in, STDIN_FILENO);
    dup2(params->fd_out, STDOUT_FILENO);
}

