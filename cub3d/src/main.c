/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:13:00 by ttelolah          #+#    #+#             */
/*   Updated: 2025/01/27 18:55:04 by rhanitra         ###   ########.fr       */
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

/* void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
} */


int	check_map(int fd, t_params *params)
{
	if (check_error_config(params))
	{
		close(fd);
		cleanup(params);
		return (perror_msg("one or more errors were detected in the map configuration", NULL));
	}
	/*else if (check_flood_fill(map))
	{
		perror("Un ou plusieurs chemin bloque(s). Le jeu est impossible !");
		free_list_map(map);
		exit(EXIT_FAILURE);
	}*/
	return (0);
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
	params->map = load_map(fd, params);
	if (!params->map)
	{
		close(fd);
		cleanup(params);
		ft_exit_faillure("one or more errors were detected in the map configuration", NULL);
	}
	if (check_map(fd, params))
		exit(EXIT_FAILURE);
	//print_config(params);
	print_map(params);
	check_wall(params->map);
	printf("\n******************************************************\n\n");
	print_map(params);
	cleanup(params);
	close(fd);
	return (0);
}
