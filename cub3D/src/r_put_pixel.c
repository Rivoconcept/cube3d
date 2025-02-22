/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_put_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:40:10 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/16 14:08:03 by rhanitra         ###   ########.fr       */
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
    dst = params->clear->data + (y * params->clear->line_len + x * \
        (params->clear->bpp / 8));
    *(unsigned int*)dst = color;
}
