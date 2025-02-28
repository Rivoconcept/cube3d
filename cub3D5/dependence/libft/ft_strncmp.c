/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:44:56 by rhanitra          #+#    #+#             */
/*   Updated: 2024/12/31 18:44:59 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n > 0)
	{
		while (str1[i] == str2[i] && str1[i] != '\0'
			&& str2[i] != '\0' && 1 < n)
		{
			i++;
			n--;
		}
		return (str1[i] - str2[i]);
	}
	else
		return (0);
}
