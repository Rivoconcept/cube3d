/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_render_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/17 19:14:52 by rhanitra         ###   ########.fr       */
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

void draw_vertical_line(t_params *params, int x, int y_start, int y_end, int color)
{
    int y;
    
    y = y_start;
    if (y_end > y_start)
    {
        while (y < y_end)
        {
            my_mlx_pixel_put(x, y, color, params);
            y++;
        }
    }
}


/*void draw_vertical_line(t_params *params, int x, int y_start, int y_end, t_img *texture, float wall_x, int wall_height)
{
    int y;
    int tex_x;
    int tex_y;
    int color;

    tex_x = (int)(wall_x * texture->line_len) % texture->line_len;

    y = y_start;
    while (y < y_end)
    {
        tex_y = ((y - y_start) * texture->line_len) / wall_height;
        int pixel_index = (tex_y * texture->line_len) + (tex_x * (texture->bpp / 8));
        color = *(int *)(texture->data + pixel_index);

        my_mlx_pixel_put(x, y, color, params);
        y++;
    }
}*/

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


void put_wall_pexel(t_params *params, int column, float distance, char wall)
{
    int wall_height;
    int top;
    int bottom;
    int color;

    if (wall == 'N')
        color = 0x00ff00;
    else
        color = 0xffffff;
    wall_height = get_wall_height(distance);
    top = (SCREEN_HEIGHT / 2) - (wall_height / 2);
    bottom = (SCREEN_HEIGHT / 2) + (wall_height / 2);
    // top = (SCREEN_HEIGHT / 2) - (wall_height / 2);
    // bottom = top + wall_height;
    if (top < 0)
        top = 0;
    if (bottom > SCREEN_HEIGHT)
        bottom = SCREEN_HEIGHT;
    draw_vertical_line(params, column, top, bottom, color);
}

/*void draw_wall(t_params *params)
{
    float step;
    float angle;
    float distance;
    int col;

    step = FOV / SCREEN_WIDTH;
    angle = params->delta - (FOV / 2);
    col = 0;
    while (col < SCREEN_WIDTH)
    {
        distance = get_distance(params, angle);


        if (distance > 0.1)
           put_wall_pexel(params, col, distance * 2);
        angle += step;
        col++;
    }
}*/

void draw_wall(t_params *params)
{
    float step;
    float angle;
    float distance;
    int col;
    char wall;

    wall = ' ';
    step = FOV / SCREEN_WIDTH;
    angle = params->delta - (FOV / 2);
    col = 0;
    while (col < SCREEN_WIDTH)
    {
        distance = get_distance(params, angle, &wall);
        distance *= cos(angle - params->delta);
        if (distance > 0.1)
            put_wall_pexel(params, col, distance, wall);
        angle += step;
        col++;
    }
}




