/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:08:35 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/20 17:58:26 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_error_wall_up(t_map *map)
{
	char		data;
	t_map		*current_map;
	t_line		*current_line;

	data = '0';
	current_map = map;
	current_line = current_map->line_value.line;
	while (current_line != NULL)
	{
		if (current_line->cell_value.value == '\n')
			break ;
		data = current_line->cell_value.value;
		if (data != 49)
			return (1);
		current_line = current_line->next;
	}
	return (0);
}

int	check_error_wall_down(t_map *map)
{
	char		data;
	t_map		*current_map;
	t_line		*current_line;

	data = '0';
	current_map = map;
	while (current_map != NULL)
	{
		current_line = current_map->line_value.line;
		current_map = current_map->next;
	}
	while (current_line != NULL)
	{
		if (current_line->cell_value.value == '\0' )
			break ;
		data = current_line->cell_value.value;
		if (data != 49)
			return (1);
		current_line = current_line->next;
	}
	return (0);
}

int	check_error_wall_left(t_map *map)
{
	char	data;
	t_map	*current_map;

	data = '0';
	current_map = map;
	while (current_map != NULL)
	{
		data = current_map->line_value.line->cell_value.value;
		if (data != 49)
			return (1);
		current_map = current_map->next;
	}
	return (0);
}

int	check_error_wall_right(t_map *map)
{
	char		data;
	t_map		*current_map;
	t_line		*current_line;

	data = '0';
	current_map = map;
	while (current_map != NULL)
	{
		current_line = current_map->line_value.line;
		while (current_line != NULL)
		{
			if (current_line->cell_value.value == '\n' \
			|| current_line->cell_value.value == '\0')
				break ;
			data = current_line->cell_value.value;
			current_line = current_line->next;
		}
		if (data != 49)
			return (1);
		current_map = current_map->next;
	}
	return (0);
}

int	check_error_wall(t_map *map)
{
	if (check_error_wall_up(map) || check_error_wall_down(map) \
		|| check_error_wall_left(map) || check_error_wall_right(map))
		return (1);
	return (0);
}
