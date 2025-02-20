/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_handle_game_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:00:52 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/20 09:34:30 by rhanitra         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/cub3d.h"

void	rotate_player(int keycode, t_params *params)
{
	if (keycode == 65361)
		params->delta -= 0.09;
	if (keycode == 65363)
		params->delta += 0.09;
	modulo_angle(&params->delta);
}

int direction_calc(float *x, float *y, int keycode, t_params *params)
{
	if (keycode == Z)
	{
		*x = params->player->x + sin(params->delta) * STEP;
		*y = params->player->y - cos(params->delta) * STEP;
		return (1);
	}
	else if (keycode == S)
	{
		*x = params->player->x - sin(params->delta) * STEP;
		*y = params->player->y + cos(params->delta) * STEP;
		return (1);
	}
	else if (keycode == A)
	{
		*x = params->player->x - cos(params->delta) * STEP;
		*y = params->player->y - sin(params->delta) * STEP;
		return (1);
	}
	else if (keycode == D)
	{
		*x = params->player->x + cos(params->delta) * STEP;
		*y = params->player->y + sin(params->delta) * STEP;
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
    draw_wall(params);
    mlx_put_image_to_window(params->mlx_connexion, params->win_open, \
    params->screen->img, 0, 0);
    return (0);
}

