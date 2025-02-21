/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_init_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:49:17 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/21 18:07:54 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_img	*init_list_img(void)
{
	t_img		*img;
	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = NULL;
	img->data = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
	img->wall_path = ' ';
	img->y_start = 0;
	img->y_end = 0;
	img->wx = 0.0;
	img->wy = 0.0;
	img->distance = 0.0;
	return (img);
}

t_img	*init_img_screen(t_params *params)
{
	t_img	*screen;

	screen = init_list_img();
	if (!screen)
		return (NULL);
	screen->img = mlx_new_image(params->mlx_connexion, params->win_width,
			params->win_height);
	if (!screen->img)
	{
		perror_msg("Failed to create image", NULL);
		cleanup(params);
		exit(EXIT_FAILURE);
	}
	screen->data = mlx_get_data_addr(screen->img, &screen->bpp,
			&screen->line_len, &screen->endian);
	if (!screen->data)
	{
		perror_msg("Failed to get image data", NULL);
		cleanup(params);
		exit(EXIT_FAILURE);
	}
	return (screen);
}

t_img	*load_texture(t_params *params, void *mlx, char *path)
{
    t_img *texture;

    texture = malloc(sizeof(t_img));
    if (!texture)
        return (NULL);
    texture->img = mlx_xpm_file_to_image(mlx, path, &texture->width, &texture->height);
	if (!texture->img)
	{
		perror_msg("Failed to create image", NULL);
		cleanup(params);
		exit(EXIT_FAILURE);
	}
    texture->data = mlx_get_data_addr(texture->img, &texture->bpp, &texture->line_len, &texture->endian);
	if (!texture->data)
	{
		perror_msg("Failed to get image data", NULL);
		cleanup(params);
		exit(EXIT_FAILURE);
	}
    return (texture);
}

void	load_all_textures(t_params *params)
{
	params->NO = load_texture(params, params->mlx_connexion, params->path->no);
	params->SO = load_texture(params, params->mlx_connexion, params->path->so);
	params->WE = load_texture(params, params->mlx_connexion, params->path->we);
	params->EA = load_texture(params, params->mlx_connexion, params->path->ea);
}

