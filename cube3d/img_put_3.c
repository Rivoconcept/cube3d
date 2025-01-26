/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_put_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:35:06 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/26 15:34:20 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_img_exit_close(t_params *params, t_map *map, t_line *line)
{
	t_image		*img;
	int			height;
	int			width;

	height = count_element_list_mapline(params->map) - 1;
	width = count_element_list_mapcol(params->map);
	if (map->line_value.index > 0 && line->cell_value.value == 'E' \
		&& map->line_value.index <= height && line->cell_value.index > 0 \
		&& line->cell_value.index < width - 1)
	{
		params->x = line->cell_value.index;
		params->y = map->line_value.index;
		img = params->img.exit_close;
		mlx_put_image_to_window(params->mlx_connexion, params->win_open, \
		img, params-> x * 64, params->y * 64);
	}
}

void	put_img_exit_open(t_params *params, t_map *map, t_line *line)
{
	t_image		*img;
	int			height;
	int			width;

	height = count_element_list_mapline(params->map) - 1;
	width = count_element_list_mapcol(params->map);
	if (map->line_value.index > 0 && line->cell_value.value == 'E' \
		&& map->line_value.index <= height && line->cell_value.index > 0 \
		&& line->cell_value.index < width - 1)
	{
		params->x = line->cell_value.index;
		params->y = map->line_value.index;
		img = params->img.exit_open;
		mlx_put_image_to_window(params->mlx_connexion, params->win_open, \
		img, params-> x * 64, params->y * 64);
	}
}

void	put_img_exit(t_params *params)
{
	t_map		*current_map;
	t_line		*current_line;

	current_map = params->map;
	while (current_map != NULL)
	{
		current_line = current_map->line_value.line;
		while (current_line != NULL)
		{
			if (count_data_game(params->map, 'C') > 0)
				put_img_exit_close(params, current_map, current_line);
			else
				put_img_exit_open(params, current_map, current_line);
			current_line = current_line->next;
		}
		current_map = current_map->next;
	}
}

void	put_collectible(t_params *params, t_map *map, t_line *line)
{
	t_image		*img;
	int			height;
	int			width;

	height = count_element_list_mapline(params->map) - 1;
	width = count_element_list_mapcol(params->map);
	if (map->line_value.index > 0 && line->cell_value.value == 'C' \
		&& map->line_value.index <= height && line->cell_value.index > 0 \
		&& line->cell_value.index < width - 1)
	{
		params->x = line->cell_value.index;
		params->y = map->line_value.index;
		img = params->img.collectible;
		mlx_put_image_to_window(params->mlx_connexion, params->win_open, \
		img, params-> x * 64, params->y * 64);
	}
}

void	put_img_collectible(t_params *params)
{
	t_map		*current_map;
	t_line		*current_line;

	current_map = params->map;
	while (current_map != NULL)
	{
		current_line = current_map->line_value.line;
		while (current_line != NULL)
		{
			put_collectible(params, current_map, current_line);
			current_line = current_line->next;
		}
		current_map = current_map->next;
	}
}
