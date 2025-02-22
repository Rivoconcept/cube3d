/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:41:35 by rhanitra          #+#    #+#             */
/*   Updated: 2024/12/31 18:41:36 by rhanitra         ###   ########.fr       */
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
