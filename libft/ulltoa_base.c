/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulltoa_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:16:00 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/16 14:37:51 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long int		conv_ex(unsigned long long int nb)
{
	if (nb >= 10)
		return (nb - 10 + 'a');
	else
		return (nb + '0');
}

char								*ulltoa_base(unsigned long long int value, int base)
{
	int						i;
	char					*str;
	unsigned long long int	tmp;

	str = NULL;
	i = 1;
	tmp = value;
	while (tmp >= (unsigned long long)base)
	{
		tmp = tmp / base;
		i++;
	}
	if (!(str = ft_memalloc(i + 1)))
		return (NULL);
	while (i > 0)
	{
		--i;
		tmp = value % base;
		str[i] = conv_ex(tmp);
		value /= base;
	}
	return (str);
}