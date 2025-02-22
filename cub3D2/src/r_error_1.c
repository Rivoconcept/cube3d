/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_error_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:50:23 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/16 14:19:17 by rhanitra         ###   ########.fr       */
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
