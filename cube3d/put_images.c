/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:35:06 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/20 17:57:35 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	load_img_wall(t_params *params)
{
	load_img_wall_up_left(params);
	load_img_wall_up_center(params);
	load_img_wall_up_right(params);
	load_img_wall_down_left(params);
	load_img_wall_down_center(params);
	load_img_wall_down_right(params);
	load_img_wall_left(params);
	load_img_wall_right(params);
}

void	load_img_data(t_params *params)
{
	load_img_collectible(params);
	load_img_flower_one(params);
	load_img_flower_two(params);
	load_img_ground(params);
	load_img_player(params);
	load_img_exit_open(params);
	load_img_exit_close(params);
	load_img_you_win(params);
}

void	put_img_wall(t_params *params)
{
	load_img_wall(params);
	put_wall_up_left(params);
	put_wall_up_center(params);
	put_wall_up_right(params);
	put_wall_down_left(params);
	put_wall_down_center(params);
	put_wall_down_right(params);
	put_wall_left(params);
	put_wall_right(params);
}

void	put_img_data(t_params *params)
{
	load_img_data(params);
	put_img_exit(params);
	put_img_player(params);
	put_img_obstacle(params);
	put_img_ground(params);
	put_img_collectible(params);
	put_img_player(params);
}
