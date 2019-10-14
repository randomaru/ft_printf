/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:08:37 by tamarant          #+#    #+#             */
/*   Updated: 2019/10/14 15:37:42 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	string(char *str)
{
	ft_putstr(str);
}

int		d_i(int nbr)
{
	int razniza = 0;

	if (nbr > 2147483647)
	{
		razniza = nbr - 2147483647;
		nbr = -2147483648 + razniza;
		ft_putnbr(nbr);
	}
	else if (nbr < -2147483648)
	{
		razniza = nbr + 2147483648;
		nbr = 2147483647 - razniza;
		ft_putnbr(nbr);
	}
	else
		ft_putnbr(nbr);
	//ft_putnbr_max((long long int)nbr);

	return (1);
}

void	u(unsigned int nbr)
{
	/*if (nbr > 4294967295)
	{
		u(nbr - 4294967295);
	}
	else*/
		ft_putnbr_max((long long int)nbr);
}

