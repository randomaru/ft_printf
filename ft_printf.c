/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:36:23 by tamarant          #+#    #+#             */
/*   Updated: 2019/10/14 19:23:33 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	ft_printf(char *apFormat, ...)
{
	va_list ap;
	char	*p;
	t_pf	*pf;

	va_start(ap, apFormat);
	p = apFormat;

	pf = (t_pf*)malloc(sizeof(t_pf));
	while (*p != '\0')
	{
		if (*p == '%')
		{
			format_flags(p, ap, pf);
		}
		else
		{
			ft_putchar(*p);
		}
		p++;
	}
	return (0);
}