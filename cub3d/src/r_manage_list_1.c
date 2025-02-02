/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_manage_list_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:48:59 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/02 13:13:22 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_line	*create_list_line(char data)
{
	t_line	*new_element;

	new_element = (t_line *)malloc(sizeof(t_line));
	if (new_element == NULL)
		exit(EXIT_FAILURE);
	new_element->cell_value.value = data;
	new_element->cell_value.index = 0;
	new_element->next = NULL;
	return (new_element);
}

t_map	*create_list_map(t_line *line)
{
	t_map	*new_element;

	if (line == NULL)
	{
		printf("Error\nThe list line is null.\n");
		exit(EXIT_FAILURE);
	}
	new_element = (t_map *)malloc(sizeof(t_map));
	if (new_element == NULL)
		exit(EXIT_FAILURE);
	new_element->line_value.line = line;
	new_element->line_value.index = 0;
	new_element->next = NULL;
	return (new_element);
}

t_position	*create_list_position(void)
{
	t_position	*new_pos;

	new_pos = (t_position *)malloc(sizeof(t_position));
	if (new_pos == NULL)
		return (NULL);
	new_pos->value.x = 0;
	new_pos->value.y = 0;
	new_pos->next = NULL;
	return (new_pos);
}

t_f	*init_ground_color(void)
{
	t_f	*ground;

	ground = (t_f *)malloc(sizeof(t_f));
	if (ground == NULL)
		return (NULL);
	ground->r = 0;
	ground->g = 0;
	ground->b = 0;
	return (ground);
}

t_c	*init_ceiling_color(void)
{
	t_c	*ceiling;

	ceiling = (t_c *)malloc(sizeof(t_c));
	if (ceiling == NULL)
		return (NULL);
	ceiling->r = 0;
	ceiling->g = 0;
	ceiling->b = 0;
	return (ceiling);
}
