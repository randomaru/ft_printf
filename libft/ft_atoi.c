/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:54:47 by tamarant          #+#    #+#             */
/*   Updated: 2019/11/27 16:55:07 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_if_neg(const char *str, int i)
{
	int neg;

	neg = 0;
	if (str[i] == '-')
		neg = 1;
	return (neg);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			neg;
	long long	res;

	i = 0;
	res = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13 && str[i] != '\0'))
		i++;
	if ((neg = ft_if_neg(str, i)) && str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	if (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (res != (res * 10 + (str[i] - '0')) / 10)
		{
			if (neg)
				return (0);
			return (-1);
		}
		res = res * 10 + (str[i++] - '0');
	}
	if (neg)
		return (-res);
	return (res);
}
