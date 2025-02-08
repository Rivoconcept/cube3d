/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_init_game_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:00:52 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/08 18:19:35 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_player	*init_player(void)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (player == NULL)
		return (NULL);
	player->init = '\0';
	player->x = 0;
	player->y = 0;
	player->width = 0;
	player->height = 0;
	player->color = 0;
	return (player);
}

void	put_player_adress(t_params *params)
{
	t_map	*current_map;
	t_line	*line;

	current_map = params->map;
	while (current_map != NULL)
	{
		line = current_map->line_value.line;
		while (line != NULL)
		{
			if (line->cell_value.value == params->player->init)
			{
				if (params->player->x == 0 && params->player->y == 0)
				{
					params->player->x = (line->cell_value.index * SLICE_SIZE)
						+ (SLICE_SIZE / 2);
					params->player->y = (current_map->line_value.index
							* SLICE_SIZE) + (SLICE_SIZE / 2);
				}
			}
			line = line->next;
		}
		current_map = current_map->next;
	}
}
