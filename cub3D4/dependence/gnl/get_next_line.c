/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:14:49 by rhanitra          #+#    #+#             */
/*   Updated: 2024/08/15 10:38:08 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*putline(char *readed_line)
{
	size_t		i;
	char		*line;
	size_t		size_line;

	i = -1;
	size_line = check_new_line(readed_line);
	line = (char *)malloc(sizeof(char) * (size_line + 1));
	if (!line)
		return (NULL);
	while (++i < size_line && readed_line[i] != '\0')
		line[i] = readed_line[i];
	line[i] = '\0';
	return (line);
}

char	*putlast(char *readed_line)
{
	size_t		i;
	size_t		j;
	size_t		size_line;
	size_t		size_read;
	char		*temp;

	j = 0;
	if (readed_line == NULL)
		return (NULL);
	size_line = check_new_line(readed_line);
	size_read = ft_strlen(readed_line);
	if (size_line == size_read)
		return (free(readed_line), NULL);
	temp = (char *)malloc(sizeof(char) * ((size_read - size_line) + 1));
	if (!temp)
		return (NULL);
	i = size_line;
	while (i + j < size_read)
	{
		temp[j] = readed_line[i + j];
		j++;
	}
	temp[j] = '\0';
	free(readed_line);
	return (temp);
}

char	*read_line(int fd, int	*check, char *buffer, char *readed_line)
{
	size_t	i;

	i = ft_strlen(readed_line);
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (readed_line != NULL && check_back_slash_n(readed_line, '\n'))
		return (readed_line);
	while (*check)
	{
		*check = read(fd, buffer, BUFFER_SIZE);
		if (*check < 0 || (*check == 0 && readed_line == NULL))
			return (free(buffer), free(readed_line), NULL);
		buffer[*check] = '\0';
		i += *check;
		readed_line = ft_strjoin_gnl(readed_line, buffer, i);
		if (readed_line == NULL)
			return (free(buffer), NULL);
		if (check_back_slash_n(buffer, '\n'))
			break ;
	}
	return (readed_line);
}

char	*get_next_line(int fd)
{
	int			check;
	char		*buffer;
	static char	*readed_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	check = -1;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	readed_line = read_line(fd, &check, buffer, readed_line);
	if (readed_line == NULL)
		return (free(readed_line), NULL);
	free(buffer);
	buffer = putline(readed_line);
	readed_line = putlast(readed_line);
	return (buffer);
}
