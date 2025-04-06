/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:16:43 by ttelolah          #+#    #+#             */
/*   Updated: 2025/04/06 12:36:05 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_config(int *flag, char *gnl, char *str, t_params *params)
{
	int	i;

	i = 0;
	if (!*flag && !is_only_space(gnl))
	{
		if (put_data_config(params, gnl, &i))
		{
			free(str);
			free(gnl);
			cleanup(params);
			return (1);
		}
	}
	return (0);
}

void	copy_line(char *gnl, char **str, int fd, t_params *params)
{
	char	*tmp;

	tmp = ft_strjoin(*str, gnl);
	if (!tmp)
	{
		free(gnl);
		free(*str);
		ft_exit_faillure(params, fd, "Allocation failed on malloc str", NULL);
	}
	free(*str);
	*str = tmp;
	if (!is_map_line(gnl))
	{
		free(gnl);
		free(*str);
		ft_exit_faillure(params, fd, "Error on map data", NULL);
	}
}

void init_load_map_attrib(char **str, int *flag)
{
	*flag = 0;
	*str = ft_strdup("");
	if (!*str) 
		exit(EXIT_FAILURE);
}


char	**load_map(int fd, t_params *params)
{
	char	**map;
	char	*gnl;
	char	*str;
	int		flag;

	init_load_map_attrib(&str, &flag);
	gnl = get_next_line(fd);
	check_first_line_is_valid(fd, gnl, str, params);
	while (gnl != NULL)
	{
		if (is_all_config_set(params, &flag, gnl, str))
			exit(EXIT_FAILURE);
		if (init_config(&flag, gnl, str, params))
			exit(EXIT_FAILURE);
		if (flag)
			copy_line(gnl, &str, fd, params);
		free(gnl);
		gnl = get_next_line(fd);
	}
	map = ft_split(str, '\n');
	if (!map || !map[0])
		return (free(str), free_array(map), NULL);
	free(str);
	return (map);
}
