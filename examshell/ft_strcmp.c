/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:32:14 by rhanitra          #+#    #+#             */
/*   Updated: 2024/12/04 13:04:29 by rhanitra         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "examshell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t 			n;
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	n = ft_strlen((char *)s2);
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
