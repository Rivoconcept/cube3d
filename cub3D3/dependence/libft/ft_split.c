/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:42:37 by rhanitra          #+#    #+#             */
/*   Updated: 2024/12/31 18:42:38 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(const char *str, char c)
{
	size_t	i;
	size_t	word_size;
	size_t	token;

	i = 0;
	word_size = 0;
	token = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && token == 0)
		{
			token = 1;
			word_size++;
		}
		else if (str[i] == c)
			token = 0;
		i++;
	}
	return (word_size);
}

static size_t	word_size(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static void	ft_free(size_t i, char **tab)
{
	while (i > 0)
	{
		i--;
		free(tab[i]);
	}
	free(tab);
}

static char	**word_copy(char const *str, char c, char **word, size_t count_word)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < count_word)
	{
		while (str[j] != '\0' && str[j] == c)
			j++;
		word[i] = ft_substr(str, j, word_size(&str[j], c));
		if (!word[i])
		{
			ft_free(i, word);
			return (NULL);
		}
		while (str[j] != '\0' && str[j] != c)
			j++;
		i++;
	}
	word[i] = NULL;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	tab = word_copy(s, c, tab, count_word(s, c));
	return (tab);
}
