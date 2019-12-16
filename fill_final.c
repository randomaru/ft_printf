/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_final.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 20:18:07 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/16 21:46:50 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*find_tmp(t_pf *pf)
{
	char *tmp;

	tmp = NULL;
	if (pf->type == '%')
		pf->num.c = '%';
	if (pf->type == 's')
	{
		if (pf->precision <= 0 && pf->dot)
		{
			tmp = NULL;
		}
		else
			tmp = ft_strdup(pf->tmp_oxfs);
	}
	if (pf->type == 'f')
		tmp = ft_strdup(pf->tmp_oxfs);
	if (ft_strchr("poxX", pf->type))
		tmp = ft_strdup(pf->tmp_oxfs);
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

static void		fill_with_symb(char *str, int *i, char c, int len)
{
	len += *i;
	while (*i < len)
	{
		str[*i] = c;
		*i += 1;
	}
}

static void		fill_sign(char *str, int *i, char sign)
{
	str[*i] = sign;
	*i += 1;
}

static void		fill_with_sharp(t_pf *pf, char *str, int *i)
{
	int j;

	j = 0;
	while (pf->sharp[j] != '\0')
	{
		str[*i] = pf->sharp[j];
		j++;
		*i += 1;
	}
}

static void		fill_with_tmp(t_pf *pf, char *str, int *i, char *tmp)
{
	int		k;

	k = 0;
	if (pf->prec_width > 0)
		fill_with_symb(str, &*i, '0', pf->prec_width);
	if (pf->type == 's' && tmp)
	{
		while (k < pf->num_len)
		{
			str[*i] = tmp[k];
			k++;
			*i += 1;
		}
	}
	else if (pf->type == 'c' || pf->type == '%')
		fill_with_symb(str, &*i, pf->num.c, 1);
	else if (tmp && pf->type != 's' && pf->type != 'c')
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
	if (ft_strchr("difu", pf->type) && (pf->plus || pf->minus))
		(pf->minus) ? (fill_sign(str, &*i, '-')) : (fill_sign(str, &*i, '+'));
	if (pf->space && !pf->minus && !pf->plus && pf->type != '%')
		fill_sign(str, &*i, ' ');
	if (ft_strchr("poxX", pf->type) && pf->sharp)
		fill_with_sharp(pf, str, &*i);
	if (pf->symbol == 1 && pf->symb_width > 0)
		fill_with_symb(str, &*i, c, pf->symb_width);
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
	fill_with_tmp(pf, str, &i, tmp);
	if (pf->float_dot)
		fill_sign(str, &i, '.');
	if (pf->symbol == 3 && pf->symb_width > 0)
		fill_with_symb(str, &i, c, pf->str_len);
	if (tmp)
		free(tmp);
	(n == 1) ? (pf->buf_len += pf->str_len) : (pf->str = str);
	return ((n == 1) ? pf->buf_len : pf->str_len);
}
