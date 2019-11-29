/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llutoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:45:23 by tamarant          #+#    #+#             */
/*   Updated: 2019/11/29 18:45:13 by tamarant         ###   ########.fr       */
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

//static char		ft_str_int(char *s, unsigned long long int n, int len)
//{
//	while (len--)
//	{
//		s[len] = (n % 10) + 48;
//		n = n / 10;
//	}
//	return ((char)s);
//}

char			*ft_llutoa(unsigned long long int n)
{
	int		len;
	char	*res;

	if (n <= 18446744073709551615U)
	{
		len = nbr_len(n);
		if (!(res = ft_memalloc(len + 1)))
			return (NULL);
//		ft_str_int(res, n, len);
		while (--len > -1)
		{
			res[len] = (n % 10) + 48;
			n = n / 10;
		}
		return (res);
	}
	return (NULL);
}
