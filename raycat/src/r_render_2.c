/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_render_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/07 19:10:35 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void ray_trace(t_params *params)
{
    int i;
    int px;
    int py;
    double distance;
    double ray_x;
    double ray_y;
    double dir_x;
    double dir_y;

    i = 0;
    distance = get_distance(params);
    ray_x = params->player->x;
    ray_y = params->player->y;
    dir_x = sin(params->delta);
    dir_y = -cos(params->delta);
    while (i < distance)
    {
        px = (int)(ray_x + dir_x * i);
        py = (int)(ray_y + dir_y * i);
        my_mlx_pixel_put(px, py, 0x00FF00, params);
        i++;
    }
}

/*void ray_trace(t_params *params)
{
    double start_angle = params->delta - (PI / 8); // -22.5° en radians
    double end_angle = params->delta + (PI / 8);   // +22.5° en radians
    double step_angle = (PI / 180) * 1.0;          // 1° d'incrément
    double ray_x, ray_y, dir_x, dir_y, distance;
    int px, py;

    for (double delta = start_angle; delta <= end_angle; delta += step_angle)
    {
        distance = get_distance(params);
        ray_x = params->player->x;
        ray_y = params->player->y;
        dir_x = sin(delta);
        dir_y = -cos(delta);

        for (int i = 0; i < distance; i++)
        {
            px = (int)(ray_x + dir_x * i);
            py = (int)(ray_y + dir_y * i);
            my_mlx_pixel_put(px, py, 0x00FF00, params);
        }
    }
}*/

/*void ray_trace(t_params *params)
{
    int i;
    int px;
    int py;
    double distance;
    double ray_x;
    double ray_y;
    double dir_x;
    double dir_y;
    double alfa = params->delta;

    double start_angle = params->delta - (PI / 6);
    double end_angle = params->delta + (PI / 6);
    double step_angle = (PI / 180) * 1.0;  

    i = 0;
    distance = get_distance(params);
    ray_x = params->player->x;
    ray_y = params->player->y;
    while(start_angle <= end_angle)
    {
        distance = get_distance(params);
        dir_x = sin(alfa);
        dir_y = -cos(alfa);
        while (i < distance)
        {
            px = (int)(ray_x + dir_x * i);
            py = (int)(ray_y + dir_y * i);
            my_mlx_pixel_put(px, py, 0x00FF00, params);
            i++;
        }
        alfa += step_angle;
    }
}*/



