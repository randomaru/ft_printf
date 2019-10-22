/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:36:23 by tamarant          #+#    #+#             */
/*   Updated: 2019/10/22 18:01:06 by tamarant         ###   ########.fr       */
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
	pf->width = 0;
	pf->str_len = 0;
	pf->slash_n = 0;
	pf->counter = 0;
	return (pf);
}

int 	ft_printf(char *apFormat, ...)
{
	va_list ap;
	char	*p;
	t_pf	*pf;
	int 	i = 0;

	va_start(ap, apFormat);
	p = apFormat;

	pf = new_t_pf();
	while (*p != '\0')
	{
		if (*p == '%')
		{
			/*tmp_format_flags(p, ap, pf);
			tmp_format(pf);
			ft_putstr(pf->str);
			while (*p != ' ' && *p != '\0')
				p++;
			p--;*/ ///tmp
			pf->counter += pf_format(pf, p, ap);
		}
		else
		{
			/*i = 0;
			while (*(p + i) != '\0')
			{
				pf->str_len += 1;
				if (*(p + i) == '%' && *(p + i + 1) == '%')
					i++;
				if (*(p + i) == '%' && *(p + i + 1) != '%')
					break ;
				i++;
			}
			pf->str = (char*)malloc(sizeof(char) * (pf->str_len + 1));
			i = 0;
			while (i < pf->str_len)
			{
				if (*p == '%')
				{
					pf->str[i] = '%';
					i++;
					p += 2;
				}
				else
				{
					pf->str[i] = *p;
					i++;
					p++;
				}
			}
			pf->str[i] = '\0';
			ft_putstr(pf->str);*/ ///tmp
			pf->counter += new_str(pf, p);
			p += pf->str_len + pf->slash_n;
		}
		//p++;
	}
	return (pf->counter);
}