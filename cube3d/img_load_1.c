/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_load_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:55:54 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/20 17:58:17 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	load_img_wall_up_left(t_params *params)
{
	int		img_width;
	int		img_height;

	params->img.wall_up_left = mlx_xpm_file_to_image(params->mlx_connexion, \
	"./image/wall_up_left.xpm", &img_width, &img_height);
	if (params->img.wall_up_left == NULL)
	{
		printf("Failed to load image : wall_up_left.xpm\n");
		cleanup(params);
		exit(EXIT_FAILURE);
	}
}

void	load_img_wall_up_center(t_params *params)
{
	int		img_width;
	int		img_height;

	params->img.wall_up_center = mlx_xpm_file_to_image(params->mlx_connexion, \
	"./image/wall_up_center.xpm", &img_width, &img_height);
	if (params->img.wall_up_center == NULL)
	{
		printf("Failed to load image : wall_up_center.xpm\n");
		cleanup(params);
		exit(EXIT_FAILURE);
	}
}

void	load_img_wall_up_right(t_params *params)
{
	int		img_width;
	int		img_height;

	params->img.wall_up_right = mlx_xpm_file_to_image(params->mlx_connexion, \
	"./image/wall_up_right.xpm", &img_width, &img_height);
	if (params->img.wall_up_right == NULL)
	{
		printf("Failed to load image : wall_up_right.xpm\n");
		cleanup(params);
		exit(EXIT_FAILURE);
	}
}

void	load_img_wall_left(t_params *params)
{
	int		img_width;
	int		img_height;

	params->img.wall_left = mlx_xpm_file_to_image(params->mlx_connexion, \
	"./image/wall_left.xpm", &img_width, &img_height);
	if (params->img.wall_left == NULL)
	{
		printf("Failed to load image : wall_left.xpm\n");
		cleanup(params);
		exit(EXIT_FAILURE);
	}
}

void	load_img_wall_right(t_params *params)
{
	int		img_width;
	int		img_height;

	params->img.wall_right = mlx_xpm_file_to_image(params->mlx_connexion, \
	"./image/wall_right.xpm", &img_width, &img_height);
	if (params->img.wall_right == NULL)
	{
		printf("Failed to load image : wall_right.xpm\n");
		cleanup(params);
		exit(EXIT_FAILURE);
	}
}
