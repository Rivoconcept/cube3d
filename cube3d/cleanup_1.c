/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:08:31 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/26 15:33:45 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	clean_img_1(t_params *params)
{
	if (params->img.wall_up_left)
	{
		mlx_destroy_image(params->mlx_connexion, params->img.wall_up_left);
		params->img.wall_up_left = NULL;
	}
	if (params->img.wall_up_center)
	{
		mlx_destroy_image(params->mlx_connexion, params->img.wall_up_center);
		params->img.wall_up_center = NULL;
	}
	if (params->img.wall_up_right)
	{
		mlx_destroy_image(params->mlx_connexion, params->img.wall_up_right);
		params->img.wall_up_right = NULL;
	}
	if (params->img.ground)
	{
		mlx_destroy_image(params->mlx_connexion, params->img.ground);
		params->img.ground = NULL;
	}
}

void	clean_img_2(t_params *params)
{
	if (params->img.wall_down_left)
	{
		mlx_destroy_image(params->mlx_connexion, params->img.wall_down_left);
		params->img.wall_down_left = NULL;
	}
	if (params->img.wall_down_center)
	{
		mlx_destroy_image(params->mlx_connexion, params->img.wall_down_center);
		params->img.wall_down_center = NULL;
	}
	if (params->img.wall_down_right)
	{
		mlx_destroy_image(params->mlx_connexion, params->img.wall_down_right);
		params->img.wall_down_right = NULL;
	}
	if (params->img.collectible)
	{
		mlx_destroy_image(params->mlx_connexion, params->img.collectible);
		params->img.collectible = NULL;
	}
}

void	clean_img_3(t_params *params)
{
	if (params->img.wall_left)
	{
		mlx_destroy_image(params->mlx_connexion, params->img.wall_left);
		params->img.wall_left = NULL;
	}
	if (params->img.wall_right)
	{
		mlx_destroy_image(params->mlx_connexion, params->img.wall_right);
		params->img.wall_right = NULL;
	}
	if (params->img.flower_one)
	{
		mlx_destroy_image(params->mlx_connexion, params->img.flower_one);
		params->img.flower_one = NULL;
	}
	if (params->img.flower_two)
	{
		mlx_destroy_image(params->mlx_connexion, params->img.flower_two);
		params->img.flower_two = NULL;
	}
}

void	clean_img_4(t_params *params)
{
	if (params->img.wall_left)
	{
		mlx_destroy_image(params->mlx_connexion, params->img.wall_left);
		params->img.wall_left = NULL;
	}
	if (params->img.wall_right)
	{
		mlx_destroy_image(params->mlx_connexion, params->img.wall_right);
		params->img.wall_right = NULL;
	}
	if (params->img.flower_one)
	{
		mlx_destroy_image(params->mlx_connexion, params->img.flower_one);
		params->img.flower_one = NULL;
	}
	if (params->img.flower_two)
	{
		mlx_destroy_image(params->mlx_connexion, params->img.flower_two);
		params->img.flower_two = NULL;
	}
}

void	clean_img_5(t_params *params)
{
	if (params->img.exit_close)
	{
		mlx_destroy_image(params->mlx_connexion, params->img.exit_close);
		params->img.exit_close = NULL;
	}
	if (params->img.exit_open)
	{
		mlx_destroy_image(params->mlx_connexion, params->img.exit_open);
		params->img.exit_open = NULL;
	}
	if (params->img.player)
	{
		mlx_destroy_image(params->mlx_connexion, params->img.player);
		params->img.player = NULL;
	}
	if (params->img.you_win)
	{
		mlx_destroy_image(params->mlx_connexion, params->img.you_win);
		params->img.you_win = NULL;
	}
}
