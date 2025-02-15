/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:08:07 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/04 13:40:41 by rhanitra         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/cub3d.h"

int out_of_play(t_params *params)
{
	int	count;

	count = 0;
	if (count_data_game(params->map, 'N') > 1 \
		|| count_data_game(params->map, 'W') > 1 \
		|| count_data_game(params->map, 'E') > 1 \
		|| count_data_game(params->map, 'S') > 1)
		return (perror_msg("Invalid Number of Player", NULL));
	if (count_data_game(params->map, 'N') == 1)
		count++;
	if (count_data_game(params->map, 'W') == 1)
		count++;
	if (count_data_game(params->map, 'E') == 1)
		count++;
	if (count_data_game(params->map, 'S') == 1)
		count++;
	if (count > 1)
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

