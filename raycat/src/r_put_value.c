/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_put_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:00:40 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/07 15:35:35 by rhanitra         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

double cast_ray(t_params *params)
{
    double ray_x = params->player->x;
    double ray_y = params->player->y;
    double ray_dir_x = sin(params->delta);
    double ray_dir_y = cos(params->delta);
    double step_size = 1.0;
    double distance = 0.0;

    while (put_map_value(params, (int)ray_x, (int)ray_y) != '1')
    {
        ray_x += ray_dir_x * step_size;
        ray_y += ray_dir_y * step_size;
        distance += step_size;
    }
    
    return distance;
}


