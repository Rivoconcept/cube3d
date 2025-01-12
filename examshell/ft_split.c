#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int	put_word_len(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	return (i);
}

int	word_count(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			j++;
		i++;
	}
	return (j);
}

char	*split_word(char *str, int index)
{
	int		i;
	int		size_word;
	char	*temp;

	i = 0;
	size_word = put_word_len(&str[index]);
	temp = (char *)malloc(sizeof(char) * size_word + 1);
	if (!temp)
		return (NULL);
	while (str[index] != '\0' && str[index] != ' ')
	{
		temp[i] = str[index];
		i++;
		index++;
	}
	temp[i] = '\0';
	return (temp);
}

char	**ft_split(char const *s)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (word_count((char *)s) + 1));
	if (!split)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != ' ')
		{
			split[j++] = split_word((char *)s, i);
			while (s[i] != '\0' && s[i] != ' ')
				i++;
		}
		else
			i++;
	}
	split[j] = NULL;
	return (split);
}
