/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijmari <ijmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:49:20 by ijmari            #+#    #+#             */
/*   Updated: 2021/11/11 16:01:13 by ijmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int	size;

	size = 1;
	if (n == -2147483648)
		return (1000000000);
	if (n < 0)
		n *= -1;
	while (n / 10 > 0)
	{
		size *= 10;
		n /= 10;
	}
	return (size);
}

static int	ft_len(int n)
{
	int	len;

	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		len = 1;
		n *= -1;
	}
	else
		len = 0;
	while (n / 10 > 0)
	{
		len += 1;
		n /= 10;
	}
	return (len + 1);
}

static int	ft_sign(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static char	*ft_stock(int len, long long int n, int size, char *temp)
{
	while (len >= 0)
	{
		temp[len] = (n % 10) + '0';
		n /= 10;
		size /= 10;
		len--;
	}
	return (temp);
}

char	*ft_itoa(int n)
{
	int						size;
	size_t					len;
	int						sign;
	char					*temp;
	long long int			t;

	sign = 0;
	len = ft_len(n);
	size = ft_size(n);
	sign = ft_sign(n);
	temp = (char *) malloc (len + 1);
	if (!temp)
		return (0);
	temp[len] = '\0';
	len--;
	t = n;
	if (n < 0)
		t *= -1;
	if (n == 0)
		temp[0] = '0';
	temp = ft_stock(len, t, size, temp);
	if (sign == 1)
		temp[0] = '-';
	return (temp);
}
