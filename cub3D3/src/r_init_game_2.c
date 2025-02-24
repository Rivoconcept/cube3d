/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_init_game_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:49:57 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/24 17:30:24 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_config(int *flag, char *gnl, char *str, t_params *params)
{
	int	i;

	i = 0;
	if (!*flag && !is_only_space(gnl))
	{
		while (ft_is_space(gnl[i]))
			i++;
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

void copy_line(char *gnl, char **str, int fd, t_params *params)
{
	char *tmp;

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

char **load_map(int fd, t_params *params)
{
    char	**map;
	char    *str;
    char    *gnl;
    int     flag;

    str = ft_strdup("");
    if (!str)
        return (NULL);
    flag = 0;
	gnl = get_next_line(fd);
	while (gnl != NULL)
	{
        is_all_config_set(params, &flag, gnl);
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

void	init_player(t_params *params)
{
	int			i;
	int			j;

	i = 0;
	while (params->map[i] != NULL)
	{
		j = 0;
		while (params->map[i][j] != '\0')
		{
			if (params->map[i][j] == params->player->init)
			{
				if (params->player->x == 0 && params->player->y == 0)
				{
					params->player->x = (j * SLICE_SIZE)
						+ (SLICE_SIZE / 2);
					params->player->y = (i * SLICE_SIZE) + (SLICE_SIZE / 2);
				}
			}
			j++;
		}
		i++;
	}
}
