/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_render_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/07 18:09:00 by rhanitra         ###   ########.fr       */
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


void clear_img(t_params *params)
{
    int x;
    int y;

    y = 0;
    while (y < params->win_height)
    {
        x = 0;
        while (x < params->win_width)
        {
            my_mlx_pixel_put(x, y, 0x000000, params);
            x++;
        }
        y++;
    }
}

int draw_loop(t_params *params)
{
    clear_img(params);
    put_wall(params);
    put_player(params);
    trace_fov(params);
    mlx_put_image_to_window(params->mlx_connexion, params->win_open, params->image->img, 0, 0);
    return (0);
}
