/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijmari <ijmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:20:59 by ijmari            #+#    #+#             */
/*   Updated: 2021/11/10 15:21:00 by ijmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (*lst && del)
	{
		temp = *lst;
		while (temp->next)
		{
			temp = *lst;
			ft_lstdelone(temp, del);
			*lst = (*lst)->next;
		}
	}
	*lst = 0;
}
