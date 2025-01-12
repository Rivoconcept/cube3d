/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:39:09 by rhanitra          #+#    #+#             */
/*   Updated: 2024/12/10 18:21:09 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "examshell.h"

int put_nbr_pipes(t_cmd *command)
{
    int count;

    count = 0;
    while (command != NULL)
    {
        if (!ft_strcmp(command->cmd[0], "|"))
            count++;
        command = command->next;
    }
    return (count);
}

void init_pipe_fd(int ***fd, t_cmd *cmd)
{
    int i;
    int pipe_count;

    i = 0;
    pipe_count = put_nbr_pipes(cmd);
    *fd = (int **)malloc(sizeof(int *) * (pipe_count));
    if (!*fd)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    while (i < pipe_count)
    {
        (*fd)[i] = (int *)malloc(sizeof(int) * 2);
        if (!(*fd)[i])
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        if (pipe((*fd)[i]) == -1)
        {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
        i++;
    }
}

void clean_pipe_fd(int ***fd,  int pipe_count)
{
    int i;

    i = 0;
    while (i < pipe_count)
    {
        close((*fd)[i][0]);
        close((*fd)[i][1]);
        free((*fd)[i]);
        i++;
    }
    free(*fd);
    *fd = NULL;
}

void exec_cmd(t_cmd *command, char **envp)
{
    int i = 0;
    int nbr_pipes = put_nbr_pipes(command);
    int **fd;
    pid_t pid;

    // Initialisation des pipes
    init_pipe_fd(&fd, command);

    while (command != NULL)
    {
        // Ignorer les séparateurs
        if (!ft_strcmp(command->cmd[0], "|") || !ft_strcmp(command->cmd[0], ";"))
        {
            command = command->next;
            continue;
        }
        if (!ft_strcmp(command->cmd[0], "cd"))
        {
            printf("oui\n");
            command = command->next;
            continue;
        }
        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            clean_pipe_fd(&fd, nbr_pipes);
            exit(EXIT_FAILURE);
        }
        if (pid == 0) // Processus enfant
        {
            // Redirections pour les pipes
            if (command->previous && !ft_strcmp(command->previous->cmd[0], "|"))
            {
                if (dup2(fd[i - 1][0], STDIN_FILENO) == -1)
                {
                    perror("dup2");
                    clean_pipe_fd(&fd, nbr_pipes);
                    exit(EXIT_FAILURE);
                }
            }
            if (command->next && !ft_strcmp(command->next->cmd[0], "|"))
            {
                if (dup2(fd[i][1], STDOUT_FILENO) == -1)
                {
                    perror("dup2");
                    clean_pipe_fd(&fd, nbr_pipes);
                    exit(EXIT_FAILURE);
                }
            }

            // Nettoyage des descripteurs inutiles
            clean_pipe_fd(&fd, nbr_pipes);

            // Exécution de la commande
            if (execve(command->cmd[0], command->cmd, envp) == -1)
            {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        }
        else // Processus parent
        {
            // Fermeture des descripteurs inutilisés dans le parent
            if (command->previous && !ft_strcmp(command->previous->cmd[0], "|"))
                close(fd[i - 1][0]);
            if (command->next && !ft_strcmp(command->next->cmd[0], "|"))
                close(fd[i][1]);

            // Attendre le processus enfant pour cette commande
            int status;
            waitpid(pid, &status, 0);
            if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
            {
                fprintf(stderr, "Un processus s'est terminé avec une erreur : %d\n", WEXITSTATUS(status));
            }
        }

        // Passer à la commande suivante
        if (command->next && !ft_strcmp(command->next->cmd[0], "|"))
            i++;
        command = command->next;
    }

    // Nettoyage final
    clean_pipe_fd(&fd, nbr_pipes);
}

