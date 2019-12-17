/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_final.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 20:18:07 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/17 19:43:53 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		fill_with_arg(t_pf *pf, char *str, int *i, char *tmp)
{
	int		k;

	k = 0;
	if (pf->prec_width > 0)
		fill_with_symb(str, &*i, '0', pf->prec_width);
	if ((pf->type == 's' || pf->type == 'S') && tmp)
	{
		while (k < pf->num_len)
		{
			str[*i] = tmp[k];
			k++;
			*i += 1;
		}
	}
	else if (pf->type == 'c' || pf->type == 'C' || pf->type == '%')
		fill_with_symb(str, &*i, pf->num.c, 1);
	else if (tmp && !(ft_strchr("sScC", pf->type)))
	{
		while (k < pf->num_len)
		{
			str[*i] = tmp[k];
			k++;
			*i += 1;
		}
	}
}

static void		fill_left_part(t_pf *pf, char *str, int *i, char c)
{
	if (pf->symbol == 2 && pf->symb_width > 0)
		fill_with_symb(str, &*i, c, pf->symb_width);
	if (ft_strchr("difFu", pf->type) && (pf->plus || pf->minus))
		(pf->minus) ? (fill_with_symb(str, &*i, '-', 1))
		: (fill_with_symb(str, &*i, '+', 1));
	if (pf->space && !pf->minus && !pf->plus && pf->type != '%')
		fill_with_symb(str, &*i, ' ', 1);
	if (ft_strchr("poxX", pf->type) && pf->sharp)
		fill_with_sharp(pf, str, &*i);
	if (pf->symbol == 1 && pf->symb_width > 0)
		fill_with_symb(str, &*i, c, pf->symb_width);
}

static void		fill_right_part(t_pf *pf, char *str, int *i, char c)
{
	if (pf->float_dot)
		fill_with_symb(str, &*i, '.', 1);
	if (pf->symbol == 3 && pf->symb_width > 0)
		fill_with_symb(str, &*i, c, pf->str_len);
}

int				fill_final(t_pf *pf, char *str, int n, int len)
{
	char	c;
	char	*tmp;
	int		i;

	i = 0;
	if (n == 2)
	{
		if (!(str = ft_memalloc(pf->str_len + 1)))
			return (-1);
	}
	if (n == 1)
		i += len;
	c = (pf->symbol == 1) ? '0' : ' ';
	fill_left_part(pf, str, &i, c);
	tmp = find_tmp(pf);
	fill_with_arg(pf, str, &i, tmp);
	fill_right_part(pf, str, &i, c);
	if (tmp)
		free(tmp);
	if (n == 1)
		(pf->buf_len += pf->str_len);
	else
		pf->str = str;
	return ((n == 1) ? pf->buf_len : pf->str_len);
}
