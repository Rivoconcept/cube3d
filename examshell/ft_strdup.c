/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:04:09 by rhanitra          #+#    #+#             */
/*   Updated: 2024/12/04 13:04:55 by rhanitra         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "examshell.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!new_str)
		return (NULL);
	while (s[i] != '\0')
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
