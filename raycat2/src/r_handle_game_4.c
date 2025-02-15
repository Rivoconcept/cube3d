/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_handle_game_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/15 19:03:30 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate_player(int keycode, t_params *params)
{
	if (keycode == 65361)
		params->delta -= 0.05;
	if (keycode == 65363)
		params->delta += 0.05;
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

int	handle_keypress(int keycode, t_params *params)
{
	float	x;
	float	y;

	escape_window(keycode, params);
	rotate_player(keycode, params);
	if (!direction_calc(&x, &y, keycode, params))
		return (0);
	if (put_map_value(params, (int)x, (int)y) != '1')
	{
		params->player->x = x;
		params->player->y = y;
	}
	return (0);
}