/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_init_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:49:17 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/18 19:09:42 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_img	*init_img_screen(t_params *params)
{
	t_img	*screen;

	screen = (t_img *)malloc(sizeof(t_img));
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
	screen->draw = NULL;
	return (screen);
}

t_img	*init_img_NO(t_params *params)
{
	t_img	*no;

	no = (t_img *)malloc(sizeof(t_img));
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
	no->draw = init_draw();
	if (!no->draw)
	{
		perror_msg("Failed to allocate draw structure", NULL);
		cleanup(params);
		exit(EXIT_FAILURE);
	}
	return (no);
}

t_img	*init_img_SO(t_params *params)
{
	t_img	*so;

	so = (t_img *)malloc(sizeof(t_img));
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
	so->draw = init_draw();
	if (!so->draw)
	{
		perror_msg("Failed to allocate draw structure", NULL);
		cleanup(params);
		exit(EXIT_FAILURE);
	}
	return (so);
}

t_img	*init_img_EA(t_params *params)
{
	t_img	*ea;

	ea = (t_img *)malloc(sizeof(t_img));
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
	ea->draw = init_draw();
	if (!ea->draw)
	{
		perror_msg("Failed to allocate draw structure", NULL);
		cleanup(params);
		exit(EXIT_FAILURE);
	}
	return (ea);
}

t_img	*init_img_WE(t_params *params)
{
	t_img	*we;

	we = (t_img *)malloc(sizeof(t_img));
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
	we->draw = init_draw();
	if (!we->draw)
	{
		perror_msg("Failed to allocate draw structure", NULL);
		cleanup(params);
		exit(EXIT_FAILURE);
	}
	return (we);
}
