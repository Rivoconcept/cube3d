/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_load_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:55:54 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/21 18:29:02 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	load_img_exit_open(t_params *params)
{
	int	img_width;
	int	img_height;

	params->img.exit_open = mlx_xpm_file_to_image(params->mlx_connexion, \
	"./image/exit_open.xpm", &img_width, &img_height);
	if (params->img.exit_open == NULL)
	{
		printf("Failed to load image : exit_open.xpm\n");
		cleanup(params);
		exit(EXIT_FAILURE);
	}
}

void	load_img_exit_close(t_params *params)
{
	int	img_width;
	int	img_height;

	params->img.exit_close = mlx_xpm_file_to_image(params->mlx_connexion, \
	"./image/exit_close.xpm", &img_width, &img_height);
	if (params->img.exit_close == NULL)
	{
		printf("Failed to load image : exit_close.xpm\n");
		cleanup(params);
		exit(EXIT_FAILURE);
	}
}

void	load_img_ground(t_params *params)
{
	int	img_width;
	int	img_height;

	params->img.ground = mlx_xpm_file_to_image(params->mlx_connexion, \
	"./image/ground.xpm", &img_width, &img_height);
	if (params->img.ground == NULL)
	{
		printf("Failed to load image : ground.xpm\n");
		cleanup(params);
		exit(EXIT_FAILURE);
	}
}

void	load_wall_img(t_params *params)
{
	int		img_width;
	int		img_height;

	params->img.flower_one = mlx_xpm_file_to_image(params->mlx_connexion, \
	"./image/flower_one.xpm", &img_width, &img_height);
	if (params->img.flower_one == NULL)
	{
		printf("Failed to load image : flower_one.xpm\n");
		cleanup(params);
		exit(EXIT_FAILURE);
	}
}

