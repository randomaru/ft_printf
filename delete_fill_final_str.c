/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_final_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:58:21 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/16 21:11:59 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
void print_res(char *str, int len, int n)
{
	if ((n == 1 && *str) || n == 2)
		write(1, str, len);
*/
/*	else if (n == 2)
		write(1, str, len);*//*

}
*/

/*void check_buf(t_pf *pf, char **p)
{
	if (pf->type)
	{
		if (pf->str_len + pf->buf_len < BU_SIZE)
		{
			fill_buff(pf);
			if (pf->str_len + pf->buf_len == BU_SIZE - 1)
			{
				print_res(pf->buff, pf->buf_len, 2);
				pf->buf_len = 0;
			}

		}
		else if (pf->str_len + pf->buf_len >= BU_SIZE)
		{
			if (pf->buf_len > 0)
			{
				print_res(pf->buff, pf->buf_len, 2);
				pf->buf_len = 0;
				fill_buff(pf);
			}
			else
			{
				fill_final_str(pf);
				print_res(pf->str, pf->str_len, 1);

			}
		}
		if (**p == '\0' && pf->buf_len > 0)
		{
			print_res(pf->buff, pf->buf_len, 2);
		}
	}
	else
	{
		if (pf->str_len + pf->buf_len <= BU_SIZE)
		{
			fill_str_buff(pf, &*p);
			if (pf->str_len + pf->buf_len == BU_SIZE)
			{
				print_res(pf->buff, pf->buf_len, 2);
				pf->buf_len = 0;
			}

		}
		else if (pf->str_len + pf->buf_len > BU_SIZE)
		{
			if (pf->buf_len > 0)
			{
				print_res(pf->buff, pf->buf_len, 2);
				pf->buf_len = 0;
				fill_str_buff(pf, &*p);
			}
			else
			{
				fill_str_str(pf, &*p);
				print_res(pf->str, pf->str_len, 1);
			}
		}
		if (**p == '\0' && pf->buf_len > 0)
		{
			print_res(pf->buff, pf->buf_len, 2);
		}
	}

}*/
/*

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
	int j;

	j = 0;
	while (pf->sharp[j] != '\0')
	{
		pf->str[*i] = pf->sharp[j];
		j++;
		*i += 1;
	}
}

char		*find_tmp(t_pf *pf)
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
	if (pf->symbol == 2 && pf->symb_width > 0)
		fill_with_symb(pf, &i, c, pf->symb_width);
	if (ft_strchr("difu", pf->type) && (pf->plus || pf->minus))
		(pf->minus) ? (fill_sign(pf, &i, '-')) : (fill_sign(pf, &i, '+'));
	if (pf->space && !pf->minus && !pf->plus)
			fill_sign(pf, &i, ' ');
	if (ft_strchr("poxX", pf->type) && pf->sharp)
		fill_with_sharp(pf, &i);
	if (pf->symbol == 1 && pf->symb_width > 0)
		fill_with_symb(pf, &i, c, pf->symb_width);
	tmp = find_tmp(pf);
	if (pf->prec_width > 0)
		fill_with_symb(pf, &i, '0', pf->prec_width);
	if (pf->type == 's' && tmp)
	{
		while (k < pf->num_len)
		{
			pf->str[i] = tmp[k];
			k++;
			i++;
		}
	}
	else if (pf->type == 'c' || pf->type == '%')
		fill_with_symb(pf, &i, pf->num.c, 1);
	else if (tmp && pf->type != 's' && pf->type != 'c')
	{
		while (tmp[k] != '\0')
		{
			pf->str[i] = tmp[k];
			k++;
			i++;
		}
	}
	if (pf->float_dot)
		fill_sign(pf, &i, '.');
	if (pf->symbol == 3 && pf->symb_width > 0)
		fill_with_symb(pf, &i, c, pf->str_len); //- i);
	if (tmp)
		free(tmp);
	return (pf->str_len);
}

static void		fill_with_symb_buff(t_pf *pf, int *i, char c, int len)
{
	len += *i;
	while (*i < len)
	{
		pf->buff[*i] = c;
		*i += 1;
	}
}

static void		fill_sign_buff(t_pf *pf, int *i, char sign)
{
	pf->buff[*i] = sign;
	*i += 1;
}

static void		fill_with_sharp_buff(t_pf *pf, int *i)
{
	int j;

	j = 0;
	while (pf->sharp[j] != '\0')
	{
		pf->buff[*i] = pf->sharp[j];
		j++;
		*i += 1;
	}
}

int		fill_buff(t_pf *pf)
{
	char c;
	char *tmp = NULL; ////отредачить str_join
	int i;
	int k;

	k = 0;
	i = 0;
	c = 't';

	int num_len = 0;

	i += pf->buf_len;
	num_len += pf->num_len;
	if (pf->symbol == 1)
		c = '0';
	if (pf->symbol == 2 || pf->symbol == 3)
		c = ' ';
	if (pf->symbol == 2 && pf->symb_width > 0)
		fill_with_symb_buff(pf, &i, c, pf->symb_width);
	if (ft_strchr("difu", pf->type) && (pf->plus || pf->minus))
		(pf->minus) ? (fill_sign_buff(pf, &i, '-')) : (fill_sign_buff(pf, &i, '+'));
	if (pf->space && !pf->minus && !pf->plus && pf->type != '%')
		fill_sign_buff(pf, &i, ' ');
	if (ft_strchr("poxX", pf->type) && pf->sharp)
		fill_with_sharp_buff(pf, &i);
	if (pf->symbol == 1 && pf->symb_width > 0)
		fill_with_symb_buff(pf, &i, c, pf->symb_width);
	tmp = find_tmp(pf);
	if (pf->prec_width > 0)
		fill_with_symb_buff(pf, &i, '0', pf->prec_width);

	if (pf->type == 's' && tmp)
	{
		while (k < num_len)
		{
			pf->buff[i] = tmp[k];
			k++;
			i++;
		}
	}
	else if (pf->type == 'c' || pf->type == '%')
		fill_with_symb_buff(pf, &i, pf->num.c, 1);
	else if (tmp && pf->type != 's' && pf->type != 'c')
	{
		while (k < num_len)
		{
			pf->buff[i] = tmp[k];
			k++;
			i++;
		}
	}
	if (pf->float_dot)
		fill_sign_buff(pf, &i, '.');
	if (pf->symbol == 3 && pf->symb_width > 0)
		fill_with_symb_buff(pf, &i, c, pf->str_len); //pf->str_len - i);
	if (tmp)
		free(tmp);
	pf->buf_len += pf->str_len;
	return (pf->buf_len);
}
*/
