#include "examshell.h"

void print_argv(char **argv)
{
    int i = 0;
    while (argv[i] != NULL)
    {
        printf("%s\n", argv[i]);
        i++;
    }

}

void free_list_cmd(t_cmd *command)
{
    t_cmd *temp;

    while (command)
    {
        temp = command;
        free_array(temp->cmd);
        command = command->next;
        free(temp);
    }
}


void free_array(char **arr)
{
    int i = 0;
    if (!arr)
        return;
    while (arr[i] != NULL)
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

