/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_manage_list_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:49:17 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/28 18:49:18 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_list_position(t_position *head)
{
	t_position	*temp;
	t_position	*current;

	if (!head)
		return ;
	temp = NULL;
	current = head;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	head = NULL;
}

void	free_list_map(t_map *head_map)
{
	t_map	*current_map;
	t_map	*next_map;
	t_line	*current_line;
	t_line	*next_line;

	current_map = head_map;
	while (current_map != NULL)
	{
		current_line = current_map->line_value.line;
		while (current_line != NULL)
		{
			next_line = current_line->next;
			free(current_line);
			current_line = next_line;
		}
		next_map = current_map->next;
		free(current_map);
		current_map = next_map;
	}
}
