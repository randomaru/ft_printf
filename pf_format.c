/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:53:59 by tamarant          #+#    #+#             */
/*   Updated: 2019/10/24 15:20:07 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		number_size(t_pf *pf, char p, va_list ap)
{
	///ft_strcmp вернет 0 если строки идентичны
	if (!(ft_strcmp(pf->size, "ll")) || !(ft_strcmp(pf->size, "hh")))
	{
		if (p == 'd' || p == 'i')
			!(ft_strcmp(pf->size, "hh")) ? (pf->num.sc = va_arg(ap, signed char))
										: (pf->num.lli = va_arg(ap, long long int));
		else if (p == 'u' || p == 'o' || p == 'x' || p == 'X')
			!(ft_strcmp(pf->size, "hh")) ? (pf->num.uc = va_arg(ap, unsigned char))
									  : (pf->num.ulli = va_arg(ap, unsigned long long int));
	}
	else if (!(ft_strcmp(pf->size, "l")) || !(ft_strcmp(pf->size, "h")))
	{
		if (p == 'd' || p == 'i')
			!(ft_strcmp(pf->size, "h")) ? (pf->num.hi = va_arg(ap, short int))
										 : (pf->num.li = va_arg(ap, long int));
		else if (p == 'u' || p == 'o' || p == 'x' || p == 'X')
			!(ft_strcmp(pf->size, "h")) ? (pf->num.uhi = va_arg(ap, unsigned short int))
										 : (pf->num.uli = va_arg(ap, unsigned long int));
	}
	else
	{
		if (p == 'd' || p == 'i' || p == 'o' || p == 'x' || p == 'X')
			pf->num.i = va_arg(ap, int);
		else if (p == 'u')
			pf->num.ui = va_arg(ap, unsigned int);
	}
}

int				pf_format(t_pf *pf, char *p, va_list ap)
{
	if (is_flags(p))
		find_flags(pf, &p);
	if (is_width(p))
		find_width(pf, &p);
	if (is_precision(p))
		find_precision(pf, &p);
	if (is_size(p))
		find_size(pf, &p);
	if (ft_strchr("diouxX", *p))
	{
		pf->type = *p;
		number_size(pf, *p, ap);
	}
	to_str(pf);
	str_format(pf);
	///теперь нужно определить тип переменной из union
}
