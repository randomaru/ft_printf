/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_final_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:58:21 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/06 19:23:43 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		fill_with_symb(t_pf *pf, int *i, char c, int len)
{
	len += *i;
	while (*i < len)
	{
		pf->str[*i] = c;
		*i += 1;
	}
}

static void		fill_sign(t_pf *pf, int *i, char sign)
{
	pf->str[*i] = sign;
	*i += 1;
}

static void		fill_with_sharp(t_pf *pf, int *i)
{
	while (*pf->sharp)
	{
		pf->str[*i] = *pf->sharp;
		pf->sharp += 1;
		*i += 1;
	}
}

static char		*find_tmp(t_pf *pf)
{
	char *tmp;
	tmp = NULL;
	if (ft_strchr("oxX", pf->type))
		tmp = ft_strdup(pf->tmp_ox);
	if (ft_strchr("di", pf->type))
		if (!(tmp = ft_lltoa(pf->num.lli)))
			return (NULL);
	if ((pf->precision <= 0 && pf->dot) && pf->num.lli == 0)
		tmp = NULL;
	if (pf->type == 'u')
	{
		if (pf->num.ulli == 0 && (pf->precision <= 0 && pf->dot))
			tmp = NULL;
		else
			tmp = ft_ulltoa(pf->num.ulli);
	}
	return (tmp);
}

int		fill_final_str(t_pf *pf)
{
	char c;
	char *tmp = NULL; ////отредачить str_join
	int i;
	int k;

	k = 0;
	i = 0;
	c = 't';
	if (!(pf->str = ft_memalloc(pf->str_len + 1)))
		return (-1);
	if (pf->symbol == 1)
		c = '0';
	if (pf->symbol == 2 || pf->symbol == 3)
		c = ' ';
	if (pf->symbol == 2)
		fill_with_symb(pf, &i, c, pf->symb_width);
	if (ft_strchr("dif", pf->type) && (pf->plus || pf->minus))
		(pf->minus) ? (fill_sign(pf, &i, '-')) : (fill_sign(pf, &i, '+'));
	if (pf->space && !pf->minus && !pf->plus)
		fill_sign(pf, &i, ' ');
	if (ft_strchr("oxX", pf->type) && pf->sharp)
		fill_with_sharp(pf, &i);
	if (pf->symbol == 1)
		fill_with_symb(pf, &i, c, pf->symb_width);
	tmp = find_tmp(pf);
	if (pf->prec_width > 0)
		fill_with_symb(pf, &i, '0', pf->prec_width);
	if (tmp)
	{
		while (tmp[k] != '\0')
		{
			pf->str[i] = tmp[k];
			k++;
			i++;
		}
	}
	if (pf->symbol == 3)
		fill_with_symb(pf, &i, c, pf->str_len - i);
	if (tmp)
		free(tmp);
	return (pf->str_len);
}
