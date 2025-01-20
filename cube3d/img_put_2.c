/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_put_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:55:54 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/20 17:58:01 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_wall_up_left(t_params *params)
{
	t_image		*img;

	img = params->img.wall_up_left;
	mlx_put_image_to_window(params->mlx_connexion, \
	params->win_open, img, 0, 0);
}

void	put_wall_up_right(t_params *params)
{
	t_image		*img;
	int			x;

	x = count_element_list_mapcol(params->map) - 1;
	img = params->img.wall_up_right;
	mlx_put_image_to_window(params->mlx_connexion, \
	params->win_open, img, x * 64, 0);
}

void	put_wall_up_center(t_params *params)
{
	int			x;
	int			width;
	t_image		*img;

	x = 1;
	img = params->img.wall_up_center;
	width = count_element_list_mapcol(params->map) - 1;
	while (x < width)
	{
		mlx_put_image_to_window(params->mlx_connexion, \
		params->win_open, img, x * 64, 0);
		x++;
	}
}

void	put_img_flower_one(t_params *params)
{
	int			x;
	int			width;
	t_image		*img;

	x = 1;
	img = params->img.flower_one;
	width = count_element_list_mapcol(params->map) - 1;
	while (x < width)
	{
		mlx_put_image_to_window(params->mlx_connexion, \
		params->win_open, img, x * 64, 0);
		x++;
	}
}

void	put_img_flower_two(t_params *params)
{
	int			x;
	int			width;
	t_image		*img;

	x = 1;
	img = params->img.flower_two;
	width = count_element_list_mapcol(params->map) - 1;
	while (x < width)
	{
		mlx_put_image_to_window(params->mlx_connexion, \
		params->win_open, img, x * 64, 0);
		x++;
	}
}
