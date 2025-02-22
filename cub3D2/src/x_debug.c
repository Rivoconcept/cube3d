#include "../include/cub3d.h"

void print_config(t_params *params)
{
    printf("no: %s\n", params->path->no);
    printf("so: %s\n", params->path->so);
    printf("we: %s\n", params->path->we);
    printf("ea: %s\n", params->path->ea);
    printf("f: %s\n", params->path->f);
    printf("c: %s\n", params->path->c);
}

void print_map(char **map)
{
    int i = 0;
    while (map[i] != NULL)
    {
        printf("%s\n", map[i]);
        i++;
    }
}

// valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./cub3D ./maps/a.cub