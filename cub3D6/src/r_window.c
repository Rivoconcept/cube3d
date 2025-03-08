/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_window.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:40:10 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/08 14:25:02 by rhanitra         ###   ########.fr       */
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
	if (putval(params, x, y) != '1' \
		&& putval(params, x, y) != ' ' && putval(params, x, y) != '\0')
	{
		params->player->x = x;
		params->player->y = y;
	}
	return (0);
}

