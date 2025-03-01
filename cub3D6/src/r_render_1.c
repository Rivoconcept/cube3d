/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_render_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/01 08:28:50 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ray_trace(t_params *params, float angle, float distance)
{
	float	i;
	int		px;
	int		py;
	float	ray_x;
	float	ray_y;
	float	dir_x;
	float	dir_y;

	i = 0.0;
    px = 0;
    py = 0;
	modulo_angle(&angle);
	dir_x = sin(angle);
	dir_y = -cos(angle);
	ray_x = params->player->x;
	ray_y = params->player->y;
	while (i < distance)
	{
		px = (int)(ray_x + dir_x * i);
		py = (int)(ray_y + dir_y * i);
		my_mlx_pixel_put(px, py, 0x00FF00, params);
		i += 0.1;
	}
}

void trace_fov(t_params *params)
{
    // float angle;
    // float step;
    // int i;
	t_img	*texture;

	texture = params->texture;
	update_player_dir(params);
	get_distance(params, &texture, params->delta);
    ray_trace(params, params->delta, texture->distance);
	printf("wall: %d - wx:%d - wy:%d $$$$ x:%d - y%d\n", (char)putval(params, texture->wx, texture->wy),  texture->wx, texture->wy, texture->wx % 64, texture->wy % 64);
	// printf("%c", texture->wall_path);
   /*step = FOV / SCREEN_WIDTH;
    i = 0;
    while (i < SCREEN_WIDTH)
    {
        angle = params->delta - (FOV / 2) + (step * i);
       	get_distance(params, &texture, angle);
        ray_trace(params, angle, texture->distance);
        i++;
    }*/
}



