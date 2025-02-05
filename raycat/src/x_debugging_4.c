#include "../include/cub3d.h"

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
	return (find_value(params->map, params->pos));
}


