/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:38:51 by rhanitra          #+#    #+#             */
/*   Updated: 2024/12/31 18:38:51 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*before;

	if (lst && *lst && del)
	{
		before = (t_list *)*lst;
		while (before)
		{
			temp = before->next;
			ft_lstdelone(before, del);
			before = temp;
		}
		*lst = NULL;
	}
}
