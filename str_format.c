/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:55:11 by tamarant          #+#    #+#             */
/*   Updated: 2019/10/24 15:32:27 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	to_str(t_pf *pf)
{
	if (pf->type == 'd' || pf->type == 'i')
		pf->str = ft_lltoa(pf->num.lli);
	if (ft_strchr("uoxX", pf->type))
		pf->str = ft_llutoa(pf->num.ulli);
	pf->str_len = ft_strlen(pf->str);
}

void	str_format(t_pf *pf)
{
	int i = 0;
	int width;
	char *tmp;

	while (pf->flags[i] != '\0')
	{
		if (pf->flags[i] == '#' && ft_strchr("oxX", pf->type))
		{
			if (pf->type == 'o')
				pf->str = ft_strjoin("0", pf->str);
			else if (pf->type == 'x')
				pf->str = ft_strjoin("0x", pf->str);
			else if (pf->type == 'x')
				pf->str = ft_strjoin("0X", pf->str);
		}
		if (pf->flags[i] == '+' && !(ft_strchr("oxXscpu", pf->type)))
		{
			if (pf->num.lli > 0 || pf->num.lli == 0 )
				ft_strjoin("+", pf->str);
			else
				ft_strjoin("-", pf->str);
			pf->str_len = ft_strlen(pf->str);
		}
		if (pf->flags[i] == '-' && pf->width > 0)
		{
			width = pf->width - pf->str_len;
			if (!(tmp = ft_memalloc(width + 1)))
				return ; ////ERROR
			while (width--)
				*tmp = ' ';
			ft_strjoin(pf->str, tmp);
		}
		if (pf->flags[i] == '0' && pf->width > 0 && !(ft_strchr(pf->flags, '-')))
		{
			width = pf->width - pf->str_len;
			if (!(tmp = ft_memalloc(width + 1)))
				return ; ////ERROR
			while (width--)
				*tmp = '0';
			ft_strjoin(tmp, pf->str);
		}
	}
}