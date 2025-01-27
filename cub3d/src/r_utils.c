/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:25:12 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/27 18:53:36 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_is_space(char c)
{
	return ((c >= '\t' && c <= '\r') || c == 32);
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

int	is_line_map(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '\n')
	{
		return (0);
	}
	while (str[i] != '\n' && (str[i] == 32 || str[i] == 49))
		i++;
	if (str[i] == '\n')
	{
		return (1);
	}
	return (0);
}

int is_only_space(char *str)
{
	int		i;

	i = 0;
	if (!str || str[0] == '\n' || str[0] == '\0')
		return (0);
	while(ft_is_space(str[i]))
		i++;
	if (str[i] == '\n' || str[i] == '\0')
		return (1);
	return (0);
}

int	perror_msg(char *error, char *var)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(var, 2);
	if (error)
		ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

void ft_exit_faillure(char *error, char *var)
{
	perror_msg(error, var);
	exit(EXIT_FAILURE);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr || arr == NULL)
		return ;
	while (arr[i] != NULL)
	{
		if (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
		}
		i++;
	}
	if (arr)
		free(arr);
	arr = NULL;
}

int is_all_config_set(t_params *params)
{
	if (params->no != NULL && params->so != NULL && params->we != NULL \
		&& params->ea != NULL && params->f != NULL && params->c != NULL)
		return (1);
	return (0);
}

int check_error_path(t_params *params)
{
	if (params->no && params->no[1] != '/')
	{
        printf("Error\npath: '%s' is not a directory\n", params->no);
		return (1);
	}
	if (params->so && params->so[1] != '/')
	{
        printf("Error\npath: '%s' is not a directory\n", params->so);
		return (1);
	}
	if (params->we && params->we[1] != '/')
	{
        printf("Error\npath: '%s' is not a directory\n", params->we);
		return (1);
	}
	if (params->ea && params->ea[1] != '/')
	{
        printf("Error\npath: '%s' is not a directory\n", params->ea);
		return (1);
	}
	return (0);
}

int check_error_color(char *color)
{
	int		i;
	char	**tab;
	int		value;

	i = 0;
	value = 0;
	tab = ft_split(color, ',');
	if (!tab || tab[3])
	{
		free_array(tab);
		return (1);
	}
	while(tab[i] != NULL)
	{
		value = ft_atoi(tab[i]);
		if (value < 0 || value > 255)
		{
			free_array(tab);
			return (1);
		}
		i++;
	}
	free_array(tab);
	return (0);
}

int check_error_config(t_params *params)
{
	if (params->no == NULL || params->so == NULL || params->we == NULL \
		|| params->ea == NULL || params->f == NULL || params->c == NULL)
		return (1);
	if (check_error_path(params))
		return (1);
	if (check_error_color(params->f))
	{
		printf("Error\nErron on data color\n");
		return (1);
	}
	return (0);
}

