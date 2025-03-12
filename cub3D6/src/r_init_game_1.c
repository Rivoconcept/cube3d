/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_init_game_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:49:57 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/11 18:26:31 by rhanitra         ###   ########.fr       */
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

int in_base(char *gnl)
{
	int	i;

	i = 0;
	while (ft_is_space(gnl[i]))
		i++;
	return ((gnl[i] == 'N' && gnl[i + 1] == 'O' && gnl[i + 2] == ' ') \
		|| (gnl[i] == 'S' && gnl[i + 1] == 'O' && gnl[i + 2] == ' ') \
		|| (gnl[i] == 'W' && gnl[i + 1] == 'E' && gnl[i + 2] == ' ') \
		|| (gnl[i] == 'E' && gnl[i + 1] == 'A' && gnl[i + 2] == ' ') \
		|| (gnl[i] == 'F' && gnl[i + 1] == ' ' && gnl[i + 1] == ' ') \
		|| (gnl[i] == 'C' && gnl[i + 1] == ' ' && gnl[i + 1] == ' '));
}

int put_data_config(t_params *params, char *gnl, int *i)
{
	if (!in_base(gnl))
		return (perror_msg("Error on data config: ", NULL));
	if (gnl[*i] == 'N' && gnl[*i + 1] == 'O' && params->path->no == NULL)
	{
		if (!(params->path->no = copy_config(gnl, i)))
			return (perror_msg("Allocation Failed on ", params->path->no));
	}
	else if (gnl[*i] == 'N' && gnl[*i + 1] == 'O' && params->path->no != NULL)
		return (perror_msg("Double key", NULL));
	if (gnl[*i] == 'S' && gnl[*i + 1] == 'O' && params->path->so == NULL)
	{
		if (!(params->path->so = copy_config(gnl, i)))
			return (perror_msg("Allocation Failed on ", params->path->so));		
	}
	else if (gnl[*i] == 'S' && gnl[*i + 1] == 'O' && params->path->so != NULL)
		return (perror_msg("Double key", NULL));
	if (gnl[*i] == 'W' && gnl[*i + 1] == 'E' && params->path->we == NULL)
	{
		if (!(params->path->we = copy_config(gnl, i)))
			return (perror_msg("Allocation Failed on ", params->path->we));
	}
	else if (gnl[*i] == 'W' && gnl[*i + 1] == 'E' && params->path->we != NULL)
		return (perror_msg("Double key", NULL));
	if (gnl[*i] == 'E' && gnl[*i + 1] == 'A' && params->path->ea == NULL)
	{
		if (!(params->path->ea = copy_config(gnl, i)))
			return (perror_msg("Allocation Failed on ", params->path->ea));
	}
	else if (gnl[*i] == 'E' && gnl[*i + 1] == 'A' && params->path->ea != NULL)
		return (perror_msg("Double key", NULL));
	if (gnl[*i] == 'F' && params->path->f == NULL)
	{
		if (!(params->path->f = copy_config(gnl, i)))
			return (perror_msg("Allocation Failed on ", params->path->f));
	}
	else if (gnl[*i] == 'F' && params->path->f != NULL)
		return (perror_msg("Double key", NULL));
	if (gnl[*i] == 'C' && params->path->c == NULL)
	{
		if (!(params->path->c  = copy_config(gnl, i)))
			return (perror_msg("Allocation Failed on ", params->path->c));
	}
	else if (gnl[*i] == 'C' && params->path->c != NULL)
		return (perror_msg("Double key", NULL));
	return (0);
}
