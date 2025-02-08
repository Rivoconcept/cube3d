/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_handle_game_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:40:10 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/07 16:56:55 by rhanitra         ###   ########.fr       */
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
