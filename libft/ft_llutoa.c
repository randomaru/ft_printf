/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llutoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:45:23 by tamarant          #+#    #+#             */
/*   Updated: 2019/11/28 20:58:54 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nbr_len(unsigned long long int n)
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

static char		ft_str_int(char *s, unsigned long long int n, int len, int neg)
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

char			*ft_llutoa(unsigned long long int n)
{
	int		len;
	int		neg;
	char	*res;

	neg = 0;
	if (n <= 18446744073709551615U)
	{
		len = nbr_len(n) + neg;
		if (!(res = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		ft_str_int(res, n, len, neg);
		return (res);
	}
	return (NULL);
}
