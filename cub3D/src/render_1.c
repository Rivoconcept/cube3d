/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttelolah <ttelolah@student.42antananavo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/04 18:41:23 by ttelolah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ray_trace(t_params *params, float angle, float distance)
{
	float	i;
	int		px;
	int		py;

	modulo_angle(&angle);
	i = 0.0;
	px = (int)params->player->x;
	py = (int)params->player->y;
	while (i < distance)
	{
		px = (int)(params->player->x + sin(angle) * i);
		py = (int)(params->player->y - cos(angle) * i);
		my_mlx_pixel_put(px, py, 0x00FF00, params);
		i += 0.1;
	}
}

void	trace_fov(t_params *params)
{
	t_img	*texture;

	texture = params->texture;
	update_player_dir(params);
	get_distance(params, &texture, params->delta);
	ray_trace(params, params->delta, texture->distance);
	printf("wall: %d - wx:%d - wy:%d $$$$ x:%d - y%d\n", (char)putval(params,
			texture->wx, texture->wy), texture->wx, texture->wy, texture->wx
		% 64, texture->wy % 64);
}
