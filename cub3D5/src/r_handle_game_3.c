/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_handle_game_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:00:52 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/28 21:17:30 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*void	rotate_player(int keycode, t_params *params)
{
	if (keycode == 65361)
		params->delta -= 0.09;
	if (keycode == 65363)
		params->delta += 0.09;
	modulo_angle(&params->delta);
}*/

void rotate_player(int keycode, t_params *params)
{
    float rotation_speed;
    rotation_speed = 0.05;
    if (keycode == 65361)
        params->delta -= rotation_speed;
    if (keycode == 65363)
        params->delta += rotation_speed;
    modulo_angle(&params->delta);
}

int direction_calc(float *x, float *y, int keycode, t_params *params)
{
	if (keycode == Z)
	{
		*x = round(params->player->x + sin(params->delta) * SPEED);
		*y = round(params->player->y - cos(params->delta) * SPEED);
		return (1);
	}
	else if (keycode == S)
	{
		*x = round(params->player->x - sin(params->delta) * SPEED);
		*y = round(params->player->y + cos(params->delta) * SPEED);
		return (1);
	}
	else if (keycode == A)
	{
		*x = round(params->player->x - cos(params->delta) * SPEED);
		*y = round(params->player->y - sin(params->delta) * SPEED);
		return (1);
	}
	else if (keycode == D)
	{
		*x = round(params->player->x + cos(params->delta) * SPEED);
		*y = round(params->player->y + sin(params->delta) * SPEED);
		return (1);
	}
	return (0);
}


int draw_loop(t_params *params)
{
    clear_img(params);
    // put_wall(params);
    // put_player(params);
    // trace_fov(params);
    render_scene(params);
    mlx_put_image_to_window(params->mlx_connexion, params->win_open, \
    params->screen->img, 0, 0);
    return (0);
}

