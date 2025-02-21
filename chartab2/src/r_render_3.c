/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_render_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/21 17:58:58 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char get_type_texture(t_params *params, int x, int y)
{
	if (putval(params, x - 1, y) == '1')
		return ('N');
    if (putval(params, x + 1, y) == '1')
		return ('S');
    if (putval(params, x, y - 1) == '1')
		return ('E');
   	if (putval(params, x, y + 1) == '1')
		return ('W');
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
	return (distance);
}

void draw_wall_slice(t_params *params, int x, float distance, char wall_dir)
{
    t_img  *texture;
    int     y;
    int     wall_height;
    int     tex_x;
    int     tex_y;
    int     color;

    wall_height = get_wall_height(distance);
    texture = get_wall_texture(params, wall_dir);
    if (!texture)
        return ;
    y = 0;
    tex_x = (x % texture->width);
    while (y < wall_height)
    {
        tex_y = (y * texture->height) / wall_height;
        color = get_texture_pixel(texture, tex_x, tex_y);
        my_mlx_pixel_put(x, (SCREEN_HEIGHT / 2 - wall_height / 2) + y, color, params);
        y++;
    }
}

void render_scene(t_params *params)
{
    int     x;
    float   angle;
    float   distance;
    char    wall_dir;

    x = 0;
    angle = params->delta - (FOV / 2);
    while (x < SCREEN_WIDTH)
    {
        distance = get_distance(params, angle, &wall_dir);
        distance *= cos(angle - params->delta);
        draw_wall_slice(params, x, distance, wall_dir);
        angle += FOV / SCREEN_WIDTH; 
        x++;
    }
}



















