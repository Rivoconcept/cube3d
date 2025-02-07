/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_utils_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:48:23 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/07 15:14:44 by rhanitra         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/cub3d.h"

int get_pos_x(int x)
{
	int	i;
	int	size;
	int	min;
	int	max;

	i = 0;
	size = SCREEN_WIDTH / 64;
	while (i < size)
	{
		min = i * 64;
		max = (i + 1) * 64;

		if (x >= min && x < max)
			return (i);
		i++;
	}
	return (-1);
}

int get_pos_y(int y)
{
	int	i;
	int	size;
	int	min;
	int	max;

	i = 0;
	size = SCREEN_HEIGHT / 64;
	while (i < size)
	{
		min = i * 64; 
		max = (i + 1) * 64;

		if (y >= min && y < max)
			return (i);
		i++;
	}
	return (-1);
}
