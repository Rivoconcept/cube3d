#include "../include/cub3d.h"

t_rect	*init_rectangle(void)
{
	t_rect	*rect;

	rect = (t_rect *)malloc(sizeof(t_rect));
	if (rect == NULL)
		return (NULL);
	rect->x = 0;
	rect->y = 0;
	rect->width = 0;
	rect->height = 0;
	rect->color = 0;
	return (rect);
}

int draw_rectangle(t_params *params)
{
    int	i;
	int	j;

    if (params->win_open == NULL)
        return (1);
    j = params->rect->x;
    while (j < params->rect->x + params->rect->width)
        mlx_pixel_put(params->mlx_connexion, params->win_open, j++, params->rect->y, params->rect->color);
    j = params->rect->x;
    while (j < params->rect->x + params->rect->width)
        mlx_pixel_put(params->mlx_connexion, params->win_open, j++, params->rect->y + params->rect->height - 1, params->rect->color);
    i = params->rect->y;
    while (i < params->rect->y + params->rect->height)
        mlx_pixel_put(params->mlx_connexion, params->win_open, params->rect->x, i++, params->rect->color);
    i = params->rect->y;
    while (i < params->rect->y + params->rect->height)
        mlx_pixel_put(params->mlx_connexion, params->win_open, params->rect->x + params->rect->width - 1, i++, params->rect->color);

    return (0);
}

void	put_rectangle(t_params *params, t_map *map, t_line *line)
{
	int	height;
	int	width;

	height = count_element_list_mapline(params->map);
	width = count_element_list_mapcol(params->map);
	if (line->cell_value.value == '1' \
		 && map->line_value.index <= height \
		 && line->cell_value.index < width )
	{
		params->rect->x = line->cell_value.index * 64;
		params->rect->y = map->line_value.index * 64;
		params->rect->width = 64;
		params->rect->height = 64;
		params->rect->color = 0xff00b4d8;
		draw_rectangle(params);
	}
}

void	put_wall(t_params *params)
{
	t_map	*current_map;
	t_line	*current_line;

	current_map = params->map;
	while (current_map != NULL)
	{
		current_line = current_map->line_value.line;
		while (current_line != NULL)
		{
			put_rectangle(params, current_map, current_line);
			current_line = current_line->next;
		}
		current_map = current_map->next;
	}
}
