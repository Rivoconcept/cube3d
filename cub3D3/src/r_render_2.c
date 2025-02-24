/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_render_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/24 21:17:22 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*char get_type_texture(t_params *params, int x, int y)
{
    if (putval(params, x - 1, y) == '1')
        return ('W');
    if (putval(params, x + 1, y) == '1')
        return ('E');
    if (putval(params, x, y - 1) == '1')
        return ('N');
    if (putval(params, x, y + 1) == '1')
        return ('S');
    return (params->player->init);
}*/

char get_type_texture(t_params *params, int x, int y)
{
    t_moov moov;

    moov.left = putval(params, x - 1, y);
    moov.right = putval(params, x + 1, y);
    moov.up = putval(params, x, y - 1);
    moov.down = putval(params, x, y + 1);
    //if (y % 4)
    // if (x % SLICE_SIZE == 0 && y % SLICE_SIZE == 0 && moov.up == '1')
    // {
    //     return ('N');
    // }
    // if (x % SLICE_SIZE == 63 && y % SLICE_SIZE == 63 && moov.up == '1')
    // {
    //     return ('N');
    // }
    if (moov.left == '1')
        return ('W');
    if (moov.right == '1')
        return ('E');
    if (moov.up == '1')
        return ('N');
    if (moov.down == '1')
        return ('S');
    return (params->player->init);
}


t_img	*get_wall_texture(t_params *params, char wall_dir)
{
    if (wall_dir == 'N')
    {
        params->NO->wall_path = wall_dir;
        return (params->NO);
    }
    if (wall_dir == 'S')
    {
        params->SO->wall_path = wall_dir;
        return (params->SO);
    }
    if (wall_dir == 'E')
    {
        params->EA->wall_path = wall_dir;
        return (params->EA);
    }
    if (wall_dir == 'W')
    {
        params->WE->wall_path = wall_dir;
        return (params->WE);
    }
    return (NULL);
}


int get_wall_height(float distance)
{
    float dpp;
    int wall_height;

    dpp = (SCREEN_WIDTH / 2.0) / tan(FOV / 2.0);
    wall_height = (int)((SLICE_SIZE * dpp) / (distance));
    return (wall_height);
}

void	get_distance(t_params *params, t_img **wall, float angle)
{
	float	rx;
	float	ry;
	float	dir_x;
	float	dir_y;
	float	distance;
    char    wall_path;

	distance = 0.0;
	rx = params->player->x;
	ry = params->player->y;
	modulo_angle(&angle);
	dir_x = sin(angle) * STEP_CAST;
	dir_y = -cos(angle) * STEP_CAST;
	while (put_map_value(params, (int)rx, (int)ry) != '1')
	{
		rx += dir_x;
		ry += dir_y;
		distance += STEP_CAST;
	}
    wall_path = get_type_texture(params, rx, ry);
    (*wall) =  get_wall_texture(params, wall_path);
    (*wall)->wx = rx;
    (*wall)->wy = ry;
    (*wall)->distance = distance;
}

int get_texture_pixel(t_img *texture, int x, int y)
{
    char    *dst;

    if (!texture || x < 0 || y < 0 || x >= texture->width || y >= texture->height)
        return (0x000000);
    dst = texture->data + (y * texture->line_len + x * (texture->bpp / 8));
    return (*(unsigned int *)dst);
}

void draw_wall_slice(t_params *params, t_img *wall, int x)
{
    int     y;
    int     wall_height;
    float     tex_x;
    float     tex_y;
    int     start;
    int     end;
    float   val;
    int     color;

    wall_height = get_wall_height(wall->distance);
    start = (SCREEN_HEIGHT / 2) - (wall_height / 2);
    end = start + wall_height;      
    y = start;
    if (wall->wall_path == 'N' || wall->wall_path == 'S')
        tex_x = ((int)wall->wx % SLICE_SIZE);
    else if (wall->wall_path == 'E' || wall->wall_path == 'W')
        tex_x = ((int)wall->wy % SLICE_SIZE);
    val = tex_x / SLICE_SIZE;
    while (y < end)
    {
        tex_y = ((y - start) * wall->height) / wall_height;
        color = get_texture_pixel(wall, val * wall->width, tex_y);
        my_mlx_pixel_put(x, y, color, params);
        y++;
    }
}

void render_scene(t_params *params)
{
    int     x;
    float   step;
    float   angle;
    t_img   *wall;

    x = 0;
    step = FOV / SCREEN_WIDTH;
    wall = params->texture;
    angle = params->delta - (FOV / 2);
    while (x < SCREEN_WIDTH)
    {
        get_distance(params, &wall, angle);
        wall->distance *= cos(angle - params->delta);
        draw_wall_slice(params, wall, x);
        angle += step; 
        x++;
    }
}
