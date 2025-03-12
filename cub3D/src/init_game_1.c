/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:16:31 by ttelolah          #+#    #+#             */
/*   Updated: 2025/03/12 18:33:53 by rhanitra         ###   ########.fr       */
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

static int	handle_first_path(t_params *params, char *gnl, int *i)
{
	char	*tmp;

	if (gnl[*i] == 'N' && gnl[*i + 1] == 'O' && params->path->no == NULL)
	{
		tmp = copy_config(gnl, i);
		if (!tmp)
			return (perror_msg("Allocation Failed on ", params->path->no));
		params->path->no = tmp;
	}
	else if (gnl[*i] == 'N' && gnl[*i + 1] == 'O' && params->path->no != NULL)
		return (perror_msg("Double key", NULL));
	if (gnl[*i] == 'S' && gnl[*i + 1] == 'O' && params->path->so == NULL)
	{
		tmp = copy_config(gnl, i);
		if (!tmp)
			return (perror_msg("Allocation Failed on ", params->path->so));
		params->path->so = tmp;
	}
	else if (gnl[*i] == 'S' && gnl[*i + 1] == 'O' && params->path->so != NULL)
		return (perror_msg("Double key", NULL));
	return (0);
}

static int	handle_second_path(t_params *params, char *gnl, int *i)
{
	char	*tmp;

	if (gnl[*i] == 'W' && gnl[*i + 1] == 'E' && params->path->we == NULL)
	{
		tmp = copy_config(gnl, i);
		if (!tmp)
			return (perror_msg("Allocation Failed on ", params->path->we));
		params->path->we = tmp;
	}
	else if (gnl[*i] == 'W' && gnl[*i + 1] == 'E' && params->path->we != NULL)
		return (perror_msg("Double key", NULL));
	if (gnl[*i] == 'E' && gnl[*i + 1] == 'A' && params->path->ea == NULL)
	{
		tmp = copy_config(gnl, i);
		if (!tmp)
			return (perror_msg("Allocation Failed on ", params->path->ea));
		params->path->ea = tmp;
	}
	else if (gnl[*i] == 'E' && gnl[*i + 1] == 'A' && params->path->ea != NULL)
		return (perror_msg("Double key", NULL));
	return (0);
}

static int	handle_color_config(t_params *params, char *gnl, int *i)
{
	char	*tmp;

	if (gnl[*i] == 'F' && params->path->f == NULL)
	{
		tmp = copy_config(gnl, i);
		if (!tmp)
			return (perror_msg("Allocation Failed on ", params->path->f));
		params->path->f = tmp;
	}
	else if (gnl[*i] == 'F' && params->path->f != NULL)
		return (perror_msg("Double key", NULL));
	if (gnl[*i] == 'C' && params->path->c == NULL)
	{
		tmp = copy_config(gnl, i);
		if (!tmp)
			return (perror_msg("Allocation Failed on ", params->path->c));
		params->path->c = tmp;
	}
	else if (gnl[*i] == 'C' && params->path->c != NULL)
		return (perror_msg("Double key", NULL));
	return (0);
}

int	put_data_config(t_params *params, char *gnl, int *i)
{
	if (!in_base(gnl))
		return (perror_msg("Error on data config: ", NULL));
	if (handle_first_path(params, gnl, i) != 0)
		return (1);
	if (handle_second_path(params, gnl, i) != 0)
		return (1);
	if (handle_color_config(params, gnl, i) != 0)
		return (1);
	return (0);
}
