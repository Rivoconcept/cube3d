/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:35:39 by ttelolah          #+#    #+#             */
/*   Updated: 2025/02/22 15:06:26 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_img	*init_player_direction(t_params *params)
{
	if (params->player->init == 'N')
	{
		params->delta = 0;
		return (params->NO);
	}
	else if (params->player->init == 'S')
	{
		params->delta = PI;
		return (params->SO);
	}
	else if (params->player->init == 'E')
	{
		params->delta = PI / 2;
		return (params->EA);
	}
	else if (params->player->init == 'W')
	{
		params->delta = 3 * PI / 2;
		return (params->WE);
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

