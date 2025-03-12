/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_error_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:08:07 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/11 18:53:24 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int is_map_line(char *str)
{
	int i;

	if (!str || str[0] == '\n')
		return (0);
	i = 0;
	while (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W' 
		|| str[i] == '1' || str[i] == '0' || str[i] == ' ')
		i++;
	if (str[i] == '\0' || str[i] == '\n')
		return (1);
	return (0);
}

int out_of_play(t_params *params)
{
	int	count;

	count = 0;
	if (count_data_game(params, 'N') > 1 \
		|| count_data_game(params, 'W') > 1 \
		|| count_data_game(params, 'E') > 1 \
		|| count_data_game(params, 'S') > 1)
		return (perror_msg("Invalid Number of Player", NULL));
	if (count_data_game(params, 'N') == 1)
		count++;
	if (count_data_game(params, 'W') == 1)
		count++;
	if (count_data_game(params, 'E') == 1)
		count++;
	if (count_data_game(params, 'S') == 1)
		count++;
	if (count > 1 || count == 0)
		return (perror_msg("Invalid Number of Player", NULL));
	return (0);
}

int	check_error(int fd, t_params *params)
{
	if (check_error_config(params))
		return (close(fd), cleanup(params), 1);
	if (check_intrus_data(params))
		return (close(fd), cleanup(params), 1);
	if (check_map(params))
		return (close(fd), cleanup(params), 1);
	if (out_of_play(params))
		return (close(fd), cleanup(params), 1);
	return (0);
}

