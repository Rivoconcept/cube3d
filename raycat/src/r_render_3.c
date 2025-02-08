/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_render_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/08 19:25:09 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int get_wall_height(double distance)
{
    double dpp;
    int wall_height;

    dpp = (SCREEN_WIDTH / 2.0) / tan(FOV / 2.0);
    if (distance <= 0)
        return (SCREEN_HEIGHT);
    if (distance < 0.5)
        distance = 0.5; // Empêche les distances trop petites qui explosent la hauteur

    // wall_height = (int)((SLICE_SIZE / distance) * dpp);
    wall_height = (int)((SLICE_SIZE / (distance + 0.01)) * dpp);
    if (wall_height > SCREEN_HEIGHT)
        wall_height = SCREEN_HEIGHT;

    return (wall_height);
}


void draw_vertical_line(t_params *params, int x, int y_start, int y_end)
{
    int y;
    
    y = y_start;
    if (y_end > y_start)
    {
        while (y < y_end)
        {
            my_mlx_pixel_put(x, y, 0xFFFFFF, params);
            y++;
        }
    }
}


void put_wall_pexel(t_params *params, int column, double distance)
{
    int wall_height;
    int top;
    int bottom;

    wall_height = get_wall_height(distance);
    top = (SCREEN_HEIGHT / 3) - (wall_height / 2);
    bottom = (SCREEN_HEIGHT / 3) + (wall_height / 2);
    if (top < 0)
        top = 0;
    if (bottom > SCREEN_HEIGHT)
        bottom = SCREEN_HEIGHT;
    draw_vertical_line(params, column, top, bottom);
}

void draw_wall(t_params *params)
{
    double step;
    double angle;
    double distance;
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
}


