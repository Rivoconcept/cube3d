/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:13:00 by ttelolah          #+#    #+#             */
/*   Updated: 2025/02/15 12:58:59 by rhanitra         ###   ########.fr       */
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

void	game_initializer(t_params *params)
{
	mlx_initialization(params);
	init_player_direction(params);
	params->win_width = SCREEN_WIDTH;
	params->win_height = SCREEN_HEIGHT;
	// params->win_width = count_element_list_mapcol(params->map) * SLICE_SIZE;
	// params->win_height = count_element_list_mapline(params->map) * SLICE_SIZE;
	mlx_window_open(params);
	params->image->img = mlx_new_image(params->mlx_connexion, params->win_width, params->win_height);
	if (!params->image->img)
	{
		perror_msg("Failed to create image", NULL);
		cleanup(params);
		exit(EXIT_FAILURE);
	}
	params->image->data = mlx_get_data_addr(params->image->img, &params->image->bpp, &params->image->line_len, &params->image->endian);
	if (!params->image->data)
	{
		perror_msg("Failed to get image data", NULL);
		cleanup(params);
		exit(EXIT_FAILURE);
	}
	mlx_put_image_to_window(params->mlx_connexion, params->win_open, params->image->img, 0, 0);
	
	/*mlx_hook(params->win_open, 2, 1L << 0, handle_keypress, params);
	mlx_hook(params->win_open, 3, 1L << 1, handle_keyrelease, params);*/
	
	mlx_hook(params->win_open, KeyPress, KeyPressMask, handle_keypress, params);
	mlx_hook(params->win_open, 17, 1L << 17, handle_mouse_click, params);
	
	mlx_loop_hook(params->mlx_connexion, draw_loop, params);
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
		ft_exit_faillure(params, fd, "Allocation failed on create_list_param", NULL);
	params->map = load_map(fd, params);
	if (!params->map)
		ft_exit_faillure(params, fd, "one or more errors were detected \
			in the map configuration", NULL);
	if (check_error(fd, params))
		exit(EXIT_FAILURE);
	init_player(params);
	game_initializer(params);
	cleanup(params);
	close(fd);
	return (0);
}

