/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:36:23 by tamarant          #+#    #+#             */
/*   Updated: 2019/11/29 17:21:25 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_null(t_pf *pf)
{
	ft_bzero(pf->flags, 6);
	if (pf->size)
		free(pf->size);
	pf->size = NULL;
	pf->width = 0;
	pf->precision = -1; ////
	pf->type = '\0';
	pf->str_len = 0;
	free(pf->str);
	pf->str = NULL;
	pf->percent = 0;
	pf->num.i = 0;

	pf->symbol = -1;
	pf->symb_width = 0;
	pf->sign = -1;
	pf->sharp = NULL;

	pf->prec_width = 0;
}

t_pf	*new_t_pf(void)
{
	t_pf *pf;

	if (!(pf = (t_pf*)malloc(sizeof(t_pf))))
		return (NULL);
	if (!(pf->flags = ft_memalloc(6)))
		return (NULL);
	pf->size = NULL;
	pf->width = 0;
	pf->precision = -1; ////
	pf->type = '\0';
	pf->str_len = 0;
	pf->str = NULL;
	pf->percent = 0;
	pf->counter = 0;
	pf->num.i = 0;
	pf->tmp_ox = NULL;
	pf->symbol = -1;
	pf->symb_width = 0;
	pf->sign = -1;
	pf->sharp = NULL;

	pf->prec_width = 0;
	return (pf);
}

void	free_t_pf(t_pf *pf)
{
	free(pf->flags);
	pf->flags = NULL;
	if (pf->size)
		free(pf->size);
	pf->size = NULL;
	free(pf->tmp_ox);
	pf->tmp_ox = NULL;
	if (pf->str)
		free(pf->str);
}

int 	ft_printf(char *format, ...)
{
	va_list ap;
	char	*p;
	t_pf	*pf;
	int 	sum;
	
	va_start(ap, format);
	p = format;
	if (!(pf = new_t_pf()))
		return (0);
	while (*p != '\0')
	{
		if (*p == '%')
		{
			if (pf_format(pf, &p, ap) == -1)
			{
				free_t_pf(pf);
				va_end(ap);
				return (-1);
			}
			set_null(pf);
		}
		else
		{
			pf->counter += new_str(pf, &p);
			//p += pf->str_len + pf->percent;
			set_null(pf);
		}
	}
	sum = pf->counter;
	free_t_pf(pf);
	free(pf);
	va_end(ap);
	return (sum);
}