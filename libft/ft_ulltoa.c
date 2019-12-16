/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 17:32:46 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/16 14:37:51 by tamarant         ###   ########.fr       */
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

static char		ft_str_int(char *s, unsigned long long int n, int len)
{
	while (len--)
	{
		s[len] = (n % 10) + 48;
		n = n / 10;
	}
	return ((char)s);
}

char			*ft_ulltoa(unsigned long long int n)
{
	int		len;
	char	*res;

	if (n <= 18446744073709551615ull)
	{
		len = nbr_len(n);
		if (!(res = ft_memalloc(len + 1)))
			return (NULL);
		ft_str_int(res, n, len);
		return (res);
	}
	return (NULL);
}
