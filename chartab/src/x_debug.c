#include "../include/cub3d.h"

void print_config(t_params *params)
{
    printf("no: %s\n", params->no);
    printf("so: %s\n", params->so);
    printf("we: %s\n", params->we);
    printf("ea: %s\n", params->ea);
    printf("f: %s\n", params->f);
    printf("c: %s\n", params->c);
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

