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
	player->key_up = false;
	player->key_down = false;
	player->key_left = false;
	player->key_right = false;
	return (player);
}


int draw_player(t_params *params)
{
    int	i;
	int j;
	int x;
    int y;

    i = 0;
	x = params->player->x + (params->rect->width / 2);
    y = params->player->y + (params->rect->height / 2);
	my_mlx_pixel_put(x, y, params->player->color, params);
	while (i < 5)
	{
		j = 0;
		my_mlx_pixel_put(x, y + i, params->player->color, params);
		while (j <= i)
		{
			my_mlx_pixel_put(x - j, y +  i, params->player->color, params);
			my_mlx_pixel_put(x + j, y +  i, params->player->color, params);
			j++;
		}
		i++;
	}
    return (0);
}

void	put_triangle(t_params *params, t_map *map, t_line *line)
{
	if (line->cell_value.value == params->init)
	{
		if (params->player->x == 0 && params->player->y == 0)
		{
			params->player->x = line->cell_value.index * 64;
			params->player->y = map->line_value.index * 64;
		}
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
