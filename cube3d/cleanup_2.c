/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:08:31 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/26 16:15:19 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	cleanup_img(t_params *params)
{
	clean_img_1(params);
	clean_img_2(params);
	clean_img_3(params);
	clean_img_4(params);
	clean_img_5(params);
}

void handle_free(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}

void	cleanup(t_params *params)
{
	/*if (params->win_open)
	{
		mlx_destroy_window(params->mlx_connexion, params->win_open);
		params->win_open = NULL;
	}
	if (params->mlx_connexion)
	{
		mlx_destroy_display(params->mlx_connexion);
		free(params->mlx_connexion);
		params->mlx_connexion = NULL;
	}*/
	/*if (params->map)
		free_list_map(params->map);*/
	handle_free(params->no);
	handle_free(params->so);
	handle_free(params->we);
	handle_free(params->ea);
	handle_free(params->f);
	handle_free(params->c);
	free(params);
}
