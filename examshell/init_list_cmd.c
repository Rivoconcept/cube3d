/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:16:23 by rhanitra          #+#    #+#             */
/*   Updated: 2024/12/07 18:12:58 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "examshell.h"

t_cmd *create_new_list_cmd(char **argv)
{
    t_cmd *new_cmd;

    new_cmd = malloc(sizeof(t_cmd));
    if (!new_cmd)
        return (perror("malloc"), NULL);
    new_cmd->cmd = argv;
    new_cmd->next = NULL;
    new_cmd->previous = NULL;
    return (new_cmd);
}

t_cmd *add_command(t_cmd *command, char **argv)
{
    t_cmd   *new_cmd;
    t_cmd   *current;

    new_cmd = create_new_list_cmd(argv);
    if (!new_cmd)
        return (free_list_cmd(command), NULL);
    if (!command)
        return (new_cmd);
    current = command;
    while (current->next)
        current = current->next;
    current->next = new_cmd;
    new_cmd->previous = current;
    return (command);
}
