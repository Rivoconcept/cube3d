/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_render_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/21 17:00:23 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/cub3d.h"


float	get_distance(t_params *params, t_img *texture, float angle, char *wall_dir)
{
	float	rx;
	float	ry;
	float	dir_x;
	float	dir_y;
	float	step;
	float	distance;

	step = 1.0;
	distance = 0.0;
	rx = params->player->x;
	ry = params->player->y;
	modulo_angle(&angle);
	dir_x = sin(angle) * step;
	dir_y = -cos(angle) * step;
	while (distance < SCREEN_WIDTH && put_map_value(params, (int)rx, (int)ry) != '1')
	{
		rx += dir_x;
		ry += dir_y;
		distance += step;
	}
    *wall_dir = get_type_texture(params, rx, ry);
    texture->rx = rx;
    texture->ry = ry;
	return (distance);
}


void draw_wall_slice(t_params *params, t_img *texture, int x, char wall_dir)
{
    int     y;
    int     wall_height;
    int     tex_x;
    int     tex_y;
    int     color;
    t_img  *wall_texture;

    wall_height = get_wall_height(texture->distance);
    wall_texture = get_wall_texture(params, wall_dir);
    if (!wall_texture)
        return ;

    // Choix de tex_x en fonction de la direction du mur
    if (wall_dir == 'N' || wall_dir == 'S') // Mur Nord ou Sud
        tex_x = (int)((texture->rx - floor(texture->rx)) * wall_texture->width);
    else // Mur Est ou Ouest
        tex_x = (int)((texture->ry - floor(texture->ry)) * wall_texture->width);

    y = 0;
    while (y < wall_height)
    {
        tex_y = (y * wall_texture->height) / wall_height;
        color = get_texture_pixel(wall_texture, tex_x, tex_y);
        my_mlx_pixel_put(x, (SCREEN_HEIGHT / 2 - wall_height / 2) + y, color, params);
        y++;
    }
}


void render_scene(t_params *params)
{
    int     x;
    float   angle;
    float   distance;
    char    wall_dir;
    t_img   tmp_texture;

    x = 0;
    // tmp_texture = {0;
    angle = params->delta - (FOV / 2);
    while (x < SCREEN_WIDTH)
    {
        distance = get_distance(params, &tmp_texture, angle, &wall_dir);
        distance *= cos(angle - params->delta);
        tmp_texture.distance = distance;
        draw_wall_slice(params, &tmp_texture, x, wall_dir);
        angle += FOV / SCREEN_WIDTH; 
        x++;
    }
}

/************************************************************************************ */

void	get_distance(t_params *params, t_img **wall, float angle)
{
	float	rx;
	float	ry;
	float	dir_x;
	float	dir_y;
	float	distance;
    char    wall_path;

	distance = 0.0;
	rx = params->player->x;
	ry = params->player->y;
	modulo_angle(&angle);
	dir_x = sin(angle) * STEP_CAST;
	dir_y = -cos(angle) * STEP_CAST;
	while (distance < SCREEN_WIDTH && put_map_value(params, (int)rx, (int)ry) != '1')
	{
		rx += dir_x;
		ry += dir_y;
		distance += STEP_CAST;
	}
    wall_path = get_type_texture(params, rx, ry);
    (*wall) =  get_wall_texture(params, wall_path);
    (*wall)->wx = rx;
    (*wall)->wy = ry;
    (*wall)->distance = distance;
}

void draw_wall_slice(t_params *params, t_img *wall, int x)
{
    t_img  *texture;
    int     y;
    int     wall_height;
    int     tex_x;
    int     tex_y;
    int     color;

    wall_height = get_wall_height(wall->distance);
    texture = get_wall_texture(params, wall->wall_path);
    if (!texture)
        return ;
    y = 0;
    if (wall->wall_path == 'N' || wall->wall_path == 'S')
        tex_x = (int)((texture->wx - floor(texture->wx)) * texture->width);
    else if (wall->wall_path == 'E' || wall->wall_path == 'W')
        tex_x = (int)((texture->wy - floor(texture->wy)) * texture->width);
    //tex_x = (x % texture->width);
    while (y < wall_height)
    {
        tex_y = (y * texture->height) / wall_height;
        color = get_texture_pixel(texture, tex_x, tex_y);
        my_mlx_pixel_put(x, (SCREEN_HEIGHT / 2 - wall_height / 2) + y, color, params);
        y++;
    }
}

void render_scene(t_params *params)
{
    int     x;
    float   angle;
    t_img   *wall;

    x = 0;
    wall = init_list_img();
    angle = params->delta - (FOV / 2);
    while (x < SCREEN_WIDTH)
    {
        get_distance(params, &wall, angle);
        wall->distance *= cos(angle - params->delta);
        draw_wall_slice(params, wall, x);
        angle += FOV / SCREEN_WIDTH; 
        x++;
    }
    free(wall);
}





