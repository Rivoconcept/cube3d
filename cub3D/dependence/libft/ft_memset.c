/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:41:35 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/02 17:01:32 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int		i;
	unsigned char		*p;

	p = s;
	i = 0;
	while (n != 0)
	{
		p[i] = c;
		i++;
		n--;
	}
	return (s);
}
int	main(void)
{
	char str[20] = "Hello, World!";
	
	printf("Avant memset : %s\n", str);
	ft_memset(str + 7, '*', 5);
	printf("Après memset  : %s\n", str);

	return (0);
}