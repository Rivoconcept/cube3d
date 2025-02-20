/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_render_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/20 15:46:07 by rhanitra         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/cub3d.h"


char get_type_texture(t_params *params, int x, int y)
{
    if (!params)
        return (' ');
    printf("Checking wall type at %d, %d\n", x, y);
    if (putval(params, x, y) == '1')
    {
        if (putval(params, x - 1, y) != '1')
            return ('W');
        if (putval(params, x + 1, y) != '1')
            return ('E');
        if (putval(params, x, y - 1) != '1')
            return ('N');
        if (putval(params, x, y + 1) != '1')
            return ('S');
    }
    return (' ');
}

t_img	*get_wall_texture(t_params *params, char wall_dir)
{
    if (wall_dir == 'N')
        return (params->NO);
    if (wall_dir == 'S')
        return (params->SO);
    if (wall_dir == 'E')
        return (params->EA);
    if (wall_dir == 'W')
        return (params->WE);
    return (NULL);
}


int get_wall_height(float distance)
{
    float dpp;
    int wall_height;

    dpp = (SCREEN_WIDTH / 2.0) / tan(FOV / 2.0);
    if (distance <= 0)
        return (SCREEN_HEIGHT);
    if (distance < 0.1)
        distance = 0.1;
    wall_height = (int)((SLICE_SIZE * dpp) / (distance + 0.01));
    if (wall_height > SCREEN_HEIGHT)
        wall_height = SCREEN_HEIGHT;
    return (wall_height);
}


float	get_distance(t_params *params, float angle, char *wall_dir)
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
    *wall_dir = get_type_texture(params, rx, ry);
    printf("Raycasting: angle=%f, distance=%f, wall_dir=%c\n", angle, distance, *wall_dir); // Debug
	return (distance);
}

void draw_textured_wall(t_params *params, int x, int y_start, int y_end, float distance, char wall_dir)
{
    t_img   *texture;
    int     y;
    int     texture_x;
    int     texture_y;
    int     color;
    float   scale_factor;

    texture = get_wall_texture(params, wall_dir);
    if (!texture)
    {
        printf("No texture found for wall_dir=%c\n", wall_dir);
        return ;
    }
    scale_factor = 1.0 / (distance + 0.01);
    texture_x = (x % texture->width);
    y = y_start;
    while (y < y_end)
    {
        texture_y = (int)((y - y_start) * texture->height * scale_factor / (y_end - y_start));
        color = get_texture_pixel(texture, texture_x, texture_y);
        my_mlx_pixel_put(x, y, color, params);
        y++;
    }
}


void draw_wall(t_params *params)
{
	int x;
	float angle;
	float distance;
	int wall_height;
	char wall_dir;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		angle = (params->delta - (FOV / 2.0)) + ((float)x / SCREEN_WIDTH) * FOV;
		distance = get_distance(params, angle, &wall_dir);
		wall_height = get_wall_height(distance);
		draw_textured_wall(params, x, (SCREEN_HEIGHT / 2) - (wall_height / 2), 
                               (SCREEN_HEIGHT / 2) + (wall_height / 2), distance, wall_dir);
		x++;
	}
}











