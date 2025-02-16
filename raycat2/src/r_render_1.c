/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_render_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/16 13:32:02 by rhanitra         ###   ########.fr       */
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
	while (distance < SCREEN_WIDTH && put_map_value(params, (int)rx, (int)ry) != '1')
	{
		rx += dir_x;
		ry += dir_y;
		distance += step;
	}
	return (distance);
}*/


float get_distance(t_params *params, float angle)
{
    float rx, ry;       // Position du rayon
    float dx, dy;       // Direction du rayon
   // float step_x, step_y; // Incréments pour atteindre la prochaine case
    int map_x, map_y;   // Coordonnées de la case actuelle
    int step_dir_x, step_dir_y; // Direction du pas (+1 ou -1)
    float side_dist_x, side_dist_y; // Distance avant la prochaine case
    float delta_dist_x, delta_dist_y; // Distance entre deux intersections

    modulo_angle(&angle);
    
    // Position initiale du rayon (position du joueur)
    rx = params->player->x;
    ry = params->player->y;

    // Direction du rayon
    dx = cos(angle);
    dy = sin(angle);

    // Case actuelle
    map_x = (int)rx;
    map_y = (int)ry;

    // Calcul des pas et des distances delta
    delta_dist_x = fabs(1 / dx);
    delta_dist_y = fabs(1 / dy);

    // Détermination des directions et des distances initiales
    if (dx < 0) {
        step_dir_x = -1;
        side_dist_x = (rx - map_x) * delta_dist_x;
    } else {
        step_dir_x = 1;
        side_dist_x = (map_x + 1.0 - rx) * delta_dist_x;
    }
    if (dy < 0) {
        step_dir_y = -1;
        side_dist_y = (ry - map_y) * delta_dist_y;
    } else {
        step_dir_y = 1;
        side_dist_y = (map_y + 1.0 - ry) * delta_dist_y;
    }

    // Lancer le DDA
    while (1) {
        // Choisir la direction avec la plus petite distance
        if (side_dist_x < side_dist_y) {
            side_dist_x += delta_dist_x;
            map_x += step_dir_x;
        } else {
            side_dist_y += delta_dist_y;
            map_y += step_dir_y;
        }

        // Vérifier si on a touché un mur
        if (put_map_value(params, map_x, map_y) == '1')
            break;
    }

    // Retourner la distance au mur
    return sqrt((map_x - rx) * (map_x - rx) + (map_y - ry) * (map_y - ry));
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



