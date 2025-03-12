/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttelolah <ttelolah@student.42antananavo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:16:31 by ttelolah          #+#    #+#             */
/*   Updated: 2025/03/04 18:34:29 by ttelolah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*copy_config(char *gnl, int *i)
{
	int		j;
	int		size;
	char	*config;

	j = 0;
	size = 0;
	while (ft_isalpha(gnl[*i]))
		(*i)++;
	while (ft_is_space(gnl[*i]))
		(*i)++;
	size = (int)ft_strlen(gnl) - *i;
	config = (char *)malloc(sizeof(char) * (size + 1));
	if (!config)
	{
		perror("Failed to allocate memory for config");
		exit(EXIT_FAILURE);
	}
	while (gnl[*i] && gnl[*i] != '\0' && gnl[*i] != '\n')
	{
		config[j] = gnl[*i];
		j++;
		(*i)++;
	}
	config[j] = '\0';
	return (config);
}

int	in_base(char *gnl)
{
	int	i;

	i = 0;
	while (ft_is_space(gnl[i]))
		i++;
	return ((gnl[i] == 'N' && gnl[i + 1] == 'O' && gnl[i + 2] == ' ')
		|| (gnl[i] == 'S' && gnl[i + 1] == 'O' && gnl[i + 2] == ' ')
		|| (gnl[i] == 'W' && gnl[i + 1] == 'E' && gnl[i + 2] == ' ')
		|| (gnl[i] == 'E' && gnl[i + 1] == 'A' && gnl[i + 2] == ' ')
		|| (gnl[i] == 'F' && gnl[i + 1] == ' ' && gnl[i + 1] == ' ')
		|| (gnl[i] == 'C' && gnl[i + 1] == ' ' && gnl[i + 1] == ' '));
}

static int	handle_cardinal_config(t_params *params, char *gnl, int *i)
{
	char	*tmp;

	if (gnl[*i] == 'N' && gnl[*i + 1] == 'O')
	{
		tmp = copy_config(gnl, i);
		if (!tmp)
			return (perror_msg("Allocation Failed on ", NULL));
		params->path->no = tmp;
	}
	if (gnl[*i] == 'S' && gnl[*i + 1] == 'O')
	{
		tmp = copy_config(gnl, i);
		if (!tmp)
			return (perror_msg("Allocation Failed on ", NULL));
		params->path->so = tmp;
	}
	if (gnl[*i] == 'W' && gnl[*i + 1] == 'E')
	{
		tmp = copy_config(gnl, i);
		if (!tmp)
			return (perror_msg("Allocation Failed on ", NULL));
		params->path->we = tmp;
	}
	return (0);
}

static int	handle_color_config(t_params *params, char *gnl, int *i)
{
	char	*tmp;

	if (gnl[*i] == 'E' && gnl[*i + 1] == 'A')
	{
		tmp = copy_config(gnl, i);
		if (!tmp)
			return (perror_msg("Allocation Failed on ", NULL));
		params->path->ea = tmp;
	}
	if (gnl[*i] == 'F')
	{
		tmp = copy_config(gnl, i);
		if (!tmp)
			return (perror_msg("Allocation Failed on ", NULL));
		params->path->f = tmp;
	}
	if (gnl[*i] == 'C')
	{
		tmp = copy_config(gnl, i);
		if (!tmp)
			return (perror_msg("Allocation Failed on ", NULL));
		params->path->c = tmp;
	}
	return (0);
}

int	put_data_config(t_params *params, char *gnl, int *i)
{
	if (!in_base(gnl))
		return (perror_msg("Error on data config: ", NULL));
	if (handle_cardinal_config(params, gnl, i) != 0)
		return (1);
	if (handle_color_config(params, gnl, i) != 0)
		return (1);
	return (0);
}
