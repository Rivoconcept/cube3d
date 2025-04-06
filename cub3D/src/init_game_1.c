/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttelolah <ttelolah@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:16:31 by ttelolah          #+#    #+#             */
/*   Updated: 2025/04/06 17:08:59 by ttelolah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_player(t_params *params)
{
	int			i;
	int			j;

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
					params->player->x = (j * SLICE_SIZE)
						+ (SLICE_SIZE / 2);
					params->player->y = (i * SLICE_SIZE) + (SLICE_SIZE / 2);
				}
			}
			j++;
		}
		i++;
	}
}

void check_first_line_is_valid(int fd, char *gnl, char *str, t_params *params)
{
	if (gnl == NULL)
	{
		free(str);
		ft_exit_faillure(params, fd, "Error on map data", NULL);
	}
	if (ft_is_space(gnl[0]))
	{
		free(gnl);
		free(str);
		ft_exit_faillure(params, fd, "Error on map data", NULL);
	}
}
