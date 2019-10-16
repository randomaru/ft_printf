/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:36:23 by tamarant          #+#    #+#             */
/*   Updated: 2019/10/16 19:26:53 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf	*new_t_pf(void)
{
	t_pf *pf;

	if (!(pf = (t_pf*)malloc(sizeof(t_pf))))
		return (NULL);
	if (!(pf->type = ft_memalloc(3)))
		return (NULL);
	pf->flag = '1';
	pf->width = 0;
	return (pf);
}

int 	ft_printf(char *apFormat, ...)
{
	va_list ap;
	char	*p;
	t_pf	*pf;

	va_start(ap, apFormat);
	p = apFormat;

	pf = new_t_pf();
	while (*p != '\0')
	{
		if (*p == '%')
		{
			format_flags(p, ap, pf);
			format(pf);
			ft_putstr(pf->result);
			while (*p != ' ' && *p != '\0')
				p++;
			p--;
		}
		else
		{
			ft_putchar(*p);
		}
		p++;
	}
	return (0);
}