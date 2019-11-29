/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:53:59 by tamarant          #+#    #+#             */
/*   Updated: 2019/11/29 14:49:14 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		number_size(t_pf *pf, char p, va_list ap)
{
	///ft_strcmp вернет 0 если строки идентичны
	if (pf->size && (!(ft_strcmp(pf->size, "ll")) || !(ft_strcmp(pf->size, "hh"))))
	{
		if (p == 'd' || p == 'i')
			!(ft_strcmp(pf->size, "hh")) ? (pf->num.sc = (signed char)va_arg(ap, int)) ////
										: (pf->num.lli = va_arg(ap, long long int));
		else if (p == 'u' || p == 'o' || p == 'x' || p == 'X')
			!(ft_strcmp(pf->size, "hh")) ? (pf->num.uc = (unsigned char)va_arg(ap, int)) //////
									  : (pf->num.ulli = va_arg(ap, unsigned long long int));
	}
	else if (pf->size && (!(ft_strcmp(pf->size, "l")) || !(ft_strcmp(pf->size, "h"))))
	{
		if (p == 'd' || p == 'i')
			!(ft_strcmp(pf->size, "h")) ? (pf->num.hi = (short int)va_arg(ap, int)) /////
										 : (pf->num.li = va_arg(ap, long int));
		else if (p == 'u' || p == 'o' || p == 'x' || p == 'X')
			!(ft_strcmp(pf->size, "h")) ? (pf->num.uhi = (unsigned short int)va_arg(ap, int)) //////
										 : (pf->num.uli = va_arg(ap, unsigned long int));
	}
	else
	{
		if (p == 'd' || p == 'i')
			pf->num.i = va_arg(ap, int);
		else if (p == 'u' || p == 'o' || p == 'x' || p == 'X')
			pf->num.ui = va_arg(ap, unsigned int);
	}
}

int				pf_format(t_pf *pf, char **p, va_list ap)
{
	*p += 1;
	if (is_flags(*p))
		find_flags(pf, &*p);
	if (is_width(*p))
		find_width(pf, &*p);
	if (is_precision(*p))
		find_precision(pf, &*p);
	if (is_size(*p))
		find_size(pf, &*p);
	if (ft_strchr("diouxX", **p))
	{
		pf->type = **p;
		number_size(pf, **p, ap);
		*p += 1;
	}
	if (**p != 'f')
	{
		save_format(pf);
		if (str_size(pf) == -1)
			return (-1);
		new_num_str(pf);
		ft_putstr(pf->str);
	}
	if (**p == 'f')
	{
		pf->type = **p;
		pf->num.d = va_arg(ap,double);
		display_f(pf);
		*p += 1;
	}
	pf->counter += ft_strlen(pf->str);
	return(1);
}
