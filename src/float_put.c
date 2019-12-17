/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:21:13 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/17 18:25:03 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		put_if_precision_null(t_float *fl, t_pf *pf, LD num)
{
	real_okrugl(fl, pf, num);
	fl->pos = 0;
	while (*(fl->frst + fl->pos) != '\0')
	{
		*(fl->res + fl->pos) = *(fl->frst + fl->pos);
		fl->pos++;
	}
}

void		put_if_precision_not_null(t_float *fl, t_pf *pf, LD num)
{
	real_okrugl(fl, pf, num);
	fl->pos = 0;
	while (*(fl->frst + fl->pos) != '\0')
	{
		*(fl->res + fl->pos) = *(fl->frst + fl->pos);
		fl->pos++;
	}
	*(fl->res + fl->pos) = '.';
	fl->pos++;
	while (*(fl->scnd + fl->i) != '\0')
	{
		*(fl->res + fl->pos) = *(fl->scnd + fl->i);
		fl->pos++;
		fl->i++;
	}
}

char		*put_in_str(t_pf *pf, t_float *fl, LD num)
{
	if (!(fl->res = ft_memalloc((ft_strlen(fl->frst))
			+ ((pf->precision == 0) ? 0 : (ft_strlen(fl->scnd) + 1))
			+ (((*pf->flags == '#') && pf->precision == 0)
					? -1 : 0) + 1)))
		return (NULL);
	if (pf->precision == 0)
		put_if_precision_null(fl, pf, num);
	else
		put_if_precision_not_null(fl, pf, num);
	*(fl->res + fl->pos) = '\0';
	return (fl->res);
}
