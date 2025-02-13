/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_render_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/13 18:10:05 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


int draw_loop(t_params *params)
{
    clear_img(params);
    // put_wall(params);
    // put_player(params);
    // trace_fov(params);
    draw_wall(params);
    mlx_put_image_to_window(params->mlx_connexion, params->win_open, \
    params->image->img, 0, 0);
    return (0);
}
