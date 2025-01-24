#include "../include/cub3d.h"

void print_config(t_params *params)
{
    printf("no: %s", params->no);
    printf("so: %s", params->so);
    printf("we: %s", params->we);
    printf("ea: %s", params->ea);
    printf("f: %s", params->f);
    printf("c: %s", params->c);
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
