/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 17:44:26 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/17 18:45:31 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*get_integer(LD num, t_float *fl)
{
	fl->first = (ULL)num;
	if (!(fl->frst = pf_itoa(fl->first)))
		return (NULL);
	return (fl->frst);
}

char		*get_decimal(LD num, t_pf *pf, t_float *fl)
{
	if (!(fl->scnd = videl_memory_for_decimal(pf, fl)))
		return (NULL);
	((pf->precision == 19) ? (fl->second = (ULL)((num - fl->first) *
			ft_pow(10, pf->precision))) :
			(fl->second = (ULL)((num - fl->first) *
					ft_pow(10, pf->precision + 1))));
	if ((num - fl->first < 0.1) && pf->precision > 1)
		fl->scnd = okrugl((LD)(num - fl->first +
				ft_pow_double(0.1, pf->precision)), fl->i,
						fl, pf->precision - 1);
	if (pf->precision + 1 == 1)
		fill_char_from_int(fl->second, fl->scnd);
	else
	{
		if (!(fl->scnd = make_decimal(fl, pf)))
			return (NULL);
	}
	return (fl->scnd);
}

int			work_with_parts(t_float *fl, LD num, t_pf *pf)
{
	if (fl->not_f == 0)
	{
		if (1 / num == (-1.0 / 0.0))
			pf->minus = 1;
		else
			pf->minus = ((num < 0) ? 1 : 0);
		((pf->minus == 1) ? ((num *= -1) && (fl->pos = 1)) : 0);
		((pf->precision == -1) ? (pf->precision = 6) : 0);
		if (!(fl->frst = get_integer(num, fl)))
			return (-1);
		if (!(fl->scnd = get_decimal(num, pf, fl)))
			return (-1);
		if (fl->scnd != NULL && pf->precision > 0)
			(((int)ft_strlen(fl->scnd) < pf->precision) ?
			(fl->scnd = add_null(pf, fl, 1)) : 0);
		if (!(fl->res = put_in_str(pf, fl, num)))
			return (-1);
	}
	return (0);
}

int			handle_inf_nan(LD num, t_pf *pf, t_float *fl)
{
	if ((1.0 / 0.0) == num)
	{
		if (!(fl->res = (pf->type == 'F' ? (ft_strdup("INF"))
				: (ft_strdup("inf")))))
			return (-1);
		return (1);
	}
	else if ((-1.0 / 0.0) == num)
	{
		if (!(fl->res = (pf->type == 'F' ? (ft_strdup("-INF"))
				: (ft_strdup("-inf")))))
			return (-1);
		return (1);
	}
	else if (num != num)
	{
		if (!(fl->res = (pf->type == 'F' ? (ft_strdup("NAN"))
				: (ft_strdup("nan")))))
			return (-1);
		return (1);
	}
	return (0);
}

int			display_f(t_pf *pf)
{
	LD			num;
	t_float		*fl;

	num = pf->num.ld;
	if (!(fl = new_t_float()))
		return (0);
	fl->not_f = handle_inf_nan(num, pf, fl);
	if (fl->not_f == 0)
	{
		float_string_helper(fl, pf, num);
		if (fl->res == NULL && work_with_parts(fl, num, pf) == -1)
			return (-1);
	}
	else if (fl->not_f == -1)
		return (-1);
	if (!(pf->tmp_oxfs = ft_strdup(fl->res)))
		return (-1);
	free_t_float(fl);
	return (1);
}
