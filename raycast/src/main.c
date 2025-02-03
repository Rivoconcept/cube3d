/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:13:00 by ttelolah          #+#    #+#             */
/*   Updated: 2025/02/03 16:16:58 by rhanitra         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/cub3d.h"

void	cleanup(t_params *params)
{
	if (params->win_open)
	{
		mlx_destroy_window(params->mlx_connexion, params->win_open);
		params->win_open = NULL;
	}
	if (params->mlx_connexion)
	{
		mlx_destroy_display(params->mlx_connexion);
		free(params->mlx_connexion);
		params->mlx_connexion = NULL;
	}
	/*if (params->f_color)
		free(params->f_color);
	if (params->c_color)
		free(params->c_color);
	if (params->rect)
		free(params->rect);
	if (params->player)
		free(params->player);
	if (params->map)
		free_list_map(params->map);
	handle_free(params->no);
	handle_free(params->so);
	handle_free(params->we);
	handle_free(params->ea);
	handle_free(params->f);
	handle_free(params->c);*/
	free(params);
}

void	mlx_initialization(t_params *params)
{
	params->mlx_connexion = mlx_init();
	if (!params->mlx_connexion)
	{
		perror("Failed to initialize mlx");
		exit(EXIT_FAILURE);
	}
}

void	mlx_window_open(t_params *params)
{
	params->win_open = mlx_new_window(params->mlx_connexion, \
	SCREEN_WIDTH, SCREEN_HEIGHT, "My Window");
	if (!params->win_open)
	{
		perror("Failed to create window");
		cleanup(params);
		exit(EXIT_FAILURE);
	}
}

void	put_pixel(int x, int y, int color, t_params *params)
{
	if (x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT || x < 0 || y < 0)
		return ;
	int	index = y * params->size_line + x * params->bpp / 8;
	params->data[index] = color & 0xFF;
	params->data[index + 1] = (color >> 8) & 0xFF;
	params->data[index + 2] = (color >> 16) & 0xFF;
}

/*void draw_square(int x, int y, int size, int color, t_game *game)
{
	int	i = 0;

	while (i < size)
	{
		put_pixel(x + i, y, color, game);
		i++;
	}
	int	j = 0;
	while (j < size)
	{
		put_pixel(x, y + j, color, game);
		j++;
	}
	int	k = 0;
	while (k < size)
	{
		put_pixel(x + size, y + k, color, game);
		k++;
	}
	int	l = 0;
	while (l < size)
	{
		put_pixel(x + l, y + size, color, game);
		l++;
	}
}*/

void draw_square(int x, int y, int size, int color, t_params *params)
{
	for (int i = 0; i < size; i++)
		put_pixel(x + i, y, color, params);
	for (int i = 0; i < size; i++)
		put_pixel(x, y + i, color, params);
	for (int i = 0; i < size; i++)
		put_pixel(x + size, y + i, color, params);
	for (int i = 0; i < size; i++)
		put_pixel(x + i, y + size, color, params);
}

void init_game(t_params *params)
{
	params->mlx_connexion = mlx_init();
	params->win_open = mlx_new_window(params->mlx_connexion, SCREEN_WIDTH, SCREEN_HEIGHT, "Game");
	params->img = mlx_new_image(params->mlx_connexion, SCREEN_WIDTH, SCREEN_HEIGHT);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_params	*params;
	init_game(params);
	draw_square(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 10, 0x00FF00, params);
	mlx_loop(params->mlx_connexion);
	cleanup(params);
	return (0);
}
