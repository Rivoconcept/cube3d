/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_handle_game_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:40:10 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/15 13:04:46 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	handle_mouse_click(t_params *params)
{
	cleanup(params);
	exit(0);
	return (0);
}

void  escape_window(int keycode, t_params *params)
{
	if (keycode == XK_Escape)
	{
		cleanup(params);
		exit(0);
	}
}

int	encode_color(uint8_t r, uint8_t g, uint8_t b)
{
    return (r << 16 | g << 8 | b);
}

void    my_mlx_pixel_put(int x, int y, int color, t_params *params)
{
    char    *dst;

    if (x < 0 || y < 0 || x >= params->win_width || y >= params->win_height)
        return ;
    dst = params->clear->data + (y * params->clear->line_len + x * \
        (params->clear->bpp / 8));
    *(unsigned int*)dst = color;
}
