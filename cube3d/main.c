/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:30:13 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/26 15:36:49 by rhanitra         ###   ########.fr       */
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

void	check_map(int fd, t_params *params)
{
	t_map	*map;

	map = load_map(fd, params);
	if (!map)
	{
		perror_msg("Failed to load map", NULL);
		exit(EXIT_FAILURE);
	}
	/*if (count_data_game(map, 'P') > 1 || count_data_game(map, 'E') > 1 \
		|| check_error_wall(map) || check_intrus_data(map) || check_init_road(map)
		|| check_error_config(params))*/
	if (check_error_config(params))
	{
		perror("La carte présente une ou plusieures erreurs");
		free_list_map(map);
		exit(EXIT_FAILURE);
	}
	/*else if (check_flood_fill(map))
	{
		perror("Un ou plusieurs chemin bloque(s). Le jeu est impossible !");
		free_list_map(map);
		exit(EXIT_FAILURE);
	}*/
	print_config(params);
	free_list_map(map);
}

void	so_long_initializer(int fd, t_params *params)
{
	mlx_initialization(params);
	params->map = load_map(fd, params);
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
	//put_img_data(params);
	mlx_loop(params->mlx_connexion);
}

int	main(int argc, char **argv)
{
	int	fd;
	t_params	*params;
	
	if (argc != 2 || (argc == 2 && !argv[1][0]) || !check_extension(argv[1]))
		return (perror_msg("Invalid parameter", NULL));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror_msg("File cannot open", NULL));
	params = create_list_param();
	if (!params)
		return (perror_msg("Allocation failed on create_list_param", NULL));
	
	check_map(fd, params);
	//so_long_initializer(argv[1], params);
	cleanup(params);
	close(fd);
	return (0);
}
