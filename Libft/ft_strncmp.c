/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijmari <ijmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 09:58:19 by ijmari            #+#    #+#             */
/*   Updated: 2021/11/05 15:58:16 by ijmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *) s1;
	st2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (st1[i] != '\0' && st2[i] != '\0'
		&& st1[i] == st2[i] && i < (n - 1))
		i++;
	return (st1[i] - st2[i]);
}
