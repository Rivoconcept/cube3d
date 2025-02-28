/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_search.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:49:34 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/28 17:09:04 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	find_value(t_params *params)
{
	int			i;
	int			j;

	i = 0;
	while (params->map[i] != NULL)
	{
		if (i == params->pos->value.y)
		{
			j = 0;
			while (params->map[i][j] != '\0')
			{
				if (j == params->pos->value.x)
					return (params->map[i][j]);
				j++;
			}
		}
		i++;
	}
	return ('\0');
}

char	putval(t_params *params, int x, int y)
{
	params->pos->value.x = get_pos_x(x, params);
	params->pos->value.y = get_pos_y(y, params);
	return (find_value(params));
}

char put_map_value(t_params *params, int x, int y)
{
	t_moov moov;

    moov.real = putval(params, x, y);
	if (moov.real == '1')
		return ('1');
    moov.left = putval(params, x - 1, y);
    moov.right = putval(params, x + 1, y);
    moov.up = putval(params, x, y - 1);
    moov.down = putval(params, x, y + 1);

	// if (x)
    if (moov.left == '1' || moov.right == '1' || moov.up == '1' || moov.down == '1')
        return '1';
    return (moov.real);
}
