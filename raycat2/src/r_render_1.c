/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_render_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/15 18:55:51 by rhanitra         ###   ########.fr       */
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

/*float get_distance(t_params *params, float angle, char *wall_dir, float *wall_x)
{
    float x = params->player->x;
    float y = params->player->y;
    float delta_x = cos(angle);
    float delta_y = sin(angle);
    int map_x = (int)(x / 64);
    int map_y = (int)(y / 64);

    float side_dist_x, side_dist_y;
    float delta_dist_x = fabs(1 / delta_x);
    float delta_dist_y = fabs(1 / delta_y);
    int step_x, step_y;
    int hit = 0;
    int side;

    // Déterminer la direction du pas
    if (delta_x < 0)
    {
        step_x = -1;
        side_dist_x = (x - map_x * 64) * delta_dist_x;
    }
    else
    {
        step_x = 1;
        side_dist_x = ((map_x + 1) * 64 - x) * delta_dist_x;
    }

    if (delta_y < 0)
    {
        step_y = -1;
        side_dist_y = (y - map_y * 64) * delta_dist_y;
    }
    else
    {
        step_y = 1;
        side_dist_y = ((map_y + 1) * 64 - y) * delta_dist_y;
    }

    // Lancer le rayon
    while (!hit)
    {
        if (side_dist_x < side_dist_y)
        {
            side_dist_x += delta_dist_x;
            map_x += step_x;
            side = 0; // Mur vertical
        }
        else
        {
            side_dist_y += delta_dist_y;
            map_y += step_y;
            side = 1; // Mur horizontal
        }

        if (put_map_value(params, map_x, map_y) == '1')
            hit = 1;
    }

    // Calculer la distance
    float distance;
    if (side == 0)
    {
        distance = (map_x - x + (1 - step_x) / 2) / delta_x;
        *wall_dir = (step_x == 1) ? 'E' : 'W';
        *wall_x = fmod(y, 64) / 64.0;
    }
    else
    {
        distance = (map_y - y + (1 - step_y) / 2) / delta_y;
        *wall_dir = (step_y == 1) ? 'S' : 'N';
        *wall_x = fmod(x, 64) / 64.0;
    }

    return distance;
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


/*float	get_distance(t_params *params, float angle)
{
	// float	rx;
	float	ry;
	float	dir_x;
	float	dir_y;
	float	distance;

	(void)angle;
	distance = 0.0;
	// rx = params->player->x;
	//modulo_angle(&angle);
	ry = params->player->y;
	dir_x = cos(angle);
	dir_y = -sin(angle);
 	// 
	distance = sqrt(pow((dir_x  * (((int)ry % SLICE_SIZE)) / dir_y), 2) + pow(((int)ry % SLICE_SIZE), 2));
	return (distance);
}*/

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
        distance = get_distance(params, angle);
        ray_trace(params, angle, distance);
        i++;
    }
}



