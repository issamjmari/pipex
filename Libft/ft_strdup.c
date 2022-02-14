/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijmari <ijmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:35:35 by ijmari            #+#    #+#             */
/*   Updated: 2021/11/11 17:34:23 by ijmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	dup = (char *) malloc ((i + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (str[j])
	{
		dup[j] = str[j];
		j++;
	}
	dup[j] = '\0';
	return (dup);
}
