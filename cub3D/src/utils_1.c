/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttelolah <ttelolah@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:48:37 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/03 16:53:15 by ttelolah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_is_space(char c)
{
	return ((c >= '\t' && c <= '\r') || c == 32);
}

int	perror_msg(char *error, char *var)
{
	ft_putstr_fd("Error\n", 2);
	if (error)
		ft_putstr_fd(error, 2);
	ft_putstr_fd(var, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

void	ft_exit_faillure(t_params *params, int fd, char *error, char *var)
{
	close(fd);
	perror_msg(error, var);
	cleanup(params);
	exit(EXIT_FAILURE);
}

int	find_char(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
