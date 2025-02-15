/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_manage_list_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:49:10 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/09 13:14:05 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_player	*init_list_player(void)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (player == NULL)
		return (NULL);
	player->init = '\0';
	player->x = 0;
	player->y = 0;
	player->width = 0;
	player->height = 0;
	player->color = 0;
	return (player);
}

t_img	*init_list_img(void)
{
	t_img		*img;
	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = NULL;
	img->data = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
	return (img);
}

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
