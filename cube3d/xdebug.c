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

void    print_line(t_line *line)
{
    while(line != NULL)
    {
        printf("%c", line->cell_value.value);
        line = line->next;
    }
}

void    print_map(t_params *params)
{
    t_map *current;
    t_line *line;

    current = params->map;
    while(current != NULL)
    {
        line = current->line_value.line;
        while(line != NULL)
        {
            printf("%c", line->cell_value.value);
            line = line->next;
        }
        current = current->next;
    }
}
