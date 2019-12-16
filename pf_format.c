/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:53:59 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/16 17:09:54 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		size_lh(t_pf *pf, char p, va_list ap, int n)
{
	if (n == 2)
	{
		if (p == 'd' || p == 'i')
			!(ft_strcmp(pf->size, "hh")) ?
			(pf->num.lli = (long long int)((signed char)va_arg(ap, int)))
			: (pf->num.lli = va_arg(ap, long long int));
		else if (p == 'u' || p == 'o' || p == 'x' || p == 'X')
			!(ft_strcmp(pf->size, "hh")) ?
			(pf->num.ulli = (unsigned long long)
					((unsigned char)va_arg(ap, int)))
			: (pf->num.ulli = va_arg(ap, unsigned long long));
	}
	else
	{
		if (p == 'd' || p == 'i')
			!(ft_strcmp(pf->size, "h")) ?
			(pf->num.lli = (long long int)((short int)va_arg(ap, int)))
			: (pf->num.lli = (long long int)va_arg(ap, long int));
		else if (p == 'f' && !ft_strcmp(pf->size, "l"))
			pf->num.ld = (long double)va_arg(ap, double);
		else if (p == 'u' || p == 'o' || p == 'x' || p == 'X')
			!(ft_strcmp(pf->size, "h")) ?
	(pf->num.ulli = (unsigned long long)((unsigned short int)va_arg(ap, int)))
	: (pf->num.ulli = (unsigned long long)va_arg(ap, unsigned long int));
	}
}

static void		number_size(t_pf *pf, char p, va_list ap)
{
	if (pf->size && (!(ft_strcmp(pf->size, "ll"))
	|| !(ft_strcmp(pf->size, "hh"))))
		size_lh(pf, p, ap, 2);
	else if (pf->size && (!(ft_strcmp(pf->size, "l"))
	|| !(ft_strcmp(pf->size, "h"))))
		size_lh(pf, p, ap, 1);
	else if (pf->size && !ft_strcmp(pf->size, "L"))
		pf->num.ld = (long double)va_arg(ap, long double);
	else
	{
		if (p == 'd' || p == 'i')
			pf->num.lli = (long long int)va_arg(ap, int);
		else if (p == 'u' || p == 'x' || p == 'X' || p == 'o')
			pf->num.ulli = (unsigned long long)va_arg(ap, unsigned int);
		else if (p == 'f')
			pf->num.ld = (long double)va_arg(ap, double);
		else if (p == 'p')
			pf->num.ulli = va_arg(ap, unsigned long long);
	}
}

static void		sc_percent_size(t_pf *pf, char p, va_list ap)
{
	if (p == 's')
	{
		if (!(pf->tmp_oxfs = ft_strdup(va_arg(ap, char*))))
			pf->tmp_oxfs = ft_strdup("(null)");
	}
	else if (p == 'c')
		pf->num.c = (char)va_arg(ap, int);
	else if (p == '%')
		pf->num.c = '%';
}

static void		find_format(t_pf *pf, char **p)
{
	if (is_flags(*p))
		find_flags(pf, &*p);
	if (is_width(*p))
		find_width(pf, &*p);
	if (is_precision(&*p, pf))
		find_precision(pf, &*p);
	if (is_size(*p))
		find_size(pf, &*p);
}

int				pf_format(t_pf *pf, char **p, va_list ap)
{
	*p += 1;
	find_format(pf, p);
	if (**p == '\0')
		return (-1);
	if (ft_strchr("%scpfdiouxX", **p))
	{
		pf->type = **p;
		if (ft_strchr("pfdiouxX", pf->type))
			number_size(pf, **p, ap);
		else
			sc_percent_size(pf, **p, ap);
		*p += 1;
	}
	if (pf->type == 'f')
		display_f(pf);
	parse_format(pf);
	if (find_str_size(pf) == -1)
		return (-1);
	check_buf(pf, &*p);
	pf->counter += pf->str_len;
	return (1);
}
