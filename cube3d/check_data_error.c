/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:08:42 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/21 18:53:09 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	count_data_game(t_map *map, char c)
{
	int			count;
	t_map		*current_map;
	t_line		*current_line;

	count = 0;
	current_map = map;
	while (current_map != NULL)
	{
		current_line = current_map->line_value.line;
		while (current_line != NULL)
		{
			if (current_line->cell_value.value == c)
				count++;
			current_line = current_line->next;
		}
		current_map = current_map->next;
	}
	return (count);
}

int	check_intrus_data(t_map *map)
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
			data = current_line->cell_value.value;
			if (data != 80 && data != 69 && data != 67 && data != 48 \
				&& data != 49 && data != 10 && data != 0 && data != 32)
				return (1);
			current_line = current_line->next;
		}
		current_map = current_map->next;
	}
	return (0);
}

int	check_rectangle(t_map *map)
{
	int			i;
	int			size_line;
	int			size_map;
	t_map		*current_map;
	t_line		*current_line;

	i = 0;
	current_map = map;
	current_line = current_map->line_value.line;
	size_line = count_element_list(current_line);
	size_map = count_element_list_mapline(map);
	while (current_map != NULL && i <= size_map)
	{
		current_line = current_map->line_value.line;
		if (size_line != count_element_list(current_line))
			return (1);
		current_map = current_map->next;
		i++;
	}
	return (0);
}

int	check_extension(char *str)
{
	int		i;
	int		size;
	char	temp[5];

	i = 0;
	temp[0] = '\0';
	size = ft_strlen(str) - 1;
	while (str[size] && i < 5)
	{
		temp[i] = str[size];
		i++;
		size--;
	}
	temp[i] = '\0';
	if (ft_strncmp(temp, "reb.", 4) == 0 && temp[i - 1] != '/')
		return (1);
	return (0);
}
