/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttelolah <ttelolah@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:48:23 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/09 12:22:44 by ttelolah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	parse_color(t_params *params, char *color, int i, int value)
{
	if (color == params->path->f)
	{
		if (i == 0)
			params->f_color->r = value;
		if (i == 1)
			params->f_color->g = value;
		if (i == 2)
			params->f_color->b = value;
	}
	if (color == params->path->c)
	{
		if (i == 0)
			params->c_color->r = value;
		if (i == 1)
			params->c_color->g = value;
		if (i == 2)
			params->c_color->b = value;
	}
}

int	check_error_color(char *color, t_params *params)
{
	int		i;
	char	**tab;
	int		value;

	i = 0;
	value = 0;
	if (!is_format_color(color))
		return (1);
	tab = ft_split(color, ',');
	if (!tab || tab[3])
		return (free_array(tab), 1);
	while (tab[i] != NULL)
	{
		value = ft_atoi(tab[i]);
		if (value < 0 || value > 255)
			return (free_array(tab), 1);
		parse_color(params, color, i, value);
		i++;
	}
	return (free_array(tab), 0);
}

int	is_xpm(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4)
		return (0);
	return (ft_strncmp(&str[len - 4], ".xpm", 4) == 0);
}

int	check_error_config(t_params *params)
{
	if (params->path->no == NULL || params->path->so == NULL \
		|| params->path->we == NULL \
		|| params->path->ea == NULL || params->path->f == NULL \
		|| params->path->c == NULL)
		return (perror_msg("Error on data config", NULL));
	if (!is_xpm(params->path->no) || !is_xpm(params->path->so) \
		|| !is_xpm(params->path->we) || !is_xpm(params->path->ea))
		return (perror_msg("Error on format xpm", NULL));
	if (check_error_color(params->path->f, params) \
	|| invalid_color_config(params->path->f))
		return (perror_msg("Error on data color", NULL));
	if (check_error_color(params->path->c, params) \
	|| invalid_color_config(params->path->c))
		return (perror_msg("Error on data color", NULL));
	return (0);
}
