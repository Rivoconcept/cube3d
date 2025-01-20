/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:07:54 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/20 17:48:12 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	initialize_line(t_line **head, char *argv)
{
	int		i;
	t_line	*current;
	t_line	*new_element;

	i = 0;
	new_element = NULL;
	while (argv[i] != '\0')
	{
		new_element = create_list_line(argv[i]);
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

t_map	*load_map(char *argv)
{
	int		fd;
	char	*gnl;
	t_map	*map;
	t_line	*line;

	line = NULL;
	map = NULL;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nErreur lors de l'ouverture du fichier");
		exit(EXIT_FAILURE);
	}
	gnl = get_next_line(fd);
	while (gnl != NULL)
	{
		line = NULL;
		initialize_line(&line, gnl);
		free(gnl);
		initialize_map(&map, line);
		gnl = get_next_line(fd);
	}
	close(fd);
	return (map);
}
