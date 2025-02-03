/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:41:24 by rhanitra          #+#    #+#             */
/*   Updated: 2024/12/31 18:41:25 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *target, void const *source, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;

	s = (char *)source;
	d = (char *)target;
	i = 0;
	if (!target && !source)
		return (target);
	if (target == source)
		return (target);
	if (d > s)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (n--)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (target);
}
