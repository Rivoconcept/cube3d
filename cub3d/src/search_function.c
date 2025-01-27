/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:08:19 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/20 17:57:32 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_position	*put_position_p(t_map *map, char c)
{
	t_map		*current_map;
	t_line		*current_line;
	t_position	*adress;

	adress = create_list_position();
	if (adress == NULL)
		return (NULL);
	current_map = map;
	while (current_map != NULL)
	{
		current_line = current_map->line_value.line;
		while (current_line != NULL)
		{
			if (current_line->cell_value.value == c)
			{
				adress->value.x = current_line->cell_value.index;
				adress->value.y = current_map->line_value.index;
				return (adress);
			}
			current_line = current_line->next;
		}
		current_map = current_map->next;
	}
	return (free(adress), NULL);
}

char	find_value(t_map *map, t_position *pos)
{
	t_map		*current_map;
	t_line		*current_line;

	current_map = map;
	while (current_map != NULL)
	{
		if (current_map->line_value.index == pos->value.y)
		{
			current_line = current_map->line_value.line;
			while (current_line != NULL)
			{
				if (current_line->cell_value.index == pos->value.x)
					return (current_line->cell_value.value);
				current_line = current_line->next;
			}
		}
		current_map = current_map->next;
	}
	return ('\0');
}

void	change_value(t_map *map, t_position *pos, char c)
{
	t_map		*current_map;
	t_line		*current_line;

	current_map = map;
	while (current_map != NULL)
	{
		if (current_map->line_value.index == pos->value.y)
		{
			current_line = current_map->line_value.line;
			while (current_line != NULL)
			{
				if (current_line->cell_value.index == pos->value.x)
				{
					current_line->cell_value.value = c;
					return ;
				}
				current_line = current_line->next;
			}
		}
		current_map = current_map->next;
	}
}
