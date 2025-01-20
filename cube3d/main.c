/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:30:13 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/20 18:39:08 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	params->win_width, params->win_height, "My Window");
	if (!params->win_open)
	{
		perror("Failed to create window");
		cleanup(params);
		exit(EXIT_FAILURE);
	}
}

void	check_map(char *argv)
{
	t_map	*map;

	map = load_map(argv);
	if (!map)
	{
		perror("Impossible d'initialiser la carte !");
		exit(EXIT_FAILURE);
	}
	if (count_data_game(map, 'P') > 1 || count_data_game(map, 'E') > 1 \
		|| check_error_wall(map) || check_rectangle(map) \
		|| check_intrus_data(map) || check_init_road(map))
	{
		perror("La carte présente une ou plusieures erreurs");
		free_list_map(map);
		exit(EXIT_FAILURE);
	}
	else if (check_flood_fill(map))
	{
		perror("Un ou plusieurs chemin bloque(s). Le jeu est impossible !");
		free_list_map(map);
		exit(EXIT_FAILURE);
	}
	free_list_map(map);
}

void	so_long_initializer(char *argv)
{
	t_params	*params;

	params = create_list_param();
	if (!params)
	{
		perror("Erreur d'allocation de mémoire pour le paramètre");
		exit(EXIT_FAILURE);
	}
	mlx_initialization(params);
	params->map = load_map(argv);
	if (!params->map)
	{
		perror("Failed to load map");
		cleanup(params);
		exit(EXIT_FAILURE);
	}
	params->win_width = count_element_list_mapcol(params->map) * 64;
	params->win_height = count_element_list_mapline(params->map) * 64;
	mlx_window_open(params);
	mlx_hook(params->win_open, KeyPress, KeyPressMask, handle_keypress, params);
	mlx_hook(params->win_open, 17, 1L << 17, handle_mouse_click, params);
	put_img_wall(params);
	put_img_data(params);
	mlx_loop(params->mlx_connexion);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || (argc == 2 && !argv[1][0]) || !check_extension(argv[1]))
	{
		perror("Invalid parameter");
		exit(EXIT_FAILURE);
	}
	else
	{
		//check_map(argv[1]);
		so_long_initializer(argv[1]);
	}
	return (0);
}
