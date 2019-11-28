/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:36:23 by tamarant          #+#    #+#             */
/*   Updated: 2019/11/28 19:24:16 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_null(t_pf *pf)
{
	ft_bzero(pf->flags, 6);
	ft_bzero(pf->size, 3);

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
	if (!(pf->size = ft_memalloc(3)))
		return (NULL);
	pf->width = 0;
	pf->precision = -1; ////
	pf->type = '\0';
	pf->str_len = 0;
	pf->str = NULL;
	pf->percent = 0;
	pf->counter = 0;
	pf->num.i = 0;

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
			if (pf_format(pf, &p, ap) == 0)
				return (0);
			set_null(pf);
		}
		else
		{
			pf->counter += new_str(pf, &p);
			//p += pf->str_len + pf->percent;
			set_null(pf);
		}
	}
	free_t_pf(pf);
	return (pf->counter);
}