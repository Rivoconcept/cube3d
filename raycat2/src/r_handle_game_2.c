/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_handle_game_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:00:52 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/15 09:48:36 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void rotate_and_draw(int x, int y, int pivot_x, int pivot_y, float angle, t_params *params)
{
    int new_x;
    int new_y;

    new_x = pivot_x + (x - pivot_x) * cos(angle) - (y - pivot_y) * sin(angle);
    new_y = pivot_y + (x - pivot_x) * sin(angle) + (y - pivot_y) * cos(angle);

    my_mlx_pixel_put(new_x, new_y, params->player->color, params);
}

int draw_player(t_params *params, int x, int y)
{
    int		i;
	int		j;
    int		pivot_x;
	int		pivot_y;
    float	angle;
	
	i = 0;
	angle = params->delta;
    pivot_x = x;
    pivot_y = y;
    while (i++ < 5)
	{
		j = 0;
		while (j++ < i)
		{
			rotate_and_draw(x, y, pivot_x, pivot_y, angle, params);
            rotate_and_draw(x, y + i, pivot_x, pivot_y, angle, params);
            rotate_and_draw(x - j, y + i, pivot_x, pivot_y, angle, params);
            rotate_and_draw(x + j, y + i, pivot_x, pivot_y, angle, params);			
		}
	}
    return (0);
}

void	put_triangle(t_params *params, t_map *map, t_line *line)
{
	if (line->cell_value.value == params->player->init)
	{
		if (params->player->x == 0 && params->player->y == 0)
		{
			params->player->x = (line->cell_value.index * SLICE_SIZE) + (SLICE_SIZE / 2);
			params->player->y = (map->line_value.index * SLICE_SIZE) + (SLICE_SIZE / 2);
		}
		params->player->width = SLICE_SIZE;
		params->player->height = SLICE_SIZE;
		params->player->color = 0xffff3f;
		draw_player(params, params->player->x, params->player->y);
	}
}


void	put_player(t_params *params)
{
	t_map	*current_map;
	t_line	*current_line;

	current_map = params->map;
	while (current_map != NULL)
	{
		current_line = current_map->line_value.line;
		while (current_line != NULL)
		{
			put_triangle(params, current_map, current_line);
			current_line = current_line->next;
		}
		current_map = current_map->next;
	}
} 

/*void	put_player(t_params *params)
{
	t_map	*current_map;
	t_line	*current_line;
	int		view_distance;
	int		player_x;
	int		player_y;

	view_distance = 10;
	player_x = (int)params->player->x;
	player_y = (int)params->player->y;
	current_map = params->map;
	while (current_map != NULL
		&& abs(current_map->line_value.index - player_y) <= view_distance)
	{
		current_line = current_map->line_value.line;
		while (current_line != NULL)
		{
			if (abs(current_line->cell_value.index - player_x)
				<= view_distance)
				put_triangle(params, current_map, current_line);
			current_line = current_line->next;
		}
		current_map = current_map->next;
	}
}*/

