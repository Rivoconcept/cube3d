/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttelolah <ttelolah@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:20:42 by ttelolah          #+#    #+#             */
/*   Updated: 2025/03/09 12:22:07 by ttelolah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	escape_space(char *color, int *i)
{
	while (ft_is_space(color[*i]))
	{
		(*i)++;
	}
}

void	escape_digit(char *color, int *i)
{
	while (ft_isdigit(color[*i]))
		(*i)++;
}

int	escape(char *color, int *i)
{
	escape_space(color, i);
	if (!ft_isdigit(color[*i]))
	{
		return (1);
	}
	escape_digit(color, i);
	escape_space(color, i);
	return (0);
}

int	is_format_color(char *color)
{
	int	i;

	i = 0;
	if (!color)
		return (0);
	escape_space(color, &i);
	if (color[i] == 'F' || color[i] == 'C')
		i++;
	if (escape(color, &i))
		return (0);
	if (color[i] == ',')
		i++;
	if (escape(color, &i))
		return (0);
	if (color[i] == ',')
		i++;
	if (escape(color, &i))
		return (0);
	if (color[i] == '\0')
		return (1);
	return (0);
}
