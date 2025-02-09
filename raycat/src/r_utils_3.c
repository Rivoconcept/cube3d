/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_utils_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:48:23 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/09 13:55:37 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int is_only_space(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	if (str[0] == '\n' || str[0] == '\0')
		return (1);
	while(ft_is_space(str[i]))
		i++;
	if (str[i] == '\n' || str[i] == '\0')
		return (1);
	return (0);
}

int is_all_config_set(t_params *params)
{
	return (params->no != NULL && params->so != NULL && params->we != NULL \
		&& params->ea != NULL && params->f != NULL && params->c != NULL);
}

int get_pos_x(int x)
{
	int	i;
	int	size;
	int	min;
	int	max;

	i = 0;
	size = SCREEN_WIDTH / 64;
	while (i < size)
	{
		min = i * 64;
		max = (i + 1) * 64;

		if (x >= min && x < max)
			return (i);
		i++;
	}
	return (-1);
}

int get_pos_y(int y)
{
	int	i;
	int	size;
	int	min;
	int	max;

	i = 0;
	size = SCREEN_HEIGHT / 64;
	while (i < size)
	{
		min = i * 64; 
		max = (i + 1) * 64;

		if (y >= min && y < max)
			return (i);
		i++;
	}
	return (-1);
}
