/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_manage_list_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:49:10 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/01 07:52:39 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_player	*init_list_player(void)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (player == NULL)
		return (NULL);
	player->init = 0;
	player->dir = 0; 
	player->x = 0;
	player->y = 0;
	player->width = 0;
	player->height = 0;
	player->color = 0;
	return (player);
}

void	init_map_size(t_params *params)
{
	int	i;
	int	j;
	int	col;

	i = 0;
	col = 0;
	while (params->map[i] != NULL)
	{
		j = 0;
		while (params->map[i][j] != '\0')
			j++;
		if (col < j)
			col = j;
		i++;
	}
	params->map_width = col;
	params->map_height = i;
}
