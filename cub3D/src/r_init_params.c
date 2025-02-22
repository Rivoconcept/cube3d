/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_init_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:49:17 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/16 18:22:45 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_list_position(t_position *head)
{
	t_position	*temp;
	t_position	*current;

	if (!head)
		return ;
	temp = NULL;
	current = head;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	head = NULL;
}

t_params	*create_list_param(void)
{
	t_params	*new_params;

	new_params = (t_params *)malloc(sizeof(t_params));
	if (new_params == NULL)
		return (NULL);
	new_params->mlx_connexion = NULL;
	new_params->win_open = NULL;
	new_params->map = NULL;
	new_params->map_width = 0;
	new_params->map_height = 0;
	new_params->clear = init_list_img();
	// new_params->wall = NULL;
	// new_params->map = NULL;
	new_params->pos = create_list_position();
	new_params->f_color = init_ground_color();
	new_params->c_color = init_ceiling_color();
	new_params->rect = init_rectangle();
	new_params->player = init_list_player();
	new_params->delta = 0;
	new_params->no = NULL;
	new_params->so = NULL;
	new_params->we = NULL;
	new_params->ea = NULL;
	new_params->f = NULL;
	new_params->c = NULL;
	new_params->x = 0;
	new_params->y = 0;
	new_params->win_width = 0;
	new_params->win_height = 0;
	new_params->next = NULL;
	return (new_params);
}
