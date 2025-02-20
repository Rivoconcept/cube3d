/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_window.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:40:10 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/16 20:53:07 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	handle_mouse_click(t_params *params)
{
	cleanup(params);
	exit(0);
	return (0);
}

void  escape_window(int keycode, t_params *params)
{
	if (keycode == XK_Escape)
	{
		cleanup(params);
		exit(0);
	}
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

