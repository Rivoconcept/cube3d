/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_init_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:49:17 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/19 18:56:19 by rhanitra         ###   ########.fr       */
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
	img->y_start = 0;
	img->y_end = 0;
	img->wall_x = 0.0;
	img->wall_height = 0;
	img->distance = 0;
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

t_img	*init_img_NO(t_params *params)
{
	t_img	*no;

	no = init_list_img();
	if (!no)
		return (NULL);
	no->img = mlx_xpm_file_to_image(params->mlx_connexion, params->path->no,
			&params->win_width, &params->win_height);
	if (!no->img)
	{
		perror_msg("Failed to create image", NULL);
		cleanup(params);
		exit(EXIT_FAILURE);
	}
	no->data = mlx_get_data_addr(no->img, &no->bpp, &no->line_len, &no->endian);
	if (!no->data)
	{
		perror_msg("Failed to get image data", NULL);
		cleanup(params);
		exit(EXIT_FAILURE);
	}
	return (no);
}

t_img	*init_img_SO(t_params *params)
{
	t_img	*so;

	so = init_list_img();
	if (!so)
		return (NULL);
	so->img = mlx_xpm_file_to_image(params->mlx_connexion, params->path->so,
			&params->win_width, &params->win_height);
	if (!so->img)
	{
		perror_msg("Failed to create image", NULL);
		cleanup(params);
		exit(EXIT_FAILURE);
	}
	so->data = mlx_get_data_addr(so->img, &so->bpp, &so->line_len, &so->endian);
	if (!so->data)
	{
		perror_msg("Failed to get image data", NULL);
		cleanup(params);
		exit(EXIT_FAILURE);
	}
	return (so);
}

t_img	*init_img_EA(t_params *params)
{
	t_img	*ea;

	ea = init_list_img();
	if (!ea)
		return (NULL);
	ea->img = mlx_xpm_file_to_image(params->mlx_connexion, params->path->ea,
			&params->win_width, &params->win_height);
	if (!ea->img)
	{
		perror_msg("Failed to create image", NULL);
		cleanup(params);
		exit(EXIT_FAILURE);
	}
	ea->data = mlx_get_data_addr(ea->img, &ea->bpp, &ea->line_len, &ea->endian);
	if (!ea->data)
	{
		perror_msg("Failed to get image data", NULL);
		cleanup(params);
		exit(EXIT_FAILURE);
	}
	return (ea);
}

t_img	*init_img_WE(t_params *params)
{
	t_img	*we;

	we = init_list_img();
	if (!we)
		return (NULL);
	we->img = mlx_xpm_file_to_image(params->mlx_connexion, params->path->we,
			&params->win_width, &params->win_height);
	if (!we->img)
	{
		perror_msg("Failed to create image", NULL);
		cleanup(params);
		exit(EXIT_FAILURE);
	}
	we->data = mlx_get_data_addr(we->img, &we->bpp, &we->line_len, &we->endian);
	if (!we->data)
	{
		perror_msg("Failed to get image data", NULL);
		cleanup(params);
		exit(EXIT_FAILURE);
	}
	return (we);
}
