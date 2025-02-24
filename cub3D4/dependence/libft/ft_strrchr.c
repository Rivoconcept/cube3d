/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:45:21 by rhanitra          #+#    #+#             */
/*   Updated: 2024/12/31 18:45:22 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char const	*pos;

	pos = NULL;
	while (*s)
	{
		if (*s == (char)c)
			pos = s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return ((char *)pos);
}
