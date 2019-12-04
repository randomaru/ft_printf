/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:09:48 by tamarant          #+#    #+#             */
/*   Updated: 2019/11/29 17:01:26 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_flags(t_pf *pf, char **p)
{
	int i;

	i = 0;
	while (ft_strchr("-+ #0", **p) )
	{
		if (**p == '-')
			pf->flags[i] = '-';
		if (**p == '+')
			pf->flags[i] = '+';
		if (**p == ' ')
			pf->flags[i] = ' ';
		if (**p == '#')
			pf->flags[i] = '#';
		if (**p == '0')
			pf->flags[i] = '0';
		i++;
		*p += 1;
	}
}

void	find_width(t_pf *pf, char **p)
{
	pf->width = ft_atoi(*p);
	*p += number_len(pf->width);
}

void	find_precision(t_pf *pf, char **p)
{
	++(*p);
	pf->precision = ft_atoi(*p);
	*p += number_len(pf->precision);
}

void	find_size(t_pf *pf, char **p)
{
	if ((**p == 'h' && *(*p + 1) == 'h') || (**p == 'l' && *(*p + 1) == 'l'))
	{
		**p == 'h' ? (pf->size = ft_strdup("hh")) : (pf->size = ft_strdup("ll"));
		*p += 2;
	}
	else if (**p == 'h' || **p == 'l' )
	{
		**p == 'h' ? (pf->size = ft_strdup("h")) : (pf->size = ft_strdup("l"));
		*p += 1;
	}
}
