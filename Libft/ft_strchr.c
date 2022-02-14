/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijmari <ijmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:02:49 by ijmari            #+#    #+#             */
/*   Updated: 2021/11/05 15:57:53 by ijmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *) str;
	while (temp[i])
	{
		if (temp[i] == (unsigned char) c)
			return (&temp[i]);
		i++;
	}
	if (temp[i] == (unsigned char) c)
		return (&temp[i]);
	return (0);
}
