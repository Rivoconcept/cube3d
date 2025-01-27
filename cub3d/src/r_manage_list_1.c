/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_manage_list_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:37:35 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/27 18:42:57 by rhanitra         ###   ########.fr       */
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

t_params	*create_list_param(void)
{
	t_params	*new_params;

	new_params = (t_params *)malloc(sizeof(t_params));
	if (new_params == NULL)
		return (NULL);
	new_params->mlx_connexion = NULL;
	new_params->win_open = NULL;
	new_params->pos = NULL;
	new_params->no = NULL;
	new_params->so = NULL;
	new_params->we = NULL;
	new_params->ea = NULL;
	new_params->f = NULL;
	new_params->c = NULL;
	new_params->x = 0;
	new_params->y = 0;
	new_params->win_width = 0;
	new_params->win_height = 0;
	new_params->next = NULL;
	return (new_params);
}
