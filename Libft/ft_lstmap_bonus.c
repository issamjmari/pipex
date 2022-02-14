/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijmari <ijmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:27:01 by ijmari            #+#    #+#             */
/*   Updated: 2021/11/11 14:27:09 by ijmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	int		i;

	i = 0;
	if (lst && f && del)
	{
		while (lst)
		{
			new = ft_lstnew(f(lst->content));
			if (i == 0)
				temp = NULL;
			if (!new)
			{
				ft_lstclear(&new, del);
				return (0);
			}
			ft_lstadd_back(&temp, new);
			lst = lst->next;
			i++;
		}
		return (temp);
	}
	return (0);
}
