/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:36:23 by tamarant          #+#    #+#             */
/*   Updated: 2019/10/24 21:04:37 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf	*new_t_pf(void)
{
	t_pf *pf;

	if (!(pf = (t_pf*)malloc(sizeof(t_pf))))
		return (NULL);
	if (!(pf->flags = ft_memalloc(6)))
		return (NULL);
	if (!(pf->size = ft_memalloc(3)))
		return (NULL);
	pf->width = 0;
	pf->precision = 0;
	pf->type = '\0';
	pf->str_len = 0;
	pf->str = NULL;
	pf->percent = 0;
	pf->counter = 0;
	pf->num.i = 0;
	return (pf);
}

void	free_t_pf(t_pf *pf)
{
	free(pf->flags);
	pf->flags = NULL;
	free(pf->size);
	pf->size = NULL;
	free(pf);
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
			if (pf->counter += pf_format(pf, &p, ap) <= 0)
				return (0);
			while (*p != ' ' && *p != '%' && *p != '\0')
				p++;
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
			p += pf->str_len + pf->percent;
		}
	}
	free_t_pf(pf);
	return (pf->counter);
}