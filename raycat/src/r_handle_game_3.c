/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_handle_game_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:40:10 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/06 15:42:50 by rhanitra         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/cub3d.h"

void  escape_window(int keycode, t_params *params)
{
	if (keycode == XK_Escape)
	{
		cleanup(params);
		exit(0);
	}
}

void	rotate_palyer(int keycode, t_params *params)
{
	if (keycode == 65361)
        params->delta -= 0.09;
    if (keycode == 65363)
        params->delta += 0.09;
}

/*int	handle_keypress(int keycode, t_params *params)
{
	int	x;
	int	y;
	int	step;

	step = 1;
	x = params->player->x;
	y = params->player->y;
	escape_window(keycode, params);
	rotate_palyer(keycode, params);
	if (keycode == 122 && put_element_value(params, x, y - 1) != '1')
		params->player->y -= step;
	if (keycode == 115 && put_element_value(params, x, y + 1) != '1')
		params->player->y += step;
	if (keycode == 113 && put_element_value(params, x - 1, y) != '1')
		params->player->x -= step;
	if (keycode == 100 && put_element_value(params, x + 1, y) != '1')
		params->player->x += step;
	return (0);
}*/

int direction_calc(double *x, double *y, int keycode, t_params *params)
{
	if (keycode == 122)
	{
		*x = params->player->x + sin(params->delta) * STEP;
		*y = params->player->y - cos(params->delta) * STEP;
		return (1);
	}
	else if (keycode == 115)
	{
		*x = params->player->x - sin(params->delta) * STEP;
		*y = params->player->y + cos(params->delta) * STEP;
		return (1);
	}
	else if (keycode == 113)
	{
		*x = params->player->x - cos(params->delta) * STEP;
		*y = params->player->y - sin(params->delta) * STEP;
		return (1);
	}
	else if (keycode == 100)
	{
		*x = params->player->x + cos(params->delta) * STEP;
		*y = params->player->y + sin(params->delta) * STEP;
		return (1);
	}
	return (0);
}

int	handle_keypress(int keycode, t_params *params)
{
	double	x;
	double	y;

	escape_window(keycode, params);
	rotate_palyer(keycode, params);
	if (!direction_calc(&x, &y, keycode, params))
		return (0);
	if (put_element_value(params, (int)x, (int)y) != '1')
	{
		params->player->x = x;
		params->player->y = y;
	}
	return (0);
}


int	handle_mouse_click(t_params *params)
{
	cleanup(params);
	exit(0);
	return (0);
}