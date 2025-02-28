/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_error_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:08:07 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/16 20:07:48 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int check_x_side(t_params *params)
{
	params->pos->value.x += 1;
	if (find_value(params) == '\0' || find_value(params) == 32)
	{
		params->pos->value.x -= 1;
		return (1);
	}
	params->pos->value.x -= 1;
	params->pos->value.x -= 1;
	if (find_value(params) == 32 || find_value(params) == '\0')
	{
		params->pos->value.x -= 1;
		return (1);
	}
	params->pos->value.x += 1;
	return (0);
}

int check_y_side(t_params *params)
{
	params->pos->value.y -= 1;
	if (find_value(params) == 32 || find_value(params) == '\0')
	{
		params->pos->value.y -= 1;
		return (1);
	}
	params->pos->value.y += 1;
	params->pos->value.y += 1;
	if (find_value(params) == 32 || find_value(params) == '\0')
	{
		params->pos->value.y += 1;
		return (1);
	}
	params->pos->value.y -= 1;
	return (0);
}

int	check_error_wall(char c, t_params *params)
{
	if (c == 48 || c == 'N' || c == 'W' || c == 'S' || c == 'E')
	{
		if (params->pos->value.y == 0 || params->pos->value.x == 0 \
		|| params->pos->value.y == params->map_height - 1)
		{
			perror_msg("The wall is not closed", NULL);
			return (1);
		}
		if (check_x_side(params) || check_y_side(params))
		{
			perror_msg("The wall is not closed", NULL);
			return (1);
		}
	}
	return (0);
}

int	check_map(t_params *params)
{
	int			i;
	int			j;
	
	i = 0;
	while (params->map[i] != NULL)
	{
		j = 0;
		params->pos->value.y = i;
		while (params->map[i][j] != '\0')
		{
			params->pos->value.x = j;
			if (check_error_wall(params->map[i][j], params))
				return (1);
			if (is_not_playable(params->map[i][j], params))
				return (perror_msg("The game is not playable", NULL));
			j++;
		}
		i++;
	}
	return (0);
}

