/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_handle_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:40:10 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/03 19:56:13 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	handle_keypress(int keycode, t_params *params)
{
	if (keycode == XK_Escape)
	{
		cleanup(params);
		exit(0);
	}
	return (0);
}

int	handle_keyrelease(int keycode, t_params *params)
{
	if (keycode == W)
		params->player->key_up = false;
	if (keycode == S)
		params->player->key_down = false;
	if (keycode == A)
		params->player->key_left = false;
	if (keycode == D)
		params->player->key_right = false;
	return (0);
}

int	handle_mouse_click(t_params *params)
{
	cleanup(params);
	exit(0);
	return (0);
}