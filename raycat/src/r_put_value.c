#include "../include/cub3d.h"

char	put_element_value(t_params *params, int x, int y)
{
	params->pos->value.x = get_pos_x(x);
	params->pos->value.y = get_pos_y(y);
	return (find_value(params->map, params->pos));
}


