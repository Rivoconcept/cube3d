/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:08:15 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/26 15:34:33 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	dispay_pos_player(t_params *params, t_position *pos, int pass)
{
	change_value(params->map, pos, 'P');
	mlx_put_image_to_window(params->mlx_connexion, params->win_open, \
	params->img.player, pos->value.x * 64, pos->value.y * 64);
	if (pass == 1)
		pos->value.y += 1;
	if (pass == 2)
		pos->value.y -= 1;
	if (pass == 3)
		pos->value.x += 1;
	if (pass == 4)
		pos->value.x -= 1;
	mlx_put_image_to_window(params->mlx_connexion, params->win_open, \
	params->img.ground, pos->value.x * 64, pos->value.y * 64);
	change_value(params->map, pos, '0');
	printf("%d\n", params->move++);
}

void	erase_pos_player(t_params *params, t_position *pos, int pass)
{
	change_value(params->map, pos, 'E');
	mlx_put_image_to_window(params->mlx_connexion, params->win_open, \
	params->img.exit_close, pos->value.x * 64, pos->value.y * 64);
	if (pass == 1)
		pos->value.y += 1;
	if (pass == 2)
		pos->value.y -= 1;
	if (pass == 3)
		pos->value.x += 1;
	if (pass == 4)
		pos->value.x -= 1;
	mlx_put_image_to_window(params->mlx_connexion, params->win_open, \
	params->img.ground, pos->value.x * 64, pos->value.y * 64);
	change_value(params->map, pos, '0');
	printf("%d\n", params->move++);
	put_img_you_win(params);
}

void	move_pass(t_params *params, t_position *pos, int token)
{
	char		value;

	if (token == 1)
		pos->value.y -= 1;
	if (token == 2)
		pos->value.y += 1;
	if (token == 3)
		pos->value.x -= 1;
	if (token == 4)
		pos->value.x += 1;
	value = find_value(params->map, pos);
	if (value != 49 && value != 'E')
	{
		dispay_pos_player(params, pos, token);
		if (!count_data_game(params->map, 'C'))
		{
			pos = put_position_p(params->map, 'E');
			mlx_put_image_to_window(params->mlx_connexion, params->win_open, \
			params->img.exit_open, pos->value.x * 64, pos->value.y * 64);
			free_list_position(pos);
		}
	}
	if (value != 49 && value == 'E' && !count_data_game(params->map, 'C'))
		erase_pos_player(params, pos, token);
}
