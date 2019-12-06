/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:33:00 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/06 17:33:00 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	find_sign(t_pf *pf)
{
	if (ft_strchr(pf->flags, '+') && ft_strchr("dif", pf->type) && pf->num.lli >= 0)
		pf->plus = 1;
	if (ft_strchr("dif", pf->type) && pf->num.lli < 0)
	{
		pf->num.lli *= -1;
		pf->minus = 1;
	}
}

static void	save_sharp(t_pf *pf)
{
	if (pf->type == 'o' )//&& pf->num.ulli != 0)
		pf->sharp = ft_strdup("0");
	else if (pf->type == 'x' && pf->num.i != 0)
		pf->sharp = ft_strdup("0x");
	else if (pf->type == 'X' && pf->num.i != 0)
		pf->sharp = ft_strdup("0X");

}

int		save_format(t_pf *pf)
{
	int i;

	i = 0;
	find_sign(pf);
	while (pf->flags[i] != '\0')
	{
		if (((pf->flags[i] == '0' || pf->flags[i] == ' ')
			 && (pf->width > 0 && !(ft_strchr(pf->flags, '-'))))
			|| (pf->width > 0 && !(ft_strchr(pf->flags, '-'))))
		{
			(pf->flags[i] == '0') ? (pf->symbol = 1) : (pf->symbol = 2);
		}
		if (pf->flags[i] == '-' && pf->width > 0)
			pf->symbol = 3;
		if (pf->flags[i] == ' ')
			pf->space = 1;
		if (pf->flags[i] == '#' && ft_strchr("oxX", pf->type))
			save_sharp(pf);
		i++;
	}
	if (pf->precision > 0 && pf->width > 0)
		(ft_strchr(pf->flags, '-')) ? (pf->symbol = 3) : (pf->symbol = 2);
	if (pf->symbol == -1  && pf->width > 0)
		pf->symbol = 2;
	return (1);
}
