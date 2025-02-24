/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_error_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:08:07 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/16 19:21:30 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_ground_left(t_params *params)
{
	if (params->pos->value.x != 0)
	{
		params->pos->value.x -= 1;
		if (find_value(params) == 48)
		{
			params->pos->value.x += 1;
			return (1);
		}
		params->pos->value.x += 1;
	}
	return (0);
}

int	is_ground_right(t_params *params)
{
	params->pos->value.x += 1;
	if (find_value(params) == '\n')
	{
		params->pos->value.x -= 1;
		return (0);
	}
	if (find_value(params) == 48)
	{
		params->pos->value.x -= 1;
		return (1);
	}
	params->pos->value.x -= 1;
	return (0);
}

int	is_ground_up(t_params *params)
{
	if (params->pos->value.y != 0)
	{
		params->pos->value.y -= 1;
		if (find_value(params) == 48)
		{
			params->pos->value.y += 1;
			return (1);
		}
		params->pos->value.y += 1;
	}
	return (0);
}

int	is_ground_down(t_params *params)
{
	if (params->pos->value.y < params->map_height)
	{
		params->pos->value.y += 1;
		if (find_value(params) == 48)
		{
			params->pos->value.y -= 1;
			return (1);
		}
		params->pos->value.y -= 1;
	}
	return (0);
}

int	is_not_playable(char c, t_params *params)
{
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
	{
		if (!is_ground_up(params) \
			&& !is_ground_down(params) \
			&& !is_ground_left(params) \
			&& !is_ground_right(params))
			return (1);
	}
	return (0);
}