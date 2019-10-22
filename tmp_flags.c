/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:41:21 by tamarant          #+#    #+#             */
/*   Updated: 2019/10/22 15:35:27 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	tmp_format_flags(char *p, va_list ap, t_pf *pf)
{
	++p;
	if (*p == '%')
		ft_putchar('%');
	if (*p == '\n')
		ft_putchar('\n');
	while(*p != ' ' && *p != '\0')
	{
		if (*p == '0')
		{
			pf->flags = '0';
			if (*(p + 1) > '0' && *(p + 1) <= '9')
			{
				p++;
				pf->width = ft_atoi(p);
			}
		}
		else if (*p > '0' && *p <= '9')
		{
			pf->flags = ' ';
			pf->width = ft_atoi(p);
		}
		if ((*p == 'h' && *(p + 1) == 'h') || (*p == 'l' && *(p + 1) == 'l'))
		{
			*p == 'h' ? (pf->type = "hh") : (pf->type = "ll");
			p += 2;
		}
		else if (*p == 'h' || *p == 'l' )
		{
			*p == 'h' ? (pf->type = "h") : (pf->type = "l");
			p++;
		}
		tmp_type(p, ap, pf);
		p++;
	}
}

void	tmp_type(char *p, va_list ap, t_pf *pf)
{
		if (pf->type[0] == 'l')
		{
			if (pf->type[1] == 'l')
			{
				if (*p == 'd' || *p == 'i')
					pf->str = ft_lltoa(va_arg(ap, long long int));
				if (*p == 'u')
					pf->str = ft_llutoa(va_arg(ap, unsigned long long int));
			}
			else
			{
				if (*p == 'd' || *p == 'i')
					pf->str = ft_lltoa((long long int)va_arg(ap, long int));
				if (*p == 'u')
					pf->str = ft_lltoa((long long int)va_arg(ap, unsigned long int));
			}
		}
		else if (pf->type[0] == 'h')
		{
			if (*p == 'd' || *p == 'i')
				pf->str = ft_lltoa((long long int)va_arg(ap, short int));
			if (*p == 'u')
				pf->str = ft_lltoa((long long int)va_arg(ap, unsigned short int));
		}
		else
		{
			if (*p == 'd' || *p == 'i')
				pf->str = ft_lltoa((long long int)va_arg(ap, int));
			if (*p == 'u')
				pf->str = ft_lltoa((long long int)va_arg(ap, unsigned int));
		}


}
