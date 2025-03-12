/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttelolah <ttelolah@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:49:34 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/08 15:20:11 by ttelolah         ###   ########.fr       */
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

void	init_moov(t_params *params, t_moov *moov, int x, int y)
{
	moov->real = putval(params, x, y);
	moov->up = putval(params, x, y - 1);
	moov->right = putval(params, x + 1, y);
	moov->down = putval(params, x, y + 1);
	moov->left = putval(params, x - 1, y);
	moov->ul = putval(params, x - 1, y - 1);
	moov->ur = putval(params, x + 1, y - 1);
	moov->dr = putval(params, x + 1, y + 1);
	moov->dl = putval(params, x - 1, y + 1);
}

char	put_map_value(t_params *params, int x, int y)
{
	t_moov	moov;

	init_moov(params, &moov, x, y);
	if ((moov.real == '0' || moov.real == params->player->init) \
		&& ((moov.ul == ' ' || moov.ul == '\0') \
		|| (moov.ur == ' ' || moov.ur == '\0') \
		|| (moov.dr == ' ' || moov.dr == '\0') \
		|| (moov.dl == ' ' || moov.dl == '\0')))
		return ('1');
	if (moov.real == '0' \
		&& ((moov.down == '1' && moov.right == '1' && moov.ul == '0') \
		|| (moov.up == '1' && moov.left == '1' && moov.ur == '0') \
		|| (moov.up == '1' && moov.right == '1' && moov.dr == '0') \
		|| (moov.down == '1' && moov.left == '1' && moov.dl == '0')))
		return ('1');
	if (moov.real == '0' && ((moov.down == '1' && moov.right == '1') \
		|| (moov.up == '1' && moov.left == '1') \
		|| (moov.up == '1' && moov.right == '1') \
		|| (moov.down == '1' && moov.left == '1')))
		return ('1');
	return (moov.real);
}
