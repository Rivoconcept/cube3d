/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_222.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttelolah <ttelolah@student.42antananavo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/04 21:04:28 by ttelolah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	update_player_dir(t_params *params)
{
	float	angle;

	angle = fmod(params->delta, 2 * PI);
	if (angle < 0)
		angle += 2 * PI;
	if ((angle >= 0 && angle < PI / 4) \
	|| (angle >= 7 * PI / 4 && angle < 2 * PI))
		params->player->dir = 'N';
	else if (angle >= PI / 4 && angle < 3 * PI / 4)
		params->player->dir = 'E';
	else if (angle >= 3 * PI / 4 && angle < 5 * PI / 4)
		params->player->dir = 'S';
	else if (angle >= 5 * PI / 4 && angle < 7 * PI / 4)
		params->player->dir = 'W';
}

void	render_scene(t_params *params)
{
	int		x;
	float	step;
	float	angle;
	t_img	*wall;

	x = 0;
	step = FOV / SCREEN_WIDTH;
	wall = params->texture;
	angle = params->delta - (FOV / 2);
	update_player_dir(params);
	while (x < SCREEN_WIDTH)
	{
		get_distance(params, &wall, angle);
		wall->distance *= cos(angle - params->delta);
		draw_wall_slice(params, wall, x);
		angle += step;
		x++;
	}
}
