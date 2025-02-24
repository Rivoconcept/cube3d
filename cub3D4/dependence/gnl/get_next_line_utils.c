/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:29:59 by rhanitra          #+#    #+#             */
/*   Updated: 2024/08/15 10:38:05 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	check_new_line(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

size_t	check_back_slash_n(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *old_str, char *buffer, size_t size)
{
	size_t		i;
	size_t		j;
	char		*new_str;

	i = 0;
	j = 0;
	new_str = NULL;
	new_str = malloc(sizeof(char) * (size + 1));
	if (!new_str)
		return (free(old_str), NULL);
	if (old_str)
	{
		while (old_str[i] != '\0')
			new_str[i++] = old_str[j++];
	}
	j = 0;
	if (buffer)
	{
		while (buffer[j] != '\0')
			new_str[i++] = buffer[j++];
	}
	new_str[i] = '\0';
	return (free(old_str), new_str);
}
