/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_str_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:18:20 by tamarant          #+#    #+#             */
/*   Updated: 2019/11/26 19:36:52 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		new_num_str(t_pf *pf)
{
	char c;
	char *tmp = NULL; ////отредачить str_join
	int i;

	i = 0;
	c = 't';
	if (!(pf->str = ft_memalloc(pf->str_len + 1)))
		return (0);
	if (pf->symbol == 1)
		c = '0';
	if (pf->symbol == 2 || pf->symbol == 3)
		c = ' ';
//	if (ft_strchr("oxX", pf->type))
//	{
		if (pf->symbol == 1 || pf->symbol == 2)
		{
			while (i < pf->symb_width)
			{
				pf->str[i] = c;
				i++;
			}
		}
		if (ft_strchr("oxX", pf->type) && pf->sharp)
		{
			while (*pf->sharp)
			{
				pf->str[i] = *pf->sharp;
				pf->sharp += 1;
			}
		}
		if (ft_strchr("oxX", pf->type)) //////   ютоа_бэйс
			//tmp = ft_llutoa(pf->num.ulli);
//			pf->type == 'o' ? (tmp = ulltoa_base(pf->num.ulli, 8)) : (tmp = ulltoa_base(pf->num.ulli, 16));
			tmp = pf->tmp_ox;
		if (ft_strchr("di", pf->type))
			tmp = ft_lltoa(pf->num.lli);
		if (pf->type == 'u')
			tmp = ft_llutoa(pf->num.ulli);
		while (*tmp)
		{
			pf->str[i] = *tmp;
			tmp++;
			i++;
		}
		if (pf->symbol == 3)
		{
			while (i < pf->str_len)
			{
				pf->str[i] = c;
				i++;
			}
		}
	//}
	return (pf->str_len);
}

int		str_size(t_pf *pf)
{
	if (ft_strchr("oxX", pf->type))
	{
//		pf->str_len = number_len_ull(pf->num.ulli);
		pf->type == 'o' ? (pf->tmp_ox = ulltoa_base(pf->num.ulli, 8)) : (pf->tmp_ox = ulltoa_base(pf->num.ulli, 16));
		pf->str_len = ft_strlen(pf->tmp_ox);
		if (pf->sharp)
		{
			(pf->type == 'o') ? (pf->str_len += 1) : (pf->str_len += 2);

		}
		/*if (pf->symbol > 0)
		{
			if ((pf->symb_width = pf->width - pf->str_len) > 0)
				pf->str_len += pf->symb_width;
		}*/
	}
	if (ft_strchr("di", pf->type))
		pf->str_len = number_len_ll(pf->num.lli);
	if (pf->type == 'u')
		pf->str_len =number_len_ull(pf->num.ulli);
	if (pf->symbol > 0)
	{
		if ((pf->symb_width = pf->width - pf->str_len) > 0)
			pf->str_len += pf->symb_width;
	}
	return (1);
}

int		save_format(t_pf *pf)
{
	int i = 0;
	while (pf->flags[i] != '\0')
	{
		if (((pf->flags[i] == '0' || pf->flags[i] == ' ') && (pf->width > 0 && !(ft_strchr(pf->flags, '-'))))
			|| (pf->width > 0 && !(ft_strchr(pf->flags, '-'))))
		{
			if (pf->flags[i] == '0')
				pf->symbol = 1;
			else
				pf->symbol = 2;
		}
		if (pf->flags[i] == '-' && pf->width > 0)
			pf->symbol = 3;
		if (pf->flags[i] == '+' && ft_strchr("diu", pf->type))
		{
			if (ft_strchr("di", pf->type))
			{
				if (pf->num.lli >= 0)
					pf->sign = 1;
				else
					pf->sign = 0;
			}
			else
				pf->sign = 1;
		}
		if (pf->flags[i] == '#' && ft_strchr("oxX", pf->type))
		{
			if (pf->type == 'o')
				pf->sharp = "0";
			else if (pf->type == 'x')
				pf->sharp = "0x";
			else if (pf->type == 'X')
				pf->sharp = "0X";
		}
		i++;
	}
	if (pf->symbol == -1  && pf->width > 0)
		pf->symbol = 2;
	return (1);
}