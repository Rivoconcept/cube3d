/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:44:10 by rhanitra          #+#    #+#             */
/*   Updated: 2024/12/10 10:36:11 by rhanitra         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "examshell.h"

int put_size(char **argv, int i)
{
    int count = 0;
    while (argv[i + count])
    {
        if (argv[i + count] == NULL || strcmp(argv[i + count], "|") == 0 || strcmp(argv[i + count], ";") == 0)
            break;
        count++;
    }
    return (count);
}

t_cmd *init_command(char **argv)
{
    t_cmd *cmd = NULL;
    char **temp = NULL;
    int i = 0, j = 0, size = 0;

    while (argv[i] != NULL)
    {
        if (!size && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
        {
            size = put_size(argv, i);
            temp = malloc(sizeof(char *) * (size + 1));
            if (!temp)
                return (free_list_cmd(cmd), perror("malloc"), NULL);
            j = 0;
        }
        if (strcmp(argv[i], "|") == 0 || strcmp(argv[i], ";") == 0)
        {
            if (temp)
            {
                temp[j] = NULL;
                cmd = add_command(cmd, temp);
                temp = NULL;
                size = 0;
            }
            temp = malloc(sizeof(char *) * 2);
            if (!temp)
                return (free_list_cmd(cmd), perror("malloc"), NULL);
            temp[0] = strdup(argv[i]);
            temp[1] = NULL;
            cmd = add_command(cmd, temp);
            temp = NULL;
            size = 0;
        }
        else
        {
            temp[j++] = strdup(argv[i]);
            if (!argv[i + 1])
            {
                temp[j] = NULL;
                cmd = add_command(cmd, temp);
                temp = NULL;
            }
        }
        i++;
    }
    return (cmd);
}

void print_list(t_cmd *command)
{
    int i;
    int list_num = 1;

    while (command)
    {
        printf("Liste%d: ", list_num++);
        i = 0;
        while (command->cmd[i])
        {
            printf("%s ", command->cmd[i]);
            i++;
        }
        printf("\n");
        command = command->next;
    }
}

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
    char *input = NULL;
    t_cmd *command = NULL;

    while (1)
    {
        input = readline("$> ");
        if (!input || ft_strcmp(input, "exit") == 0) {
            free(input);
            break;
        }
        char **parsed = parse_command(input);
        del_quotes(parsed);
        command = init_command(parsed);
        exec_cmd(command, envp);
        free(input);
        free_array(parsed);
        free_list_cmd(command);
    }
    return 0;
}