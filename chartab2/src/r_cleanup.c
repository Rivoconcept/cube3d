/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_cleanup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:50:08 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/17 19:13:26 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void clear_img(t_params *params)
{
    int x;
    int y;
    int ceiling_color;
    int floor_color;

    ceiling_color = encode_color(params->c_color->r, params->c_color->g, params->c_color->b);
    floor_color = encode_color(params->f_color->r, params->f_color->g, params->f_color->b);
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

void handle_free(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}

void free_path(t_path *path)
{
	handle_free(path->no);
	handle_free(path->so);
	handle_free(path->we);
	handle_free(path->ea);
	handle_free(path->f);
	handle_free(path->c);
	free(path);
}

void free_other_list(t_params *params)
{
	if (params->map)
		free_array(params->map);
	if (params->pos)
		free(params->pos);
	if (params->screen)
		free(params->screen);
	if (params->NO)
		free(params->NO);
	if (params->SO)
		free(params->SO);
	if (params->WE)
		free(params->WE);
	if (params->EA)
		free(params->EA);
	if (params->f_color)
		free(params->f_color);
	if (params->c_color)
		free(params->c_color);
	if (params->rect)
		free(params->rect);
	if (params->player)
		free(params->player);
	if (params->path)
		free_path(params->path);
}

void	cleanup(t_params *params)
{
	if (params->win_open)
	{
		mlx_destroy_window(params->mlx_connexion, params->win_open);
		params->win_open = NULL;
	}
	if (params->mlx_connexion)
	{
		mlx_destroy_image(params->mlx_connexion, params->screen->img);
		mlx_destroy_display(params->mlx_connexion);
		free(params->mlx_connexion);
		params->mlx_connexion = NULL;
	}
	free_other_list(params);
	free(params);
}


