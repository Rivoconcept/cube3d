/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_handle_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:40:10 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/02 16:31:44 by rhanitra         ###   ########.fr       */
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
	/*int step = 100; 

	if (keycode == 65362)
		params->player->y -= step;
	if (keycode == 65364)
		params->player->y += step;
	if (keycode == 65361)
		params->player->x -= step;
	if (keycode == 65363)
		params->player->x += step;
    mlx_clear_window(params->mlx_connexion, params->win_open);
    put_wall(params);
	put_player(params);*/

	return (0);
}

int	handle_mouse_click(t_params *params)
{
	cleanup(params);
	exit(0);
	return (0);
}