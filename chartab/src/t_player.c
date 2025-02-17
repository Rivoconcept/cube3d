/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:35:39 by ttelolah          #+#    #+#             */
/*   Updated: 2025/02/16 20:19:14 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_player_direction(t_params *params)
{
	if (params->player->init == 'N')
		params->delta = 0;
	else if (params->player->init == 'S')
		params->delta = PI;
	else if (params->player->init == 'E')
		params->delta = PI / 2;
	else if (params->player->init == 'W')
		params->delta = 3 * PI / 2;
}

void	modulo_angle(float *angle)
{
	while (*angle < 0)
		*angle += 2 * PI;
	while (*angle >= 2 * PI)
		*angle -= 2 * PI;
}

