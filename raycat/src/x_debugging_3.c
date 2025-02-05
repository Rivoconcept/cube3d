#include "../include/cub3d.h"

t_player	*init_player(void)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (player == NULL)
		return (NULL);
	player->init = '\0';
	player->x = 0;
	player->y = 0;
	player->width = 0;
	player->height = 0;
	player->color = 0;
	return (player);
}
void rotate_and_draw(int x, int y, int pivot_x, int pivot_y, double angle, t_params *params)
{
    int new_x;
    int new_y;

    new_x = pivot_x + (x - pivot_x) * cos(angle) - (y - pivot_y) * sin(angle);
    new_y = pivot_y + (x - pivot_x) * sin(angle) + (y - pivot_y) * cos(angle);

    my_mlx_pixel_put(new_x, new_y, params->player->color, params);
}

int draw_player(t_params *params, int x, int y)
{
    int		i;
	int		j;
    int		pivot_x;
	int		pivot_y;
    double	angle;
	
	i = 0;
	angle = params->delta;
    pivot_x = x;
    pivot_y = y;
    while (i++ < 5)
	{
		j = 0;
		while (j++ < i)
		{
			rotate_and_draw(x, y, pivot_x, pivot_y, angle, params);
            rotate_and_draw(x, y + i, pivot_x, pivot_y, angle, params);
            rotate_and_draw(x - j, y + i, pivot_x, pivot_y, angle, params);
            rotate_and_draw(x + j, y + i, pivot_x, pivot_y, angle, params);			
		}
	}
    return (0);
}

void	put_triangle(t_params *params, t_map *map, t_line *line)
{
	if (line->cell_value.value == params->player->init)
	{
		if (params->player->x == 0 && params->player->y == 0)
		{
			params->player->x = (line->cell_value.index * COL_SIZE) + (COL_SIZE / 2);
			params->player->y = (map->line_value.index * COL_SIZE) + (COL_SIZE / 2);
		}
		params->player->width = COL_SIZE;
		params->player->height = COL_SIZE;
		params->player->color = 0xffff3f;
		draw_player(params, params->player->x, params->player->y);
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
