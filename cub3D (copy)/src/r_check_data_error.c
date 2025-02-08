/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_check_data_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:50:23 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/30 07:32:46 by rhanitra         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
			if (data != 'N' && data != 'S' && data != 'E' && data != 'W' \
				&& data != 49 && data != 10 && data != 48 && data != 32)
				return (perror_msg("Invalid data entry in map", NULL));
			current_line = current_line->next;
		}
		current_map = current_map->next;
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
	if (ft_strncmp(temp, "buc.", 4) == 0 && temp[i - 1] != '/')
		return (1);
	return (0);
}
