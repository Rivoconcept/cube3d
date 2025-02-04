/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_handle_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:40:10 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/04 17:11:56 by rhanitra         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/cub3d.h"

int	handle_keypress(int keycode, t_params *params)
{
	if (keycode == XK_Escape)
	{
		cleanup(params);
		exit(0);
	}

	/*if (keycode == Z)
		params->player->key_up = true;
	if (keycode == S)
		params->player->key_down = true;
	if (keycode == Q)
		params->player->key_left = true;
	if (keycode == D)
		params->player->key_right = true;*/

	if (keycode == 119)
		params->player->y -= 5;
	if (keycode == 97)
		params->player->y += 5;
	if (keycode == 115 || keycode == 65361)
		params->player->x -= 5;
	if (keycode == 100 || keycode == 65363)
		params->player->x += 5;
	/*if (keycode == 65361)
		params->player->x -= 5;
	if (keycode == 65363)
		params->player->x += 5;*/

	return (0);
}

/*int	handle_keyrelease(int keycode, t_params *params)
{
	if (keycode == Z)
		params->player->key_up = false;
	if (keycode == S)
		params->player->key_down = false;
	if (keycode == Q)
		params->player->key_left = false;
	if (keycode == D)
		params->player->key_right = false;
	return (0);
}*/

int	handle_mouse_click(t_params *params)
{
	cleanup(params);
	exit(0);
	return (0);
}