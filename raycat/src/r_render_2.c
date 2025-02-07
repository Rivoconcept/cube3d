/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_render_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/07 18:39:50 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double get_distance(t_params *params, double angle)
{
    double rx;
    double ry;
    double dir_x;
    double dir_y;
    double step;
    double distance;

    step = 0.1;
    distance = 0.0;
    rx = params->player->x;
    ry = params->player->y;
    dir_x = sin(angle) * step;
    dir_y = -cos(angle) * step;
    while (put_map_value(params, (int)rx, (int)ry) != '1')
    {
        rx += dir_x;
        ry += dir_y;
        distance += step;
    }
    return distance;
}

void ray_trace(t_params *params, double angle)
{
    double i;
    double ray_x;
    double ray_y;
    double dir_x;
    double dir_y;
    double distance;

    i = 0.0;
    dir_x = sin(angle);
    dir_y = -cos(angle);
    ray_x = params->player->x;
    ray_y = params->player->y;
    distance = get_distance(params, angle);
    while (i < distance)
    {
        int px = (int)(ray_x + dir_x * i);
        int py = (int)(ray_y + dir_y * i);
        my_mlx_pixel_put(px, py, 0x00FF00, params);
        i += 0.1;
    }
}

void trace_fov(t_params *params)
{
    double angle;
    double start_angle;
    double end_angle;
    double step; 

    step = (PI / 180) * 1.0;     
    start_angle = params->delta - (PI / 4);
    end_angle = params->delta + (PI / 4);
    angle = start_angle;
    while (angle <= end_angle)
    {
        ray_trace(params, angle);
        angle += step;
    }
}



