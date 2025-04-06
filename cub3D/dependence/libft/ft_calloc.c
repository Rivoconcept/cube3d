/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:20:06 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/02 17:07:18 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(nmemb * size);
	if (str == 0)
		return (0);
	while (i < nmemb * size)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}

int	main(void)
{
	size_t	nmemb = 5;
	size_t	size = sizeof(int);
	int		*arr;
	size_t	i;

	// Appel de ft_calloc pour allouer et initialiser le tableau
	arr = (int *)ft_calloc(nmemb, size);
	if (arr == NULL)
	{
		perror("ft_calloc a échoué");
		return (EXIT_FAILURE);
	}

	// Vérification que chaque élément est initialisé à zéro
	for (i = 0; i < nmemb; i++)
	{
		if (arr[i] != 0)
		{
			printf("Échec : arr[%zu] = %d, attendu 0\n", i, arr[i]);
			free(arr);
			return (EXIT_FAILURE);
		}
	}

	printf("Succès : tous les éléments sont initialisés à 0.\n");

	// Libération de la mémoire allouée
	free(arr);

	return (EXIT_SUCCESS);
}
