/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flood_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:08:07 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/23 16:52:47 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	go_up(t_map *map, t_position *pos, \
		t_line *current_line, t_map *current_map)
{
	int	u;

	u = 1;
	pos->value.x = current_line->cell_value.index;
	pos->value.y = current_map->line_value.index;
	while (1)
	{
		pos->value.y = current_map->line_value.index - u;
		if (find_value(map, pos) != 49 && pos->value.y != 0 \
			&& find_value(map, pos) != 'P')
			change_value(map, pos, 'P');
		else
			break ;
		u++;
	}
}

void	go_down(t_map *map, t_position *pos, \
		t_line *current_line, t_map *current_map)
{
	int	u;

	u = 1;
	pos->value.x = current_line->cell_value.index;
	pos->value.y = current_map->line_value.index;
	while (1)
	{
		pos->value.y = current_map->line_value.index + u;
		if (pos->value.y != count_element_list_mapline(map) \
			&& find_value(map, pos) != 'P' && find_value(map, pos) != 49)
			change_value(map, pos, 'P');
		else
			break ;
		u++;
	}
}

void	go_left(t_map *map, t_position *pos, \
		t_line *current_line, t_map *current_map)
{
	int	u;

	u = 1;
	pos->value.x = current_line->cell_value.index;
	pos->value.y = current_map->line_value.index;
	while (1)
	{
		pos->value.x = current_line->cell_value.index - u;
		if (find_value(map, pos) != 49 && pos->value.x != 0 \
			&& find_value(map, pos) != 'P')
			change_value(map, pos, 'P');
		else
			break ;
		u++;
	}
}

void	go_right(t_map *map, t_position *pos, \
		t_line *current_line, t_map *current_map)
{
	int	u;

	u = 1;
	pos->value.x = current_line->cell_value.index;
	pos->value.y = current_map->line_value.index;
	while (1)
	{
		pos->value.x = current_line->cell_value.index + u;
		if (find_value(map, pos) != 49 && pos->value.x != '\n' \
			&& find_value(map, pos) != 'P')
			change_value(map, pos, 'P');
		else
			break ;
		u++;
	}
}

t_map	*put_position_f(t_map *map, char c)
{
	t_map		*current_map;
	t_line		*current_line;
	t_position	*pos;

	current_map = map;
	pos = create_list_position();
	while (current_map != NULL)
	{
		current_line = current_map->line_value.line;
		while (current_line != NULL)
		{
			if (current_line->cell_value.value == c)
			{
				go_up(map, pos, current_line, current_map);
				go_down(map, pos, current_line, current_map);
				go_left(map, pos, current_line, current_map);
				go_right(map, pos, current_line, current_map);
			}
			current_line = current_line->next;
		}
		current_map = current_map->next;
	}
	return (free(pos), map);
}
