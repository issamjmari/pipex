/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijmari <ijmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:22:05 by ijmari            #+#    #+#             */
/*   Updated: 2021/11/11 20:40:09 by ijmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					i;
	unsigned char			*t1;
	unsigned char			*t2;

	i = 0;
	if (n == 0)
		return (0);
	t1 = (unsigned char *) s1;
	t2 = (unsigned char *) s2;
	while (t1[i] == t2[i] && i < n - 1)
		i++;
	return (t1[i] - t2[i]);
}
