/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_render_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/28 18:03:48 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*char get_type_texture(t_params *params, int x, int y)
{
    if (putval(params, x - 1, y) == '1')
        return ('W');
    if (putval(params, x + 1, y) == '1')
        return ('E');
    if (putval(params, x, y - 1) == '1')
        return ('N');
    if (putval(params, x, y + 1) == '1')
        return ('S');
    return (params->player->init);
}*/

char get_type_texture(t_params *params, int x, int y)
{
    t_moov moov;

    moov.left = putval(params, x - 1, y);
    moov.right = putval(params, x + 1, y);
    moov.up = putval(params, x, y - 1);
    moov.down = putval(params, x, y + 1);
    /*if (x % SLICE_SIZE == 63 && y % SLICE_SIZE == 63 && moov.right == '1')
    {
        // if ((x + 1) % SLICE_SIZE == 0 && ((y + 1) % SLICE_SIZE == 0))
        //     printf("oui\n");
        return ('N');
    }*/
    if (moov.up == '1')
        return ('N');
    if (moov.left == '1')
        return ('W');
    if (moov.right == '1')
        return ('E');
    if (moov.down == '1')
        return ('S');
    return (params->player->init);
}


t_img	*get_wall_texture(t_params *params, char wall_dir)
{
    if (wall_dir == 'N')
    {
        params->NO->wall_path = wall_dir;
        return (params->NO);
    }
    if (wall_dir == 'S')
    {
        params->SO->wall_path = wall_dir;
        return (params->SO);
    }
    if (wall_dir == 'E')
    {
        params->EA->wall_path = wall_dir;
        return (params->EA);
    }
    if (wall_dir == 'W')
    {
        params->WE->wall_path = wall_dir;
        return (params->WE);
    }
    return (NULL);
}


int get_wall_height(float distance)
{
    float dpp;
    int wall_height;

    dpp = (SCREEN_WIDTH / 2.0) / tan(FOV / 2.0);
    wall_height = (int)((SLICE_SIZE * dpp) / (distance));
    return (wall_height);
}

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
	while (put_map_value(params, (int)rx, (int)ry) != '1')
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

int get_texture_pixel(t_img *texture, int x, int y)
{
    char    *dst;

    if (!texture || x < 0 || y < 0 || x >= texture->width || y >= texture->height)
        return (0x000000);
    dst = texture->data + (y * texture->line_len + x * (texture->bpp / 8));
    return (*(unsigned int *)dst);
}

void draw_wall_slice(t_params *params, t_img *wall, int x)
{
    int     y;
    int     wall_height;
    float     tex_x;
    float     tex_y;
    int     start;
    int     end;
    float   val;
    int     color;

    wall_height = get_wall_height(wall->distance);
    start = (SCREEN_HEIGHT / 2) - (wall_height / 2);
    end = start + wall_height;      
    y = start;
    if (wall->wall_path == 'N' || wall->wall_path == 'S')
        tex_x = ((int)wall->wx % SLICE_SIZE);
    else if (wall->wall_path == 'E' || wall->wall_path == 'W')
        tex_x = ((int)wall->wy % SLICE_SIZE);
    val = tex_x / SLICE_SIZE;
    while (y < end)
    {
        tex_y = ((y - start) * wall->height) / wall_height;
        color = get_texture_pixel(wall, val * wall->width, tex_y);
        /*if (wall->wall_path == 'N')
            color = 0x00FF00;
        if (wall->wall_path == 'S')
            color = 0xFF0000;
        if (wall->wall_path == 'W')
            color = 0x0000FF;
        if (wall->wall_path == 'E')
            color = 0x00FFFF;*/

        my_mlx_pixel_put(x, y, color, params);
        y++;
    }
}

void render_scene(t_params *params)
{
    int     x;
    float   step;
    float   angle;
    t_img   *wall;

    x = 0;
    step = FOV / SCREEN_WIDTH;
    wall = params->texture;
    angle = params->delta - (FOV / 2);
    while (x < SCREEN_WIDTH)
    {
        get_distance(params, &wall, angle);
        wall->distance *= cos(angle - params->delta);
        draw_wall_slice(params, wall, x);
        angle += step; 
        x++;
    }
}


/*void render_scene(t_params *params)
{
    int     x;
    float   step;
    float   angle;
    float   normalized_angle;
    t_img   *wall;

    x = 0;
    step = FOV / SCREEN_WIDTH;
    wall = params->texture;
    angle = params->delta - (FOV / 2);

    while (x < SCREEN_WIDTH)
    {
        get_distance(params, &wall, angle);
        wall->distance *= cos(angle - params->delta);

        normalized_angle = fmod(angle, 2 * PI);
        if (normalized_angle < 0)
            normalized_angle += 2 * PI;

        if (normalized_angle >= PI / 4 && normalized_angle < 3 * PI / 4)
            wall = get_wall_texture(params, 'N');
        else if (normalized_angle >= 3 * PI / 4 && normalized_angle < 5 * PI / 4)
            wall = get_wall_texture(params, 'W');
        else if (normalized_angle >= 5 * PI / 4 && normalized_angle < 7 * PI / 4)
            wall = get_wall_texture(params, 'S');
        else
            wall = get_wall_texture(params, 'E'); 

        draw_wall_slice(params, wall, x);
        angle += step;
        x++;
    }
}*/



/*void render_scene(t_params *params)
{
    int     x;
    float   step;
    float   angle;
    t_img   *wall;
    char    w;
    char    last_wall[9] = {0};
    int     token = 0;
    int     trigger = 0;
    int     i = 0;
    int col = 0;
    // int     j = 0;

    x = 0;
    step = FOV / SCREEN_WIDTH;
    wall = params->texture;
    angle = params->delta - (FOV / 2);

    while (x < SCREEN_WIDTH)
    {
        get_distance(params, &wall, angle);
        wall->distance *= cos(angle - params->delta);
        if (!token && !trigger)
        {
            w = wall->wall_path;
            token = 1;
        }
        // printf("w:%c lw:%c\n", w, wall->wall_path);
        if (token && w != wall->wall_path)
        {
            trigger = 1;
            col = x;
        }
        if (trigger)
            last_wall[i++] = wall->wall_path;
        if (trigger && i == 9 && last_wall[7] != last_wall[8])
        {
            wall = get_wall_texture(params, w);
            while (col++ <= x)
                draw_wall_slice(params, wall, col);
            token = 0;
            trigger = 0;
        }
        else if (trigger && i == 9 && last_wall[7] == last_wall[8])
        {
            token = 0;
            trigger = 0;
            i = 0;
        }
        // printf("1:%c 2:%c 3:%c\n", test[0], test[1], test[2]);
        draw_wall_slice(params, wall, x);
        angle += step; 
        x++;
    }
}*/

/*void render_scene(t_params *params)
{
    int     x;
    float   step;
    float   angle;
    t_img   *wall;
    char    w;
    char    last_wall[10] = {0};
    int     token = 0;
    int     trigger = 0;
    int     i = -1;
    int distance;
    float old_angle;
    
    x = 0;
    step = FOV / SCREEN_WIDTH;
    wall = params->texture;
    angle = params->delta - (FOV / 2);

    while (x < SCREEN_WIDTH)
    {
        get_distance(params, &wall, angle);
        wall->distance *= cos(angle - params->delta);
        if (!token && !trigger)
        {
            w = wall->wall_path;
            token = 1;
        }
        if (token && w != wall->wall_path)
            trigger = 1;
           
        if (trigger && i < 10)
        {
            if (trigger && i < 10)
            {
                last_wall[i++] = wall->wall_path;
                // printf("%c\n", last_wall[i]);
            }
        }
        if (trigger && i > 8)
        {
            distance = wall->distance;
            // printf("%c - %c\n", last_wall[8], last_wall[9]);
            if (last_wall[8] != last_wall[9]) 
            {
                int col = x;
                int i = 0;
                wall->wall_path = w;
                wall->distance = distance;
                old_angle = angle;
                while (col - i && i < 10)
                {
                    draw_wall_slice(params, wall, col);
                    angle -= step; 
                    i++;
                }
                token = 0;
                trigger = 0;
                i = -1;
                angle = old_angle;
            }
        }
        draw_wall_slice(params, wall, x);
        angle += step; 
        x++;
    }
}*/
