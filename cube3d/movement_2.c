/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:08:15 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/26 15:34:37 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_player(t_params *params, int code)
{
	t_position	*pos;

	pos = put_position_p(params->map, 'P');
	move_pass(params, pos, code);
	free_list_position(pos);
}

int	handle_keypress(int keycode, t_params *params)
{
	if (keycode == XK_Escape)
	{
		cleanup(params);
		exit(0);
	}
	if (count_data_game(params->map, 'P'))
	{
		if (keycode == 122 || keycode == 65362)
			move_player(params, 1);
		if (keycode == 115 || keycode == 65364)
			move_player(params, 2);
		if (keycode == 113 || keycode == 65361)
			move_player(params, 3);
		if (keycode == 100 || keycode == 65363)
			move_player(params, 4);
	}
	else
		put_img_you_win(params);
	return (0);
}

int	handle_mouse_click(t_params *params)
{
	cleanup(params);
	exit(0);
	return (0);
}
