/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_load_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:55:54 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/15 15:47:00 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	load_texture(t_img *wall, char *img_path, t_params *params)
{
    int	img_width;
    int	img_height;

    wall->img = mlx_xpm_file_to_image(params->mlx_connexion, img_path, &img_width, &img_height);
    if (!wall->img)
    {
        printf("Failed to load image: %s\n", img_path);
        cleanup(params);
        exit(EXIT_FAILURE);
    }
    wall->data = mlx_get_data_addr(wall->img, &wall->bpp, &wall->line_len, &wall->endian);
}

void load_all_textures(t_params *params)
{
    load_texture(&params->wall->NO, "./image/no.xpm", params);
    load_texture(&params->wall->SO, "./image/so.xpm", params);
    load_texture(&params->wall->EA, "./image/ea.xpm", params);
    load_texture(&params->wall->WE, "./image/we.xpm", params);
}


t_img	*get_wall_texture(t_params *params, char wall_dir)
{
    if (wall_dir == 'N')
        return (&params->wall->NO);
    if (wall_dir == 'S')
        return (&params->wall->SO);
    if (wall_dir == 'E')
        return (&params->wall->EA);
    if (wall_dir == 'W')
        return (&params->wall->WE);
    return (NULL);
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
}

void put_wall_pexel(t_params *params, int column, float distance, char wall_dir, float wall_x)
{
    int wall_height;
    int top;
    int bottom;
    t_img *texture;

    wall_height = get_wall_height(distance);
    top = (SCREEN_HEIGHT / 2) - (wall_height / 2);
    bottom = top + wall_height;
    if (top < 0)
        top = 0;
    if (bottom > SCREEN_HEIGHT)
        bottom = SCREEN_HEIGHT;

    texture = get_wall_texture(params, wall_dir);
    if (!texture)
        return;

    draw_vertical_line(params, column, top, bottom, texture, wall_x, wall_height);
}

void draw_wall(t_params *params)
{
    float step;
    float angle;
    float distance;
    int col;
    char wall_dir;
    float wall_x;

    step = FOV / SCREEN_WIDTH;
    angle = params->delta - (FOV / 2);
    col = 0;
    while (col < SCREEN_WIDTH)
    {
        distance = get_distance(params, angle, &wall_dir, &wall_x);
        distance *= cos(angle - params->delta);
        if (distance > 0.1)
            put_wall_pexel(params, col, distance, wall_dir, wall_x);
        angle += step;
        col++;
    }
}*/

