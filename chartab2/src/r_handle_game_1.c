/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_handle_game_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:00:58 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/19 18:34:54 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_rect	*init_rectangle(void)
{
	t_rect	*rect;

	rect = (t_rect *)malloc(sizeof(t_rect));
	if (rect == NULL)
		return (NULL);
	rect->x = 0;
	rect->y = 0;
	rect->width = 0;
	rect->height = 0;
	rect->color = 0;
	return (rect);
}

int draw_rectangle(t_params *params)
{
    int		i;
	int		j;
    t_rect *rect;

	rect = params->rect;
    if (params->win_open == NULL)
	{
        return (1);
	}
	j = rect->x;
	while (j < rect->x + rect->width)
	{
        my_mlx_pixel_put(j, rect->y, rect->color, params->screen);
        my_mlx_pixel_put(j, rect->y + rect->height - 1, rect->color, params->screen);
		j++;
	}
	i = rect->y;
	while (i < rect->y + rect->height)
	{
        my_mlx_pixel_put(rect->x, i, rect->color, params->screen);
        my_mlx_pixel_put(rect->x + rect->width - 1, i, rect->color, params->screen); 
		i++;
	}
    return (0);
}

void	put_wall(t_params *params)
{
	int			i;
	int			j;

	i = 0;
	while (params->map[i] != NULL)
	{
		j = 0;
		while (params->map[i][j] != '\0')
		{
			if (params->map[i][j] == '1' && i <= params->map_height \
				&& j < params->map_width)
			{
				params->rect->x = j * 64;
				params->rect->y = i * 64;
				params->rect->width = 64;
				params->rect->height = 64;
				params->rect->color = 0xff00b4d8;
				draw_rectangle(params);
			}
			j++;
		}
		i++;
	}
}

/*void put_wall(t_params *params)
{
    t_map *current_map;
    t_line *current_line;
    int view_distance = 10;
    int player_x = (int)params->player->x;
    int player_y = (int)params->player->y;
    
    current_map = params->map;
    while (current_map != NULL && abs(current_map->line_value.index - player_y) <= view_distance)
    {
        if (abs(current_map->line_value.index - player_y) <= view_distance)
        {
            current_line = current_map->line_value.line;
            while (current_line != NULL)
            {
                if (abs(current_line->cell_value.index - player_x) <= view_distance)
                    put_rectangle(params, current_map, current_line);
                current_line = current_line->next;
            }
        }
        current_map = current_map->next;
    }
}*/

