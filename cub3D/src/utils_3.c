/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttelolah <ttelolah@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:48:23 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/09 12:02:33 by ttelolah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_only_space(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	if (str[0] == '\n' || str[0] == '\0')
		return (1);
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '\n' || str[i] == '\0')
		return (1);
	return (0);
}

void	is_all_config_set(t_params *params, int *flag, char *gnl)
{
	if ((params->path->no != NULL && params->path->so != NULL \
		&& params->path->we != NULL && params->path->ea != NULL \
		&& params->path->f != NULL && params->path->c != NULL) \
		&& is_map_line(gnl))
		*flag = 1;
}

int	get_pos_x(int x, t_params *params)
{
	int	map_width;

	map_width = params->win_width;
	if (x < 0 || x >= map_width * 64)
	{
		return (-1);
	}
	return (x / 64);
}

int	get_pos_y(int y, t_params *params)
{
	int	map_height;

	map_height = params->map_height;
	if (y < 0 || y >= map_height * 64)
	{
		return (-1);
	}
	return (y / 64);
}

int	invalid_color_config(char *color)
{
	int	i;

	i = 0;
	if (!color)
		return (0);
	while (color[i] != '\0')
	{
		if (ft_isdigit(color[i]) || color[i] == ',' || ft_is_space(color[i]))
		{
			i++;
			continue ;
		}
		if (!ft_isdigit(color[i]) && color[i] != ',' && !ft_is_space(color[i]))
			return (1);
		i++;
	}
	return (0);
}
