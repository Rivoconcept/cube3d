/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_load_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:55:54 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/20 17:58:14 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	load_img_wall_down_left(t_params *params)
{
	int		img_width;
	int		img_height;

	params->img.wall_down_left = mlx_xpm_file_to_image(params->mlx_connexion, \
	"./image/wall_down_left.xpm", &img_width, &img_height);
	if (params->img.wall_down_left == NULL)
	{
		printf("Failed to load image : wall_down_left.xpm\n");
		cleanup(params);
		exit(EXIT_FAILURE);
	}
}

void	load_img_wall_down_center(t_params *params)
{
	int		img_width;
	int		img_height;

	params->img.wall_down_center = mlx_xpm_file_to_image(params->mlx_connexion, \
	"./image/wall_down_center.xpm", &img_width, &img_height);
	if (params->img.wall_down_center == NULL)
	{
		printf("Failed to load image : wall_down_center.xpm\n");
		cleanup(params);
		exit(EXIT_FAILURE);
	}
}

void	load_img_wall_down_right(t_params *params)
{
	int		img_width;
	int		img_height;

	params->img.wall_down_right = mlx_xpm_file_to_image(params->mlx_connexion, \
	"./image/wall_down_right.xpm", &img_width, &img_height);
	if (params->img.wall_down_right == NULL)
	{
		printf("Failed to load image : wall_down_right.xpm\n");
		cleanup(params);
		exit(EXIT_FAILURE);
	}
}

void	load_img_player(t_params *params)
{
	int		img_width;
	int		img_height;

	params->img.player = mlx_xpm_file_to_image(params->mlx_connexion, \
	"./image/mario_face.xpm", &img_width, &img_height);
	if (params->img.player == NULL)
	{
		printf("Failed to load image : mario_face.xpm\n");
		cleanup(params);
		exit(EXIT_FAILURE);
	}
}

void	load_img_collectible(t_params *params)
{
	int		img_width;
	int		img_height;

	params->img.collectible = mlx_xpm_file_to_image(params->mlx_connexion, \
	"./image/collectible.xpm", &img_width, &img_height);
	if (params->img.collectible == NULL)
	{
		printf("Failed to load image : collectible.xpm\n");
		cleanup(params);
		exit(EXIT_FAILURE);
	}
}
