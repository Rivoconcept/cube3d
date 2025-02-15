/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_render_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/15 15:08:41 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*float	get_distance(t_params *params, float angle)
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
}*/

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
	while (distance < SCREEN_WIDTH && put_map_value(params, (int)rx, (int)ry) != '1')
	{
		rx += dir_x;
		ry += dir_y;
		distance += step;
	}
	return (distance);
}

#include <math.h>

/*float get_distance(t_params *params, float angle, char *wall_dir, float *wall_x)
{
    float delta_x = cos(angle);
    float delta_y = sin(angle);
    float x = params->player->x;
    float y = params->player->y;

    float step_size = 0.01; // Petit pas pour avancer le rayon
    float distance = 0;

    while (distance < SCREEN_WIDTH)
    {
        x += delta_x * step_size;
        y += delta_y * step_size;
        distance += step_size;

        if (put_map_value(params, x, y) == '1') // Fonction à créer si elle n'existe pas
        {
            if (fabs(delta_x) > fabs(delta_y)) // Vérifie si on touche un mur vertical ou horizontal
            {
                if (delta_x < 0)
                    *wall_dir = 'W';
                else
                    *wall_dir = 'E';
                *wall_x = fmod(y, 64) / 64.0; // Normalisation sur la texture
            }
            else
            {
                if (delta_y < 0)
                    *wall_dir = 'N';
                else
                    *wall_dir = 'S';
                *wall_x = fmod(x, 64) / 64.0;
            }
            return distance;
        }
    }

    return SCREEN_WIDTH;
}*/



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

/*void trace_fov(t_params *params)
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
}*/



