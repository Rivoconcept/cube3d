/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_render_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/03 18:59:31 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	encode_color(uint8_t r, uint8_t g, uint8_t b, t_params *params)
{
    if (params->x >= params->win_width || params->y >= params->win_height \
        || params->x < 0 || params->y < 0)
		return (0);
    return (r << 16 | g << 8 | b);
}

int	pixel_render(t_params *params)
{
    if (params->win_open != NULL)
        mlx_pixel_put(params->mlx_connexion, params->win_open, 
            params->win_width / 2, params->win_height / 2, RED_PIXEL);
    return (0);
}

void move_player(t_player *player)
{
    int step;

    step = 5;
    if (player->key_up)
        player->y -= step;
    if (player->key_down)
        player->y += step;
    if (player->key_left)
        player->x -= step;
    if (player->key_right)
        player->x += step;
}

int draw_loop(t_params *params)
{
    t_player    *player;

    player = params->player;
    move_player(player);
    put_player(params);
    mlx_put_image_to_window(params->mlx_connexion, params->win_open, params->image->img, 0, 0);
    return (0);
}
