/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 21:17:19 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/17 21:53:27 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	dop_free_end(t_pf *pf, int n)
{
	if (n == 0)
	{
		free(pf->flags);
		pf->flags = NULL;
		pf->counter = 0;
		pf->buf_len = 0;
	}
	else if (n == 1)
		ft_bzero(pf->flags, 6);
}

void	free_chars(t_pf *pf)
{
	if (pf->size)
	{
		free(pf->size);
		pf->size = NULL;
	}
	if (pf->tmp_oxfs)
	{
		free(pf->tmp_oxfs);
		pf->tmp_oxfs = NULL;
	}
	if (pf->str)
	{
		free(pf->str);
		pf->str = NULL;
	}
	if (pf->sharp)
	{
		free(pf->sharp);
		pf->sharp = NULL;
	}
}

void	free_t_pf(t_pf *pf, int n)
{
	free_chars(pf);
	pf->width = 0;
	pf->precision = -1;
	pf->type = '\0';
	pf->str_len = 0;
	pf->percent = 0;
	pf->num.i = 0;
	pf->symbol = -1;
	pf->symb_width = 0;
	pf->prec_width = 0;
	pf->dot = 0;
	pf->plus = 0;
	pf->minus = 0;
	pf->space = 0;
	pf->float_dot = 0;
	dop_free_end(pf, n);
	if (n == 0)
		free(pf);
}
