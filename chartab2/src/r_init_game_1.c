/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_init_game_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:49:57 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/17 18:22:20 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


/*void	initialize_map(t_map **head, t_line *line)
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
}*/

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

int in_base(char *gnl)
{
	int	i;

	i = 0;
	while (ft_is_space(gnl[i]))
		i++;
	return ((gnl[i] == 'N' && gnl[i + 1] == 'O' && gnl[i + 2] == ' ') \
		|| (gnl[i] == 'S' && gnl[i + 1] == 'O' && gnl[i + 2] == ' ') \
		|| (gnl[i] == 'W' && gnl[i + 1] == 'E' && gnl[i + 2] == ' ') \
		|| (gnl[i] == 'E' && gnl[i + 1] == 'A' && gnl[i + 2] == ' ') \
		|| (gnl[i] == 'F' && gnl[i + 1] == ' ' && gnl[i + 1] == ' ') \
		|| (gnl[i] == 'C' && gnl[i + 1] == ' ' && gnl[i + 1] == ' '));
}

int put_data_config(t_params *params, char *gnl, int *i)
{
	if (!in_base(gnl))
		return (perror_msg("Data error: ", gnl));
	if (gnl[*i] == 'N' && gnl[*i + 1] == 'O')
		if (!(params->path->no = copy_config(gnl, i)))
			return (perror_msg("Allocation Failed on ", params->path->no));
	if (gnl[*i] == 'S' && gnl[*i + 1] == 'O')
		if (!(params->path->so = copy_config(gnl, i)))
			return (perror_msg("Allocation Failed on ", params->path->so));		
	if (gnl[*i] == 'W' && gnl[*i + 1] == 'E')
		if (!(params->path->we = copy_config(gnl, i)))
			return (perror_msg("Allocation Failed on ", params->path->we));
	if (gnl[*i] == 'E' && gnl[*i + 1] == 'A')
		if (!(params->path->ea = copy_config(gnl, i)))
			return (perror_msg("Allocation Failed on ", params->path->ea));
	if (gnl[*i] == 'F')
		if (!(params->path->f = copy_config(gnl, i)))
			return (perror_msg("Allocation Failed on ", params->path->f));
	if (gnl[*i] == 'C')
		if (!(params->path->c  = copy_config(gnl, i)))
			return (perror_msg("Allocation Failed on ", params->path->c));
	return (0);
}
