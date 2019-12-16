/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 20:37:24 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/16 14:37:51 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len_itoa(int n)
{
	int len;

	len = 1;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char		ft_str_int(char *s, int n, int len, int neg)
{
	while (len--)
	{
		s[len] = (n % 10) + 48;
		n = n / 10;
	}
	if (neg)
		s[0] = '-';
	return ((char)s);
}

char			*ft_itoa(int n)
{
	int		len;
	int		neg;
	char	*res;

	neg = 0;
	if (n > -2147483648 && n <= 2147483647)
	{
		if (n < 0)
		{
			neg = 1;
			n *= -1;
		}
		len = ft_len_itoa(n) + neg;
		if (!(res = ft_memalloc(len + 1)))
			return (NULL);
		ft_str_int(res, n, len, neg);
		return (res);
	}
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (NULL);
}
