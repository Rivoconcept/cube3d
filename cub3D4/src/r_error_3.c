/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_error_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:50:23 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/16 18:33:41 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	count_data_game(t_params *params, char c)
{
	int			i;
	int			j;
	int			count;

	i = 0;
	count = 0;
	while (params->map[i] != NULL)
	{
		j = 0;
		while (params->map[i][j] != '\0')
		{
			if (params->map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_intrus_data(t_params *params)
{
	int			i;
	int			j;
	char		data;

	i = 0;
	data = '0';
	while (params->map[i] != NULL)
	{
		j = 0;
		while (params->map[i][j] != '\0')
		{
			data = params->map[i][j];
			if (data != 'N' && data != 'S' && data != 'E' && data != 'W' \
				&& data != 49 && data != 10 && data != 48 && data != 32)
				return (perror_msg("Invalid data entry in map", NULL));
			if ( data == 'N' || data == 'W' || data == 'E' || data == 'S')
				params->player->init = data;
			j++;
		}
		i++;
	}
	return (0);
}

