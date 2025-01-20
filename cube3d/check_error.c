/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:08:39 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/20 17:58:33 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_init_road(t_map *map)
{
	int			j;
	t_position	*pos;

	j = 0;
	pos = put_position_p(map, 'P');
	pos->value.y = pos->value.y - 1;
	if (find_value(map, pos) == 49 || find_value(map, pos) == 'E')
		j++;
	pos->value.y = pos->value.y + 1;
	pos->value.y = pos->value.y + 1;
	if (find_value(map, pos) == 49 || find_value(map, pos) == 'E')
		j++;
	pos->value.y = pos->value.y - 1;
	pos->value.x = pos->value.x - 1;
	if (find_value(map, pos) == 49 || find_value(map, pos) == 'E')
		j++;
	pos->value.x = pos->value.x + 1;
	pos->value.x = pos->value.x + 1;
	if (find_value(map, pos) == 49 || find_value(map, pos) == 'E')
		j++;
	free_list_position(pos);
	if (j == 4)
		return (1);
	return (0);
}

int	check_after_flood_fill(t_map *map)
{
	char		data;
	t_map		*current_map;
	t_line		*current_line;

	data = '0';
	current_map = map;
	while (current_map != NULL)
	{
		current_line = current_map->line_value.line;
		while (current_line != NULL)
		{
			data = current_line->cell_value.value;
			if (data == 'E' || data == 'C')
				return (1);
			current_line = current_line->next;
		}
		current_map = current_map->next;
	}
	return (0);
}

int	check_flood_fill(t_map *map)
{
	int	i;
	int	size;

	i = 0;
	size = count_element_list_mapline(map);
	while (i < size)
	{
		map = put_position_f(map, 'P');
		i++;
	}
	if (check_after_flood_fill(map))
		return (1);
	return (0);
}
