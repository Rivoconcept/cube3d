/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_put_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:00:40 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/08 17:55:29 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
