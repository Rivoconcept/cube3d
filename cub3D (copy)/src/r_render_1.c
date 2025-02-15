/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_render_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/03 16:13:02 by rhanitra         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
