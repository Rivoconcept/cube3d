/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_wall_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:08:07 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/23 13:34:48 by rhanitra         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/cub3d.h"

int is_wall_left(t_position *pos, t_map *map)
{
	if (pos->value.x != 0)
	{
		pos->value.x -= 1;
		if (find_value(map, pos) == 49)
		{
			pos->value.x += 1;
			return (1);
		}
		pos->value.x += 1;
	}
	return (0);
}

int is_wall_right(t_position *pos, t_map *map)
{
	pos->value.x += 1;
	if (find_value(map, pos) == '\n')
	{
		pos->value.x -= 1;
		return (0);
	}
	if (find_value(map, pos) == 49)
	{
		pos->value.x -= 1;
		return (1);
	}
	pos->value.x -= 1;
	return (0);
}

int is_wall_up(t_position *pos, t_map *map)
{
	if (pos->value.y != 0)
	{
		pos->value.y -= 1;
		if (find_value(map, pos) == 49)
		{
			pos->value.y += 1;
			return (1);
		}
		pos->value.y += 1;
	}
	return (0);
}

int is_wall_down(t_position *pos, t_map *map)
{
	if (pos->value.y < count_element_list_mapline(map))
	{
		pos->value.y += 1;
		if (find_value(map, pos) == 49)
		{
			pos->value.y -= 1;
			return (1);
		}
		pos->value.y -= 1;
	}
	return (0);
}