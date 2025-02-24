/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:50:18 by rhanitra          #+#    #+#             */
/*   Updated: 2024/12/31 18:37:02 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int		i;
	unsigned char		*p;

	p = s;
	i = 0;
	while (n != 0)
	{
		p[i] = 0;
		i++;
		n--;
	}
}
