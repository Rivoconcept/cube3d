#include "../include/cub3d.h"

void draw_square(t_params *params)
{
	int	i = 0;

	while (i < 64)
	{
		pixel_render(params);
		i++;
	}
	int	j = 0;
	while (j < 64)
	{
		pixel_render(params);
		j++;
	}
	int	k = 0;
	while (k < 64)
	{
		pixel_render(params);
		k++;
	}
	int	l = 0;
	while (l < 64)
	{
		pixel_render(params);
		l++;
	}
}