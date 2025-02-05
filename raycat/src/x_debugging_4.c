#include "../include/cub3d.h"

/*char get_map_element(t_params *params, int x, int y)
{
    int i;
	int j;
    int col;
    int row;
    t_map *current_map;
	t_line *current_line;

	i = 0;
	col = x / COL_SIZE;
	printf("col :%d\n", col);
    row = y / COL_SIZE;
	printf("row :%d\n", row);
	current_map = params->map;
    while (current_map != NULL)
    {
        if (i == row)
        {
            current_line = current_map->line_value.line;
            j = 0;
            while (current_line != NULL)
            {
                if (j == col)
                    return current_line->cell_value.value;
                current_line = current_line->next;
                j++;
            }
        }
        current_map = current_map->next;
        i++;
    }
    return (' ');
}*/
int get_pos_x(int x)
{
	int	i;
	int	size;
	int	min;
	int	max;

	i = 0;
	size = SCREEN_WIDTH / 64;
	while (i < size)
	{
		min = i * 64;
		max = (i + 1) * 64;

		if (x >= min && x < max)
			return (i);
		i++;
	}
	return (-1);
}

int get_pos_y(int y)
{
	int	i;
	int	size;
	int	min;
	int	max;

	i = 0;
	size = SCREEN_HEIGHT / 64;
	while (i < size)
	{
		min = i * 64; 
		max = (i + 1) * 64;

		if (y >= min && y < max)
			return (i);
		i++;
	}
	return (-1);
}

char	put_element_value(t_params *params, int x, int y)
{
	params->pos->value.x = get_pos_x(x);
	params->pos->value.y = get_pos_y(y);
	printf("x:%d - y:%d + pos_x:%d - pos_y:%d\n", params->player->x, params->player->y, params->pos->value.x, params->pos->value.y);

	printf("%c\n", find_value(params->map, params->pos));
	return (' ');
}


