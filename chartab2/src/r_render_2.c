/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_render_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/19 16:38:22 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

void draw_vertical_line(t_params *params, t_img *texture, int x)
{
    int y;
    int tex_x;
    int tex_y;
    int pixel_index;
    int color;
    
    color = 0x000000;
    y = texture->y_start;
    tex_x = (int)(texture->wall_x * texture->line_len) % texture->line_len;
    if (texture->y_end > texture->y_start)
    {
        while (y < texture->y_end)
        {
            tex_y = ((y - texture->y_start) * texture->line_len) / texture->wall_height;
            pixel_index = (tex_y * texture->line_len) + (tex_x * (texture->bpp / 8));
            color = *(int *)(texture->data + pixel_index);
            my_mlx_pixel_put(x, y, color, params);
            y++;
        }
    }
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


/*void put_wall_pexel(t_params *params, t_img *texture, int column, char wall_type)
{
    int top;
    int bottom;
    int wall_height;

    texture = get_wall_texture(params, wall_type);
    wall_height = get_wall_height(texture->distance);
    top = (SCREEN_HEIGHT / 2) - (wall_height / 2);
    bottom = top + wall_height;
    if (top < 0)
        top = 0;
    if (bottom > SCREEN_HEIGHT)
        bottom = SCREEN_HEIGHT;
    texture->y_start = top;
    texture->y_end = bottom;
    texture->wall_height = wall_height;
    draw_vertical_line(params, texture, column);
}*/

/*void draw_wall(t_params *params)
{
    float step;
    float angle;
    float distance;
    int col;
    char wall;
    t_img   *texture;

    wall = ' ';
    texture = NULL;
    step = FOV / SCREEN_WIDTH;
    angle = params->delta - (FOV / 2);
    col = 0;
    while (col < SCREEN_WIDTH)
    {
        distance = get_distance(params, texture, angle, &wall);
        distance *= cos(angle - params->delta);
        if (distance > 0.1)
            put_wall_pexel(params, texture, col, wall);
        angle += step;
        col++;
    }
}*/

char get_type_texture(t_params *params, int x, int y)
{
    if (!params)
        return (' ');
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

float get_distance(t_params *params, t_img *texture, float angle, char *wall)
{
    float rx, ry, dir_x, dir_y, step, distance;

    if (!params || !params->player || !wall || !texture)
        return SCREEN_WIDTH;

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

    if (put_map_value(params, (int)rx, (int)ry) == '1')
    {
        if (fabs(dir_x) > fabs(dir_y))
        {
            *wall = (dir_x < 0) ? 'W' : 'E';
            texture->wall_x = fmod(ry, 64) / 64.0;
        }
        else
        {
            *wall = (dir_y < 0) ? 'N' : 'S';
            texture->wall_x = fmod(rx, 64) / 64.0;
        }
        *wall = get_type_texture(params, (int)rx, (int)ry);
        texture->distance = distance;
        return distance;
    }
    return SCREEN_WIDTH;
}

void put_wall_pexel(t_params *params, t_img *texture, int column, char wall_type)
{
    int top, bottom, wall_height;

    if (!params || !texture)
        return;

    texture = get_wall_texture(params, wall_type);
    if (!texture)
        return;

    wall_height = get_wall_height(texture->distance);
    top = (SCREEN_HEIGHT / 2) - (wall_height / 2);
    bottom = top + wall_height;
    if (top < 0)
        top = 0;
    if (bottom > SCREEN_HEIGHT)
        bottom = SCREEN_HEIGHT;

    texture->y_start = top;
    texture->y_end = bottom;
    texture->wall_height = wall_height;

    draw_vertical_line(params, texture, column);
}

void draw_wall(t_params *params)
{
    float step, angle, distance;
    int col;
    char wall;
    t_img *texture;

    if (!params)
        return;

    wall = ' ';
    texture = NULL;
    step = FOV / SCREEN_WIDTH;
    angle = params->delta - (FOV / 2);
    col = 0;

    while (col < SCREEN_WIDTH)
    {
        texture = get_wall_texture(params, wall);
        if (!texture)
        {
            col++;
            continue;
        }

        distance = get_distance(params, texture, angle, &wall);
        distance *= cos(angle - params->delta);

        if (distance > 0.1)
            put_wall_pexel(params, texture, col, wall);

        angle += step;
        col++;
    }
}





