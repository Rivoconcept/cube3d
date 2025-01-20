/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_load_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:55:54 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/20 17:58:07 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	load_img_you_win(t_params *params)
{
	int	img_width;
	int	img_height;

	params->img.you_win = mlx_xpm_file_to_image(params->mlx_connexion, \
	"./image/you_win.xpm", &img_width, &img_height);
	if (params->img.you_win == NULL)
	{
		printf("Failed to load image : you_win.xpm\n");
		cleanup(params);
		exit(EXIT_FAILURE);
	}
}
