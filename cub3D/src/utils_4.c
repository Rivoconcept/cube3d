/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:20:42 by ttelolah          #+#    #+#             */
/*   Updated: 2025/04/06 12:18:48 by rhanitra         ###   ########.fr       */
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

int	in_base(char *gnl)
{
	int	i;

	i = 0;
	while (ft_is_space(gnl[i]))
		i++;
	return ((gnl[i] == 'N' && gnl[i + 1] == 'O') || (gnl[i] == 'S' && gnl[i + 1] == 'O')
		|| (gnl[i] == 'W' && gnl[i + 1] == 'E') || (gnl[i] == 'E' && gnl[i + 1] == 'A')
		|| (gnl[i] == 'F' && gnl[i + 1] == ' ') || (gnl[i] == 'C' && gnl[i + 1] == ' '));
}
