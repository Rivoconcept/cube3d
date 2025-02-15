/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_render_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/15 09:48:36 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float	get_distance(t_params *params, float angle)
{
	float	rx;
	float	ry;
	float	dir_x;
	float	dir_y;
	float	step;
	float	distance;

	step = 1.0;
	distance = 0.0;
	rx = params->player->x;
	ry = params->player->y;
	modulo_angle(&angle);
	dir_x = sin(angle) * step;
	dir_y = -cos(angle) * step;
	while (put_map_value(params, (int)rx, (int)ry) != '1')
	{
		rx += dir_x;
		ry += dir_y;
		distance += step;
	}
	return (distance);
}


void	ray_trace(t_params *params, float angle, float distance)
{
	float	i;
	int		px;
	int		py;
	float	ray_x;
	float	ray_y;
	float	dir_x;
	float	dir_y;

	i = 0.0;
    px = 0;
    py = 0;
	modulo_angle(&angle);
	dir_x = sin(angle);
	dir_y = -cos(angle);
	ray_x = params->player->x;
	ray_y = params->player->y;
	while (i < distance)
	{
		px = (int)(ray_x + dir_x * i);
		py = (int)(ray_y + dir_y * i);
		my_mlx_pixel_put(px, py, 0x00FF00, params);
		i += 0.1;
	}
}

void trace_fov(t_params *params)
{
    float angle;
    float step;
    float distance;
    int i;

    step = FOV / SCREEN_WIDTH;
    i = 0;
    while (i < SCREEN_WIDTH)
    {
        angle = params->delta - (FOV / 2) + (step * i);
        modulo_angle(&angle);
        distance = get_distance(params, angle);
        ray_trace(params, angle, distance);
        i++;
    }
}



