/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_utils_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:48:23 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/09 12:52:39 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void parse_color(t_params *params, char *color, int i, int value)
{
	if (color == params->f)
	{
		if (i == 0)
			params->f_color->r = value;
		if (i == 1)
			params->f_color->g = value;
		if (i == 2)
			params->f_color->b = value;
	}
	if (color == params->c)
	{
		if (i == 0)
			params->c_color->r = value;
		if (i == 1)
			params->c_color->g = value;
		if (i == 2)
			params->c_color->b = value;
	}
}

int check_error_color(char *color, t_params *params)
{
	int		i;
	char	**tab;
	int		value;

	i = 0;
	value = 0;
	tab = ft_split(color, ',');
	if (!tab || tab[3])
		return (free_array(tab), 1);
	while(tab[i] != NULL)
	{
		value = ft_atoi(tab[i]);
		if (value < 0 || value > 255)
			return (free_array(tab), 1);
		parse_color(params, color, i, value);
		i++;
	}
	return (free_array(tab), 0);
}

int invalid_color_config(char *color)
{
	int	i;

	i = 0;
	if (!color)
		return (0);
	while (color[i] != '\0')
	{
		if (ft_isdigit(color[i]) || color[i] == ',')
		{
			i++;
			continue ;
		}
		if (!ft_isdigit(color[i]) && color[i] != ',')
			return (1);
		i++;
	}
	return (0);
}

int check_error_config(t_params *params)
{
	if (params->no == NULL || params->so == NULL || params->we == NULL \
		|| params->ea == NULL || params->f == NULL || params->c == NULL)
		return (perror_msg("Erron on data config", NULL));
	if (check_error_color(params->f, params) || invalid_color_config(params->f))
		return (perror_msg("Erron on data color", NULL));
	if (check_error_color(params->c, params) || invalid_color_config(params->c))
		return (perror_msg("Erron on data color", NULL));
	return (0);
}
