/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_manage_list_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:49:10 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/28 18:49:11 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	count_element_list(t_line *head)
{
	int		count;
	t_line	*current;

	count = 0;
	current = head;
	while (current != NULL)
	{
		if (current->cell_value.value == '\n' \
			|| current->cell_value.value == '\0')
			break ;
		count++;
		current = current->next;
	}
	return (count);
}

void update_col(int count, int *col)
{
	if (*col < count)
	{
		*col = count;
	}
}

int	count_element_list_mapcol(t_map *head)
{
	int		col;
	int		count;
	t_map	*current_map;
	t_line	*current_line;

	col = 0;
	count = 0;
	current_line = NULL;
	current_map = head;
	while (current_map != NULL)
	{
		count = 0;
		current_line = current_map->line_value.line;
		while (current_line != NULL)
		{
			if (current_line->cell_value.value == '\n')
				break ;
			count++;
			current_line = current_line->next;
		}
		if (col < count)
			col = count;
		current_map = current_map->next;
	}
	return (col);
}

int	count_element_list_mapline(t_map *head)
{
	int		count;
	t_map	*current;

	count = 0;
	current = head;
	while (current != NULL)
	{
		if (current->line_value.line->cell_value.value == '\n')
			break ;
		count++;
		current = current->next;
	}
	return (count);
}

void	put_ranks_line(t_line **head)
{
	int		index;
	t_line	*current;

	index = 0;
	current = *head;
	while (current != NULL)
	{
		current->cell_value.index = index;
		index++;
		current = current->next;
	}
}

void	put_ranks_map(t_map **head)
{
	int		index;
	t_map	*current;

	index = 0;
	current = *head;
	while (current != NULL)
	{
		current->line_value.index = index;
		index++;
		current = current->next;
	}
}
