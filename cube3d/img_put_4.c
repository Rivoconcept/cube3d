/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_put_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:35:06 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/20 17:57:55 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_player(t_params *params, t_map *map, t_line *line)
{
	t_image		*img;
	int			height;
	int			width;

	height = count_element_list_mapline(params->map) - 1;
	width = count_element_list_mapcol(params->map);
	if (map->line_value.index > 0 && line->cell_value.value == 'P' \
		&& map->line_value.index <= height && line->cell_value.index > 0 \
		&& line->cell_value.index < width - 1)
	{
		params->x = line->cell_value.index;
		params->y = map->line_value.index;
		img = params->img.player;
		mlx_put_image_to_window(params->mlx_connexion, params->win_open, \
		img, params-> x * 64, params->y * 64);
	}
}

void	put_img_player(t_params *params)
{
	t_map		*current_map;
	t_line		*current_line;

	current_map = params->map;
	while (current_map != NULL)
	{
		current_line = current_map->line_value.line;
		while (current_line != NULL)
		{
			put_player(params, current_map, current_line);
			current_line = current_line->next;
		}
		current_map = current_map->next;
	}
}

void	put_obstacle_one(t_params *params, t_map *map, t_line *line)
{
	t_image		*img;
	int			height;
	int			width;

	height = count_element_list_mapline(params->map) - 2;
	width = count_element_list_mapcol(params->map);
	if (map->line_value.index > 0 && line->cell_value.value == '1' \
		&& map->line_value.index % 2 == 0 && map->line_value.index <= height \
		&& line->cell_value.index > 0 && line->cell_value.index < width - 1)
	{
		params->x = line->cell_value.index;
		params->y = map->line_value.index;
		img = params->img.flower_one;
		mlx_put_image_to_window(params->mlx_connexion, params->win_open, \
		img, params-> x * 64, params->y * 64);
	}
}

void	put_obstacle_two(t_params *params, t_map *map, t_line *line)
{
	t_image		*img;
	int			height;
	int			width;

	height = count_element_list_mapline(params->map) - 2;
	width = count_element_list_mapcol(params->map);
	if ((map->line_value.index == 1 || map->line_value.index % 2 != 0) \
		&& line->cell_value.value == '1' && map->line_value.index <= height \
		&& line->cell_value.index > 0 && line->cell_value.index < width - 1)
	{
		params->x = line->cell_value.index;
		params->y = map->line_value.index;
		img = params->img.flower_two;
		mlx_put_image_to_window(params->mlx_connexion, params->win_open, \
		img, params->x * 64, params->y * 64);
	}
}

void	put_img_obstacle(t_params *params)
{
	t_map	*current_map;
	t_line	*current_line;

	current_map = params->map;
	while (current_map != NULL)
	{
		current_line = current_map->line_value.line;
		while (current_line != NULL)
		{
			put_obstacle_one(params, current_map, current_line);
			put_obstacle_two(params, current_map, current_line);
			current_line = current_line->next;
		}
		current_map = current_map->next;
	}
}
