/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:09:48 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/16 21:11:49 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	find_flags(t_pf *pf, char **p)
{
	int i;

	i = 0;
	while (ft_strchr("-+ #0", **p))
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
	while (!(ft_strchr("LlhdifFouxXsScCp%", **p)))
		*p += 1;
}

void	find_size(t_pf *pf, char **p)
{
	if ((**p == 'h' && *(*p + 1) == 'h') || (**p == 'l' && *(*p + 1) == 'l'))
	{
		pf->size = ft_strdup((**p == 'h') ? "hh" : "ll");
		*p += 2;
	}
	else if (**p == 'h' || **p == 'l')
	{
		pf->size = ft_strdup((**p == 'h') ? "h" : "l");
		*p += 1;
	}
	else if (**p == 'L')
	{
		pf->size = ft_strdup("L");
		*p += 1;
	}
}
