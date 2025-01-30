/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_utils_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:48:23 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/30 17:38:43 by rhanitra         ###   ########.fr       */
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

int check_error_color(char *color)
{
	int		i;
	char	**tab;
	int		value;

	i = 0;
	value = 0;
	tab = ft_split(color, ',');
	if (!tab || tab[3])
	{
		free_array(tab);
		return (1);
	}
	while(tab[i] != NULL)
	{
		value = ft_atoi(tab[i]);
		if (value < 0 || value > 255)
		{
			free_array(tab);
			return (1);
		}
		i++;
	}
	free_array(tab);
	return (0);
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
	if (check_error_color(params->f) || invalid_color_config(params->f))
		return (perror_msg("Erron on data color", NULL));
	if (check_error_color(params->c) || invalid_color_config(params->c))
		return (perror_msg("Erron on data color", NULL));
	return (0);
}
