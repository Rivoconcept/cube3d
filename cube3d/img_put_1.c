/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_put_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:55:54 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/20 17:58:04 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_wall_down_left(t_params *params)
{
	int			y;
	t_image		*img;

	y = count_element_list_mapline(params->map) - 1;
	img = params->img.wall_down_left;
	mlx_put_image_to_window(params->mlx_connexion, \
	params->win_open, img, 0, y * 64);
}

void	put_wall_down_center(t_params *params)
{
	int			x;
	int			y;
	int			width;
	t_image		*img;

	x = 1;
	img = params->img.wall_down_center;
	width = count_element_list_mapcol(params->map) - 1;
	y = count_element_list_mapline(params->map) - 1;
	while (x < width)
	{
		mlx_put_image_to_window(params->mlx_connexion, \
		params->win_open, img, x * 64, y * 64);
		x++;
	}
}

void	put_wall_down_right(t_params *params)
{
	int			x;
	int			y;
	t_image		*img;

	x = count_element_list_mapcol(params->map) - 1;
	y = count_element_list_mapline(params->map) - 1;
	img = params->img.wall_down_right;
	mlx_put_image_to_window(params->mlx_connexion, \
	params->win_open, img, x * 64, y * 64);
}

void	put_wall_left(t_params *params)
{
	int			y;
	int			height;
	t_image		*img;

	y = 1;
	img = params->img.wall_left;
	height = count_element_list_mapline(params->map) - 1;
	while (y < height)
	{
		mlx_put_image_to_window(params->mlx_connexion, \
		params->win_open, img, 0, y * 64);
		y++;
	}
}

void	put_wall_right(t_params *params)
{
	int			x;
	int			y;
	int			height;
	t_image		*img;

	y = 1;
	img = params->img.wall_right;
	x = count_element_list_mapcol(params->map) - 1;
	height = count_element_list_mapline(params->map) - 1;
	while (y < height)
	{
		mlx_put_image_to_window(params->mlx_connexion, \
		params->win_open, img, x * 64, y * 64);
		y++;
	}
}
