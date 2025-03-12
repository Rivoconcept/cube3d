/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttelolah <ttelolah@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:26:13 by ttelolah          #+#    #+#             */
/*   Updated: 2025/03/03 14:03:56 by ttelolah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	clear_img(t_params *params)
{
	int	x;
	int	y;
	int	ceiling_color;
	int	floor_color;

	ceiling_color = encode_color(params->c_color->r, \
		params->c_color->g, params->c_color->b);
	floor_color = encode_color(params->f_color->r, params->f_color->g, \
		params->f_color->b);
	y = 0;
	while (y < params->win_height)
	{
		x = 0;
		while (x < params->win_width)
		{
			if (y < params->win_height / 2)
				my_mlx_pixel_put(x, y, ceiling_color, params);
			else
				my_mlx_pixel_put(x, y, floor_color, params);
			x++;
		}
		y++;
	}
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr || arr == NULL)
		return ;
	while (arr[i] != NULL)
	{
		if (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
		}
		i++;
	}
	if (arr)
		free(arr);
	arr = NULL;
}

void	handle_free(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}
