/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_render_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/08 13:56:22 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	encode_color(uint8_t r, uint8_t g, uint8_t b)
{
    return (r << 16 | g << 8 | b);
}

void    my_mlx_pixel_put(int x, int y, int color, t_params *params)
{
    char    *dst;

    if (x < 0 || y < 0 || x >= params->win_width || y >= params->win_height)
        return ;
    dst = params->image->data + (y * params->image->line_len + x * \
        (params->image->bpp / 8));
    *(unsigned int*)dst = color;
}

void	rotate_palyer(int keycode, t_params *params)
{
	if (keycode == 65361)
        params->delta -= 0.09;
    if (keycode == 65363)
        params->delta += 0.09;
}

int direction_calc(double *x, double *y, int keycode, t_params *params)
{
	if (keycode == 122)
	{
		*x = params->player->x + sin(params->delta) * STEP;
		*y = params->player->y - cos(params->delta) * STEP;
		return (1);
	}
	else if (keycode == 115)
	{
		*x = params->player->x - sin(params->delta) * STEP;
		*y = params->player->y + cos(params->delta) * STEP;
		return (1);
	}
	else if (keycode == 113)
	{
		*x = params->player->x - cos(params->delta) * STEP;
		*y = params->player->y - sin(params->delta) * STEP;
		return (1);
	}
	else if (keycode == 100)
	{
		*x = params->player->x + cos(params->delta) * STEP;
		*y = params->player->y + sin(params->delta) * STEP;
		return (1);
	}
	return (0);
}

int	handle_keypress(int keycode, t_params *params)
{
	double	x;
	double	y;

	escape_window(keycode, params);
	rotate_palyer(keycode, params);
	if (!direction_calc(&x, &y, keycode, params))
		return (0);
	if (put_map_value(params, (int)x, (int)y) != '1')
	{
		params->player->x = x;
		params->player->y = y;
	}
	return (0);
}