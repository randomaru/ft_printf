/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:33:00 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/16 15:17:12 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	find_sign(t_pf *pf)
{
	if (pf->type == 'f')
	{
		if (ft_strchr(pf->flags, '+') && pf->num.ld >= 0 && !pf->minus)
			pf->plus = 1;
	}
	else
	{
		if (ft_strchr(pf->flags, '+') && ft_strchr("di", pf->type) && pf->num.lli >= 0)
			pf->plus = 1;
		if (ft_strchr("di", pf->type) && pf->num.lli < 0)
		{
			if (pf->num.lli == LONG_MIN)
			{
				pf->type = 'u';
				pf->minus = 1;
			}

			else
				pf->num.lli = -pf->num.lli;
			pf->minus = 1;
		}
	}
}

static void	save_sharp(t_pf *pf)
{
	if (pf->type == 'o' )
		pf->sharp = ft_strdup("0");
	else if ((pf->type == 'x' && pf->num.i != 0) || pf->type == 'p')
		pf->sharp = ft_strdup("0x");
	else if (pf->type == 'X' && pf->num.i != 0)
		pf->sharp = ft_strdup("0X");

}

int		parse_format(t_pf *pf)
{
	int i;

	i = 0;
	find_sign(pf);
	if (pf->type != 's' && pf->precision > pf->width)
		pf->width = 0;
	if (pf->flags)
	{
		if (((ft_strchr(pf->flags,'0') || ft_strchr(pf->flags,' '))
			 && (pf->width > 0 && !(ft_strchr(pf->flags, '-'))))
			|| (pf->width > 0 && !(ft_strchr(pf->flags, '-'))))
		{
			if (ft_strchr("fF", pf->type))
			{
				if (ft_strchr(pf->flags,'0') && (ft_isinf(pf->num.ld) || ft_isnan(pf->num.ld)))
					pf->symbol = 2;
				else
					(ft_strchr(pf->flags,'0')) ? (pf->symbol = 1) : (pf->symbol = 2);
			}
			else
				(ft_strchr(pf->flags,'0')) ? (pf->symbol = 1) : (pf->symbol = 2);
		}
	}
	if (pf->type == 'p')
		save_sharp(pf);
	while (pf->flags[i] != '\0')
	{
		if (pf->flags[i] == '-' && pf->width > 0)
			pf->symbol = 3;
		if (pf->flags[i] == ' ' && !ft_isnan(pf->num.ld) && !ft_is_minus_inf(pf->num.ld) && pf->type != 'u' && pf->type != 'c')
			pf->space = 1;
		if ((pf->flags[i] == '#' && ft_strchr("oxX", pf->type)))
			save_sharp(pf);
		i++;
	}
	if (pf->precision > 0 && pf->width > 0 && pf->type != 'f')
		(ft_strchr(pf->flags, '-')) ? (pf->symbol = 3) : (pf->symbol = 2);
	if (pf->symbol == -1  && pf->width > 0)
		pf->symbol = 2;
	return (1);
}
