/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:08:07 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/29 16:23:39 by rhanitra         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/cub3d.h"

int check_x_side(t_map *map, t_position *pos)
{
	pos->value.x += 1;
	if (find_value(map, pos) == '\n' || find_value(map, pos) == 32)
	{
		pos->value.x -= 1;
		return (1);
	}
	pos->value.x -= 1;
	pos->value.x -= 1;
	if (find_value(map, pos) == 32)
	{
		pos->value.x -= 1;
		return (1);
	}
	pos->value.x += 1;
	return (0);
}

int check_y_side(t_map *map, t_position *pos)
{
	pos->value.y -= 1;
	if (find_value(map, pos) == 32)
	{
		pos->value.y -= 1;
		return (1);
	}
	pos->value.y += 1;
	pos->value.y += 1;
	if (find_value(map, pos) == 32)
	{
		pos->value.y += 1;
		return (1);
	}
	pos->value.y -= 1;
	return (0);
}

int	check_error_wall(char c, t_map *map, t_position *pos)
{
	if (c == 48 || c == 'N' || c == 'W' || c == 'S' || c == 'E')
	{
		if (pos->value.y == 0 || pos->value.x == 0 \
		|| pos->value.y == count_element_list_mapline(map) - 1)
		{
			perror_msg("The wall is not closed", NULL);
			return (1);
		}
		if (check_x_side(map, pos) || check_y_side(map, pos))
		{
			perror_msg("The wall is not closed", NULL);
			return (1);
		}
	}
	return (0);
}

int	check_map(t_params *params)
{
	t_map		*current_map;
	t_line		*line;
	t_position	*pos;

	current_map = params->map;
	pos = create_list_position();
	while (current_map)
	{
		line = current_map->line_value.line;
		pos->value.y = current_map->line_value.index;
		while (line)
		{
			pos->value.x = line->cell_value.index;
			if (check_error_wall(line->cell_value.value, params->map, pos))
				return (free(pos), 1);
			if (is_not_playable(line->cell_value.value, pos, params->map))
				return (free(pos), perror_msg("The game is not playable", NULL));
			line = line->next;
		}
		current_map = current_map->next;
	}
	return (free(pos), 0);
}

