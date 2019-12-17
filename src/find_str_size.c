/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_str_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:35:41 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/17 21:27:12 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		find_sp_width_s(t_pf *pf)
{
	pf->prec_width = 0;
	if ((pf->symb_width = pf->width - pf->str_len) > 0)
		pf->str_len += pf->symb_width;
}

static void		find_symb_prec_width(t_pf *pf)
{
	int	sharp_len;

	sharp_len = 0;
	if (pf->type == 'o' && pf->sharp)
		sharp_len = 1;
	if (ft_strchr("fF", pf->type))
	{
		if ((pf->symb_width = pf->width - pf->str_len) > 0)
			pf->str_len += pf->symb_width;
	}
	else if (ft_strchr("sScC", pf->type))
		find_sp_width_s(pf);
	else
	{
		if ((pf->prec_width = pf->precision - pf->num_len - sharp_len) > 0 &&
			(pf->symb_width = pf->width - pf->str_len - pf->prec_width) >= 0)
			pf->str_len += pf->symb_width + pf->prec_width;
		else if ((pf->symb_width = pf->width - pf->str_len) > 0)
			pf->str_len += pf->symb_width;
		else if (pf->prec_width > 0)
			pf->str_len += pf->prec_width;
	}
}

static void		pox_size(t_pf *pf)
{
	if ((((pf->precision <= 0 && pf->dot) || pf->sharp) && pf->num.ulli == 0
	&& pf->type != 'p')
	|| (pf->precision <= 0 && pf->dot && pf->num.ulli == 0 && pf->type == 'p'))
	{
		pf->num_len = 0;
		pf->tmp_oxfs = NULL;
	}
	else
	{
		pf->tmp_oxfs = ulltoa_base(pf->num.ulli, (pf->type == 'o') ? 8 : 16);
		if (pf->type == 'X')
			pf->tmp_oxfs = to_uppercase(pf->tmp_oxfs);
		pf->num_len = ft_strlen(pf->tmp_oxfs);
	}
	pf->str_len += pf->num_len;
	if (pf->sharp)
		(pf->type == 'o') ? (pf->str_len += 1) : (pf->str_len += 2);
}

static void		dius_size(t_pf *pf, int n)
{
	if (n == 1)
	{
		if (pf->num.ulli == 0 && pf->precision <= 0 && pf->dot)
			pf->num_len = 0;
		else if (ft_strchr("di", pf->type))
		{
			pf->num_len = number_len_ll(pf->num.lli);
			if (!pf->plus && !pf->minus)
				pf->str_len += pf->space;
		}
		else
			pf->num_len = number_len_ull(pf->num.ulli);
		pf->str_len += pf->num_len + pf->minus + pf->plus;
	}
	else
	{
		pf->num_len = ft_strlen(pf->tmp_oxfs);
		if (pf->precision <= 0 && pf->dot)
			pf->num_len = 0;
		else if (pf->precision > 0 && pf->precision < pf->num_len)
			pf->num_len = pf->precision;
		else if (pf->width > 0 && pf->dot && pf->precision <= 0)
			pf->num_len = 0;
		pf->str_len += pf->num_len;
	}
}

int				find_str_size(t_pf *pf)
{
	if (ft_strchr("poxX", pf->type))
		pox_size(pf);
	if (ft_strchr("diu", pf->type))
		dius_size(pf, 1);
	if (ft_strchr("fF", pf->type))
	{
		if (pf->precision == 0 && pf->flags && ft_strchr(pf->flags, '#'))
			pf->float_dot = 1;
		if (pf->space && !pf->minus && !pf->plus)
			pf->str_len += 1;
		pf->num_len = (int)ft_strlen(pf->tmp_oxfs);
		pf->str_len += pf->num_len + pf->plus + pf->minus + pf->float_dot;
	}
	if (pf->type == 's' || pf->type == 'S')
		dius_size(pf, 2);
	if (pf->type == 'c' || pf->type == 'C' || pf->type == '%')
	{
		pf->num_len = 1;
		pf->str_len = 1;
	}
	if (pf->symbol > 0 || pf->precision > 0)
		find_symb_prec_width(pf);
	return (1);
}
