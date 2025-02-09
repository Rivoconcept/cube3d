/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_search.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:49:34 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/09 12:55:53 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	find_value(t_map *map, t_position *pos)
{
	t_map		*current_map;
	t_line		*current_line;

	current_map = map;
	while (current_map != NULL)
	{
		if (current_map->line_value.index == pos->value.y)
		{
			current_line = current_map->line_value.line;
			while (current_line != NULL)
			{
				if (current_line->cell_value.index == pos->value.x)
					return (current_line->cell_value.value);
				current_line = current_line->next;
			}
		}
		current_map = current_map->next;
	}
	return ('\0');
}

char	putval(t_params *params, int x, int y)
{
	params->pos->value.x = get_pos_x(x);
	params->pos->value.y = get_pos_y(y);
	return (find_value(params->map, params->pos));
}

char put_map_value(t_params *params, int x, int y)
{
    char c;

    c = putval(params, x, y);
	if (c == '1')
        return c;
    if (putval(params, x + 1, y) == '1' || putval(params, x - 1, y) == '1' ||
        putval(params, x, y + 1) == '1' || putval(params, x, y - 1) == '1')
        return '1';
    if ((putval(params, x + 1, y) == '1' && putval(params, x, y + 1) == '1') ||
        (putval(params, x - 1, y) == '1' && putval(params, x, y - 1) == '1') ||
        (putval(params, x + 1, y) == '1' && putval(params, x, y - 1) == '1') ||
        (putval(params, x - 1, y) == '1' && putval(params, x, y + 1) == '1'))
        return '1';
    return c;
}
