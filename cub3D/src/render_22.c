/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_22.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttelolah <ttelolah@student.42antananavo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/04 21:55:53 by ttelolah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_img	*get_wall_texture(t_params *params, char wall_dir)
{
	if (wall_dir == 'N')
	{
		params->no->wall_path = wall_dir;
		return (params->no);
	}
	if (wall_dir == 'S')
	{
		params->so->wall_path = wall_dir;
		return (params->so);
	}
	if (wall_dir == 'E')
	{
		params->ea->wall_path = wall_dir;
		return (params->ea);
	}
	if (wall_dir == 'W')
	{
		params->we->wall_path = wall_dir;
		return (params->we);
	}
	return (NULL);
}

int	get_wall_height(float distance)
{
	float	dpp;
	int		wall_height;

	dpp = (SCREEN_WIDTH / 2.0) / tan(FOV / 2.0);
	wall_height = (int)((SLICE_SIZE * dpp) / (distance));
	return (wall_height);
}

void	get_distance(t_params *params, t_img **wall, float angle)
{
	t_raycast	ray;

	ray.distance = 0.0;
	ray.rx = params->player->x;
	ray.ry = params->player->y;
	modulo_angle(&angle);
	ray.dir_x = sin(angle) * STEP_CAST;
	ray.dir_y = -cos(angle) * STEP_CAST;
	while (1)
	{
		ray.rx += ray.dir_x;
		ray.ry += ray.dir_y;
		ray.distance += STEP_CAST;
		if (put_map_value(params, ceil(ray.rx), ceil(ray.ry)) == '1')
			break ;
	}
	ray.wall_path = get_type_texture(params, ceil(ray.rx), ceil(ray.ry));
	*wall = get_wall_texture(params, ray.wall_path);
	(*wall)->wx = ceil(ray.rx) + 1;
	(*wall)->wy = ceil(ray.ry) + 1;
	(*wall)->distance = ray.distance;
}

int	get_texture_pixel(t_img *texture, int x, int y)
{
	char	*dst;

	if (!texture || x < 0 || y < 0 || x \
		>= texture->width || y >= texture->height)
		return (0x000000);
	dst = texture->data + (y * \
		texture->line_len + x * (texture->bpp / 8));
	return (*(unsigned int *)dst);
}

void	draw_wall_slice(t_params *params, t_img *wall, int x)
{
	t_wall_draw	d;

	d.wall_height = get_wall_height(wall->distance);
	d.start = (SCREEN_HEIGHT / 2) - (d.wall_height / 2);
	d.end = d.start + d.wall_height;
	d.y = d.start;
	d.tex_x = 0;
	if (wall->wall_path == 'N' || wall->wall_path == 'S')
		d.tex_x = wall->wx % SLICE_SIZE;
	else if (wall->wall_path == 'E' || wall->wall_path == 'W')
		d.tex_x = wall->wy % SLICE_SIZE;
	d.val = d.tex_x / SLICE_SIZE;
	while (d.y < d.end)
	{
		d.tex_y = ((d.y - d.start) * wall->height) / d.wall_height;
		d.color = get_texture_pixel(wall, d.val * wall->width, d.tex_y);
		my_mlx_pixel_put(x, d.y, d.color, params);
		d.y++;
	}
}
