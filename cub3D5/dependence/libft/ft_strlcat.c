/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:44:09 by rhanitra          #+#    #+#             */
/*   Updated: 2024/12/31 18:44:12 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	srclen;
	size_t	destlen;

	destlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = destlen;
	if (dst == src)
		return (0);
	if (size != 0 && i < (size - 1))
	{
		j = 0;
		while (i < (size - 1) && src[j] != '\0')
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	if (destlen > size)
		return (size + srclen);
	return (destlen + srclen);
}
