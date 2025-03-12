/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttelolah <ttelolah@student.42antananavo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:35:39 by ttelolah          #+#    #+#             */
/*   Updated: 2025/03/04 22:26:19 by ttelolah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_img	*init_player_direction(t_params *params)
{
	if (params->player->init == 'N')
	{
		params->delta = 0;
		return (params->no);
	}
	else if (params->player->init == 'S')
	{
		params->delta = PI;
		return (params->so);
	}
	else if (params->player->init == 'E')
	{
		params->delta = PI / 2;
		return (params->ea);
	}
	else if (params->player->init == 'W')
	{
		params->delta = 3 * PI / 2;
		return (params->we);
	}
	return (NULL);
}

void	modulo_angle(float *angle)
{
	while (*angle < 0)
		*angle += 2 * PI;
	while (*angle >= 2 * PI)
		*angle -= 2 * PI;
}
