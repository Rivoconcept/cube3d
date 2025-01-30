/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:53:27 by rhanitra          #+#    #+#             */
/*   Updated: 2024/12/31 18:40:30 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int			i;
	unsigned char			*str;
	unsigned char			to_find;

	str = (unsigned char *)s;
	to_find = (unsigned char)c;
	i = 0;
	while (n--)
	{
		if (str[i] == to_find)
			return ((void *)(unsigned char *)&str[i]);
		i++;
	}
	return (0);
}
