#include "../include/cub3d.h"

t_player	*init_player(void)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (player == NULL)
		return (NULL);
	player->x = 0;
	player->y = 0;
	player->width = 0;
	player->height = 0;
	player->color = 0;
	return (player);
}

int draw_player(t_params *params)
{
    int x, y;
    int center_x, top_y;
    int half_width;
    
    if (params->win_open == NULL)
        return (1);

    int triangle_width = params->rect->width / 5;
    int triangle_height = params->rect->height / 5;

    center_x = params->player->x + (params->rect->width / 2);
    top_y = params->player->y + (params->rect->height / 2) - (triangle_height / 2);
    half_width = triangle_width / 3;
	y = 0;
    while ( y++ < triangle_height)
	{
		int start_x = center_x - (y * half_width / triangle_height);
        int end_x = center_x + (y * half_width / triangle_height);
		x = start_x;
		while (x++ <= end_x)
            mlx_pixel_put(params->mlx_connexion, params->win_open, x, top_y + y, params->player->color);
	}
    return (0);
}


void	put_triangle(t_params *params, t_map *map, t_line *line)
{
	int	height;
	int	width;

	height = count_element_list_mapline(params->map);
	width = count_element_list_mapcol(params->map);
	if (line->cell_value.value == 'N' \
		 && map->line_value.index <= height \
		 && line->cell_value.index < width )
	{
		params->player->x = line->cell_value.index * 64;
		params->player->y = map->line_value.index * 64;
		params->player->width = 64;
		params->player->height = 64;
		params->player->color = 0xffff3f;
		draw_player(params);
	}
}

void	put_player(t_params *params)
{
	t_map	*current_map;
	t_line	*current_line;

	current_map = params->map;
	while (current_map != NULL)
	{
		current_line = current_map->line_value.line;
		while (current_line != NULL)
		{
			put_triangle(params, current_map, current_line);
			current_line = current_line->next;
		}
		current_map = current_map->next;
	}
}
