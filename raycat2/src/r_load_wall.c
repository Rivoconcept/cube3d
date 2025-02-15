/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_load_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:55:54 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/15 16:47:28 by rhanitra         ###   ########.fr       */
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

int	get_pixel_color(t_img *wall, int x, int y)
{
    int		color;
    char	*pixel;

    if (x < 0 || y < 0 || x >= wall->line_len || y >= wall->endian)
        return (0x000000);
    pixel = wall->data + (y * wall->line_len + x * (wall->bpp / 8));
    color = *(int *)pixel;
    return (color);
}

void	display_pixel_from_texture(t_img *wall, int tex_x, int tex_y, int screen_x, int screen_y, t_params *params)
{
    int	color;

    color = get_pixel_color(wall, tex_x, tex_y);
    my_mlx_pixel_put(screen_x, screen_y, color, params);
}

