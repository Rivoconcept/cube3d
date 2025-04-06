/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:48:23 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/06 10:48:00 by rhanitra         ###   ########.fr       */
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

int	is_all_config_set(t_params *params, int *flag, char *gnl, char *str)
{
	if (params->path->no != NULL 
		&& params->path->no[ft_strlen(params->path->no) - 6] != 'n')
		return (free(str), free(gnl), cleanup(params), \
		perror_msg("Error on data config", NULL));
	if (params->path->so != NULL 
		&& params->path->so[ft_strlen(params->path->so) - 6] != 's')
		return (free(str), free(gnl), cleanup(params), \
		perror_msg("Error on data config", NULL));
	if (params->path->ea != NULL 
		&& params->path->ea[ft_strlen(params->path->ea) - 6] != 'e')
		return (free(str), free(gnl), cleanup(params), \
		perror_msg("Error on data config", NULL));
	if (params->path->we != NULL 
		&& params->path->we[ft_strlen(params->path->we) - 6] != 'w')
		return (free(str), free(gnl), cleanup(params), \
		perror_msg("Error on data config", NULL));
	if ((params->path->no != NULL && params->path->so != NULL \
		&& params->path->we != NULL && params->path->ea != NULL \
		&& params->path->f != NULL && params->path->c != NULL) \
		&& is_map_line(gnl))
		*flag = 1;
	return (0);
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
