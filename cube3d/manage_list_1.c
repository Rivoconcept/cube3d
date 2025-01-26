/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:37:35 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/26 15:34:53 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_line	*create_list_line(char data)
{
	t_line	*new_element;

	new_element = (t_line *)malloc(sizeof(t_line));
	if (new_element == NULL)
		exit(EXIT_FAILURE);
	new_element->cell_value.value = data;
	new_element->cell_value.index = 0;
	new_element->next = NULL;
	return (new_element);
}

t_map	*create_list_map(t_line *line)
{
	t_map	*new_element;

	if (line == NULL)
	{
		perror_msg("The list line is null", NULL);
		exit(EXIT_FAILURE);
	}
	new_element = (t_map *)malloc(sizeof(t_map));
	if (new_element == NULL)
		exit(EXIT_FAILURE);
	new_element->line_value.line = line;
	new_element->line_value.index = 0;
	new_element->next = NULL;
	return (new_element);
}

t_position	*create_list_position(void)
{
	t_position	*new_pos;

	new_pos = (t_position *)malloc(sizeof(t_position));
	if (new_pos == NULL)
		return (NULL);
	new_pos->value.x = 0;
	new_pos->value.y = 0;
	new_pos->next = NULL;
	return (new_pos);
}

void	create_img(t_params *new_params)
{
	new_params->img.wall_up_left = NULL;
	new_params->img.wall_up_center = NULL;
	new_params->img.wall_up_right = NULL;
	new_params->img.wall_left = NULL;
	new_params->img.wall_right = NULL;
	new_params->img.wall_down_left = NULL;
	new_params->img.wall_down_center = NULL;
	new_params->img.wall_down_right = NULL;
	new_params->img.flower_one = NULL;
	new_params->img.flower_two = NULL;
	new_params->img.player = NULL;
	new_params->img.exit_close = NULL;
	new_params->img.exit_open = NULL;
	new_params->img.ground = NULL;
	new_params->img.you_win = NULL;
}

t_params	*create_list_param(void)
{
	t_params	*new_params;

	new_params = (t_params *)malloc(sizeof(t_params));
	if (new_params == NULL)
		return (NULL);
	new_params->mlx_connexion = NULL;
	new_params->win_open = NULL;
	new_params->pos = NULL;
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
	new_params->move = 1;
	create_img(new_params);
	new_params->next = NULL;
	return (new_params);
}
