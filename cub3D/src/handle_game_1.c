/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttelolah <ttelolah@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:00:58 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/03 13:50:29 by ttelolah         ###   ########.fr       */
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

int	draw_rectangle(t_params *params)
{
	int		i;
	int		j;
	t_rect	*rect;

	rect = params->rect;
	if (params->win_open == NULL)
	{
		return (1);
	}
	j = rect->x;
	while (j < rect->x + rect->width)
	{
		my_mlx_pixel_put(j, rect->y, rect->color, params);
		my_mlx_pixel_put(j, rect->y + rect->height - 1, rect->color, params);
		j++;
	}
	i = rect->y;
	while (i < rect->y + rect->height)
	{
		my_mlx_pixel_put(rect->x, i, rect->color, params);
		my_mlx_pixel_put(rect->x + rect->width - 1, i, rect->color, params);
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
