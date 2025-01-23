/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:07:54 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/23 19:21:38 by rhanitra         ###   ########.fr       */
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

/*NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0*/

void put_data_config(t_params *params, char *gnl, int *i)
{
	if (gnl[*i] == 'N' && gnl[*i + 1] == 'O')
		params->no = ft_strdup(ft_strchr(gnl, '.'));
	if (gnl[*i] == 'S' && gnl[*i + 1] == 'O')
		params->so = ft_strdup(ft_strchr(gnl, '.'));
	if (gnl[*i] == 'W' && gnl[*i + 1] == 'E')
		params->we = ft_strdup(ft_strchr(gnl, '.'));
	if (gnl[*i] == 'E' && gnl[*i + 1] == 'A')
		params->ea = ft_strdup(ft_strchr(gnl, '.'));
	if (gnl[*i] == 'F')
	{
		while (ft_is_space(gnl[*i]))
			(*i)++;
		params->f = ft_strdup(&gnl[*i]);
	}
	if (gnl[*i] == 'C')
	{
		while (ft_is_space(gnl[*i]))
			(*i)++;
		params->c = ft_strdup(&gnl[*i]);
	}
}
int	init_config(int *flag, char *gnl, t_params *params)
{
	int		i;

	i = 0;
	while (ft_is_space(gnl[i]))
		i++;
	put_data_config(params, gnl, &i);
	if (check_error_config(params) && is_all_config_set(params))
		flag = 1;
	return (0);
}

t_map *put_map(int fd, int *flag)
{
	t_map	*map;
	t_line	*line;
	char	*gnl;

	line = NULL;
	map = NULL;
	gnl = get_next_line(fd);
	while (gnl != NULL)
	{
		line = NULL;
		if (!*flag)

		if (*flag)
		{
			initialize_line(&line, gnl);
			free(gnl);
			initialize_map(&map, line);
		}
		gnl = get_next_line(fd);
	}
	return (map);
}

t_map	*load_map(char *argv)
{
	int		fd;
	int		flag;
	t_map	*map;

	flag = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nErreur lors de l'ouverture du fichier");
		exit(EXIT_FAILURE);
	}
	map = init_config(fd, &flag);
	close(fd);
	return (map);
}
