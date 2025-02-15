/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_manage_list_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:49:17 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/15 12:55:36 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_ranks_line(t_line **head)
{
	int		index;
	t_line	*current;

	index = 0;
	current = *head;
	while (current != NULL)
	{
		current->cell_value.index = index;
		index++;
		current = current->next;
	}
}

void	put_ranks_map(t_map **head)
{
	int		index;
	t_map	*current;

	index = 0;
	current = *head;
	while (current != NULL)
	{
		current->line_value.index = index;
		index++;
		current = current->next;
	}
}


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

t_params	*create_list_param(void)
{
	t_params	*new_params;

	new_params = (t_params *)malloc(sizeof(t_params));
	if (new_params == NULL)
		return (NULL);
	new_params->mlx_connexion = NULL;
	new_params->win_open = NULL;
	new_params->image = init_list_img();
	new_params->wall = NULL;
	new_params->map = NULL;
	new_params->pos = create_list_position();
	new_params->f_color = init_ground_color();
	new_params->c_color = init_ceiling_color();
	new_params->rect = init_rectangle();
	new_params->player = init_list_player();
	new_params->delta = 0;
	new_params->no = NULL;
	new_params->so = NULL;
	new_params->we = NULL;
	new_params->ea = NULL;
	new_params->f = NULL;
	new_params->c = NULL;
	new_params->x = 0;
	new_params->y = 0;
	new_params->win_width = 0;
	new_params->win_height = 0;
	new_params->next = NULL;
	return (new_params);
}
