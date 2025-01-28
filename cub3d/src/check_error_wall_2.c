/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_wall_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:08:07 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/28 16:25:10 by rhanitra         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/cub3d.h"

void	go_up(t_map *map, t_position *pos)
{
	while (1)
	{
		if (find_value(map, pos) == 49)
			change_value(map, pos, 'P');
		if (is_wall_down(pos, map))
			pos->value.y -= 1;
		else
			break ; 
	}
	/*if (!is_wall_left(pos, map))
		pos->value.x -= 1;
	else
		pos->value.x += 1;*/
}

void	go_down(t_map *map, t_position *pos)
{
	while (1)
	{
		if (find_value(map, pos) == 49)
			change_value(map, pos, 'P');
		if (is_wall_down(pos, map))
			pos->value.y += 1;
		else
			break ; 
	}
	/*if (!is_wall_right(pos, map))
		pos->value.x -= 1;
	else
		pos->value.x += 1;*/
}

void	go_left(t_map *map, t_position *pos)
{
	while (1)
	{
		if (find_value(map, pos) == 49)
			change_value(map, pos, 'P');
		if (is_wall_down(pos, map))
			break;
		if (is_wall_left(pos, map))
			pos->value.x -= 1;
		else
			break ; 
	}
	/*if (!is_wall_down(pos, map))
		pos->value.y -= 1;
	else
		pos->value.y += 1;*/
}

void	go_right(t_map *map, t_position *pos)
{
	while (1)
	{
		if (find_value(map, pos) == 49)
			change_value(map, pos, 'P');
		if (is_wall_right(pos, map))
			pos->value.x += 1;
		else
			break ; 
	}
	/*if (!is_wall_down(pos, map))
		pos->value.y -= 1;
	else
		pos->value.y += 1;*/
}

/*int check_place(t_map *map, t_position *pos)
{

}*/


/*t_map	*check_wall(t_map *map, char c)
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
}*/

int get_initial_pos(t_line *line)
{
	if (line->cell_value.index == 0 && line->cell_value.value != 49 \
		&& line->cell_value.value != 32)
		return (-1);
	if (line->cell_value.index == 0 && line->cell_value.value == 49)
		return (0);
	if (line->cell_value.index == 0 && line->cell_value.value == 32)
	{
		while (line != NULL && line->cell_value.value == 32)
			line = line->next;
		if (line->cell_value.value != 49)
			return (-1);
		else if (line->cell_value.value == 49)
			return (line->cell_value.index);
	}
	return (-1);
}

/*int is_wall(t_position *pos, t_map *map)
{

}*/

/*void	check_wall(t_map *map)
{
	t_line		*line;
	t_position	*pos;

	pos = create_list_position();
	line = map->line_value.line;
	pos->value.x = get_initial_pos(line);
	if (pos->value.x < 0)
		ft_exit_faillure("The wall is not closed", NULL);
	pos->value.y = 0;
	int i = 0;
	while (i <= 10)
	{
		go_right(map, pos);
		go_down(map, pos);
		go_left(map, pos);
		go_up(map, pos);
		// if (pos->value.x == 8 && pos->value.y == 0)
		// 	break ;
		i++;
	}
	while (1)
	{
		go_up(map, pos, line, map);
		go_down(map, pos, line, map);
		go_left(map, pos, line, map);
		go_right(map, pos, line, map);
		if (pos->value.x == 0 && pos->value.y == 0)
			break ;
	}
	free(pos);
}*/

int is_not_wall(t_map *map, t_position *pos)
{
	if (pos->value.y == 0 || pos->value.x == 0 \
		|| pos->value.y == count_element_list_mapline(map) - 1)
	{
		return (1);
	}
	return (0);
}

int	is_data_game(char c)
{
	return (c == 48 || c == 'N' || c == 'W' || c == 'S' || c == 'E');
}

int	check_wall(t_params *params)
{
	t_map		*current_map;
	t_line		*current_line;
	t_position	*pos;

	current_map = params->map;
	pos = create_list_position();
	while (current_map)
	{
		current_line = current_map->line_value.line;
		pos->value.y = current_map->line_value.index;
		while (current_line)
		{
			pos->value.x = current_line->cell_value.index;
			if (is_data_game(current_line->cell_value.value))
			{
				if (is_not_wall(params->map, pos))
					return (free(pos), 1);
			}
			current_line = current_line->next;
		}
		current_map = current_map->next;
	}
	return (free(pos), 0);
}

