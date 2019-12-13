/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:36:23 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/12 20:14:04 by tamarant         ###   ########.fr       */
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
	pf->num_len = 0;
	pf->num.i = 0;

	pf->symbol = -1;
	pf->symb_width = 0;
	pf->sign = -1;
	pf->sharp = NULL;
	//pf->num.i = 0;

	pf->prec_width = 0;
	pf->dot = 0;
	pf->plus = 0;
	pf->minus = 0;
	pf->space = 0;
	pf->float_dot = 0;
	//pf->buf_len = 0;

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
	pf->tmp_oxfs = NULL;
	pf->symbol = -1;
	pf->symb_width = 0;
	pf->sign = -1;
	pf->sharp = NULL;
	pf->prec_width = 0;
	pf->dot = 0;
	pf->plus = 0;
	pf->minus = 0;
	pf->space = 0;
	pf->float_dot = 0;
	pf->buf_len = 0;


	return (pf);
}

void	free_t_pf(t_pf *pf)
{
	free(pf->flags);
	pf->flags = NULL;
	if (pf->size)
		free(pf->size);
	pf->size = NULL;
	if (pf->tmp_oxfs)
		free(pf->tmp_oxfs);
	pf->tmp_oxfs = NULL;
	if (pf->str)
		free(pf->str);
	if (pf->sharp)
		free(pf->sharp);
	pf->size = NULL;
	pf->width = 0;
	pf->precision = -1; ////
	pf->type = '\0';
	pf->str_len = 0;
	pf->str = NULL;
	pf->percent = 0;
	pf->counter = 0;
	pf->num.i = 0;
	pf->tmp_oxfs = NULL;
	pf->symbol = -1;
	pf->symb_width = 0;
	pf->sign = -1;
	pf->sharp = NULL;
	pf->prec_width = 0;
	pf->dot = 0;
	pf->plus = 0;
	pf->minus = 0;
	pf->space = 0;
	pf->float_dot = 0;
	pf->buf_len = 0;
	free(pf);
}

void	ft_printf_end(t_pf *pf, va_list ap)
{
	free_t_pf(pf);
	va_end(ap);
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
		if (*p == '%' && *(p + 1) != '%' ) //// %%2 %%%3 %%%%4
		{
			if (pf_format(pf, &p, ap) == -1)
			{
				ft_printf_end(pf, ap);
				return (0);
			}
			set_null(pf);
		}
		else
		{
			pf->counter += new_str(pf, &p);
			set_null(pf);
		}
	}
	sum = pf->counter;
	ft_printf_end(pf, ap);
	return (sum);
}