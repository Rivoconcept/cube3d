/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:14:35 by ttelolah          #+#    #+#             */
/*   Updated: 2025/04/06 09:53:46 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_extension(char *str)
{
	int		i;
	int		size;
	char	temp[5];

	i = 0;
	temp[0] = '\0';
	size = ft_strlen(str) - 1;
	if (size + 1 == 4)
	{
		return (0);
	}
	while (str[size] && i < 5)
	{
		temp[i] = str[size];
		i++;
		size--;
	}
	temp[i] = '\0';
	if (ft_strncmp(temp, "buc.", 4) == 0 && temp[i - 1] != '/')
		return (1);
	return (0);
}
