/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttelolah <ttelolah@student.42antananavo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/04 18:28:27 by ttelolah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate_and_draw(int x, int y, float angle, t_params *params)
{
	int	new_x;
	int	new_y;
	int	pivot_x;
	int	pivot_y;

	pivot_x = params->player->x;
	pivot_y = params->player->y;
	new_x = pivot_x + (x - pivot_x) * cos(angle) - (y - pivot_y) * sin(angle);
	new_y = pivot_y + (x - pivot_x) * sin(angle) + (y - pivot_y) * cos(angle);
	my_mlx_pixel_put(new_x, new_y, params->player->color, params);
}

int	draw_player(t_params *params, int x, int y)
{
	int		i;
	int		j;
	float	angle;

	angle = params->delta;
	i = 0;
	while (i++ < 5)
	{
		j = 0;
		while (j++ < i)
		{
			rotate_and_draw(x, y, angle, params);
			rotate_and_draw(x, y + i, angle, params);
			rotate_and_draw(x - j, y + i, angle, params);
			rotate_and_draw(x + j, y + i, angle, params);
		}
	}
	return (0);
}

void	put_player(t_params *params)
{
	int	i;
	int	j;

	i = 0;
	while (params->map[i] != NULL)
	{
		j = 0;
		while (params->map[i][j] != '\0')
		{
			if (params->map[i][j] == params->player->init)
			{
				if (params->player->x == 0 && params->player->y == 0)
				{
					params->player->x = (j * SLICE_SIZE) + (SLICE_SIZE / 2);
					params->player->y = (i * SLICE_SIZE) + (SLICE_SIZE / 2);
				}
				params->player->width = SLICE_SIZE;
				params->player->height = SLICE_SIZE;
				params->player->color = 0xffff3f;
				draw_player(params, params->player->x, params->player->y);
			}
			j++;
		}
		i++;
	}
}
