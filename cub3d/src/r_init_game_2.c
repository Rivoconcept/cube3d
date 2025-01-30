/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_init_game_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:49:57 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/30 16:58:19 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"



int	init_config(int *flag, char *gnl, t_params *params)
{
	int		i;

	i = 0;
	if (!*flag && !is_only_space(gnl))
	{
		while (ft_is_space(gnl[i]))
			i++;
		if (put_data_config(params, gnl, &i))
		{
			free(gnl);
			cleanup(params);
			return (1);
		}
	}
	return (0);
}

t_map *load_map(int fd, t_params *params)
{
	t_map	*map;
	t_line	*line;
	char	*gnl;
	int 	flag;

	line = NULL;
	map = NULL;
	flag = 0;
	gnl = get_next_line(fd);
	while (gnl != NULL)
	{
		line = NULL;
		if (is_all_config_set(params))
			flag = 1;
		if (init_config(&flag, gnl, params))
			exit(EXIT_FAILURE);
		if (flag && !is_only_space(gnl))
		{
			initialize_line(&line, gnl);
			initialize_map(&map, line);
		}
		free(gnl);
		gnl = get_next_line(fd);
	}
	return (map);
}
