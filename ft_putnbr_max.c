/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:08:45 by tamarant          #+#    #+#             */
/*   Updated: 2019/11/27 16:55:07 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putnbr_max(long long int nb)
{
	if (nb == LONG_MIN)
		ft_putstr("-9223372036854775808");
	if (nb < 0 && nb != LONG_MIN)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10 && nb != LONG_MIN)
	{
		ft_putnbr_max(nb / 10);
		ft_putnbr_max(nb % 10);
	}
	else if (nb != LONG_MIN)
	{
		ft_putchar(nb + '0');
	}
}
