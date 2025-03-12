/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttelolah <ttelolah@student.42antananavo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/04 18:54:39 by ttelolah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static char	north_view(t_params *params, t_moov *moov)
{
	if ((*moov).down == '0' || (*moov).down == params->player->init)
		return ('N');
	if ((*moov).left == '0' || (*moov).left == params->player->init)
		return ('E');
	if ((*moov).right == '0' || (*moov).right == params->player->init)
		return ('W');
	if ((*moov).up == '0' || (*moov).up == params->player->init)
		return ('S');
	return (params->player->init);
}

static char	south_view(t_params *params, t_moov *moov)
{
	if ((*moov).up == '0' || (*moov).up == params->player->init)
		return ('S');
	if ((*moov).right == '0' || (*moov).right == params->player->init)
		return ('W');
	if ((*moov).left == '0' || (*moov).left == params->player->init)
		return ('E');
	if ((*moov).down == '0' || (*moov).down == params->player->init)
		return ('N');
	return (params->player->init);
}

static char	east_view(t_params *params, t_moov *moov)
{
	if ((*moov).left == '0' || (*moov).left == params->player->init)
		return ('E');
	if ((*moov).up == '0' || (*moov).up == params->player->init)
		return ('S');
	if ((*moov).down == '0' || (*moov).down == params->player->init)
		return ('N');
	if ((*moov).right == '0' || (*moov).right == params->player->init)
		return ('W');
	return (params->player->init);
}

static char	west_view(t_params *params, t_moov *moov)
{
	if ((*moov).right == '0' || (*moov).right == params->player->init)
		return ('W');
	if ((*moov).down == '0' || (*moov).down == params->player->init)
		return ('N');
	if ((*moov).up == '0' || (*moov).up == params->player->init)
		return ('S');
	if ((*moov).left == '0' || (*moov).left == params->player->init)
		return ('E');
	return (params->player->init);
}

char	get_type_texture(t_params *params, int x, int y)
{
	t_moov	moov;

	moov.left = putval(params, x - 1, y);
	moov.right = putval(params, x + 1, y);
	moov.up = putval(params, x, y - 1);
	moov.down = putval(params, x, y + 1);
	if (params->player->dir == 'N')
		return (north_view(params, &moov));
	else if (params->player->dir == 'S')
		return (south_view(params, &moov));
	else if (params->player->dir == 'E')
		return (east_view(params, &moov));
	else if (params->player->dir == 'W')
		return (west_view(params, &moov));
	return (params->player->init);
}
