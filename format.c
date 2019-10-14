/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:41:21 by tamarant          #+#    #+#             */
/*   Updated: 2019/10/14 20:11:41 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_flags(char *p, va_list ap, t_pf *pf)
{
	++p;
	if (*p == '%')
		ft_putchar('%');
	while (!(ft_strchr("cspdiouxXhlL", *p)))
	{
		if (*p == '0')
			pf->flag = '0';
		else if (*p > '0' && *p <= '9')
		{
			pf->flag = ' ';
			pf->width = ft_atoi(p);
		}
		p++;
	}

}

void	type(char *p, va_list *ap, t_pf *pf)
{
	if ((*p == 'h' && *(p + 1) == 'h') || (*p == 'l' && *(p + 1) == 'l'))
	{
		if (*p == 'h')
			pf->type = "hh";
		else
			pf->type = "ll";
	}
	if (*p == 'h' || *p == 'l' )
		*p == 'h' ? (pf->type = "h") : (pf->type = "l");


}
