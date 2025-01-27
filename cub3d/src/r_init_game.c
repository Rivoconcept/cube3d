/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_init_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:07:54 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/27 21:35:04 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	initialize_line(t_line **head, char *gnl)
{
	int		i;
	t_line	*current;
	t_line	*new_element;

	i = 0;
	new_element = NULL;
	while (gnl[i] != '\0')
	{
		new_element = create_list_line(gnl[i]);
		if (new_element == NULL)
			return ;
		if (*head == NULL)
			*head = new_element;
		else
		{
			current = *head;
			while (current->next != NULL)
				current = current->next;
			current->next = new_element;
		}
		i++;
	}
	put_ranks_line(head);
}

void	initialize_map(t_map **head, t_line *line)
{
	t_map	*current;
	t_map	*new_element;

	new_element = create_list_map(line);
	if (!new_element)
		return ;
	if (*head == NULL)
		*head = new_element;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_element;
	}
	put_ranks_map(head);
}

char	*copy_config(char *gnl, int *i)
{
	int		j;
	int		size;
	char	*config;

	j = 0;
	size = 0;
	while (ft_isalpha(gnl[*i]))
		(*i)++;
	while (ft_is_space(gnl[*i]))
		(*i)++;
	size = (int)ft_strlen(gnl) - *i;
	config = (char *)malloc(sizeof(char) * (size + 1));
	if (!config)
    {
        perror("Failed to allocate memory for config");
        exit(EXIT_FAILURE);
    }
	while (gnl[*i] && gnl[*i] != '\0' && gnl[*i] != '\n')
	{
		config[j] = gnl[*i];
		j++;
		(*i)++;
	}
	config[j] = '\0';
	return (config);
}

int put_data_config(t_params *params, char *gnl, int *i)
{
	if (gnl[*i] == 'N' && gnl[*i + 1] == 'O')
	{
		if (!(params->no = copy_config(gnl, i)))
			return (perror_msg("Allocation Failed on ", params->no));
	}
	else if (gnl[*i] == 'S' && gnl[*i + 1] == 'O')
	{
		if (!(params->so = copy_config(gnl, i)))
			return (perror_msg("Allocation Failed on ", params->so));		
	}
	else if (gnl[*i] == 'W' && gnl[*i + 1] == 'E')
	{
		if (!(params->we = copy_config(gnl, i)))
			return (perror_msg("Allocation Failed on ", params->we));
	}
	else if (gnl[*i] == 'E' && gnl[*i + 1] == 'A')
	{
		if (!(params->ea = copy_config(gnl, i)))
			return (perror_msg("Allocation Failed on ", params->ea));
	}
	else if (gnl[*i] == 'F')
	{
		if (!(params->f = copy_config(gnl, i)))
			return (perror_msg("Allocation Failed on ", params->f));
	}
	else if (gnl[*i] == 'C')
	{
		if (!(params->c = copy_config(gnl, i)))
			return (perror_msg("Allocation Failed on ", params->c));
	}
	else if (is_only_space(gnl))
		return (0);
	else
		return (perror_msg("Data error: ", gnl));
	return (0);
}

int	init_config(int *flag, char *gnl, t_params *params)
{
	int		i;

	i = 0;
	if (!*flag && !is_only_space(gnl))
	{
		while (ft_is_space(gnl[i]))
			i++;
		if (put_data_config(params, gnl, &i))
			return (1);
	}
	return (0);
}

t_map *load_map(int fd, t_params *params)
{
	t_map	*map;
	t_line	*line;
	char	*gnl;
	int 	flag;

	line = NULL;
	map = NULL;
	flag = 0;
	gnl = get_next_line(fd);
	while (gnl != NULL)
	{
		line = NULL;
		if (is_all_config_set(params))
			flag = 1;
		if (init_config(&flag, gnl, params))
		{
			free(gnl);
			cleanup(params);
			exit(EXIT_FAILURE);
		}
		if (flag)
		{
			initialize_line(&line, gnl);
			initialize_map(&map, line);
		}
		free(gnl);
		gnl = get_next_line(fd);
	}
	return (map);
}
