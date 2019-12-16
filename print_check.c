/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 21:24:24 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/16 21:24:57 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_res(char *str, int len, int n)
{
	if ((n == 1 && *str) || n == 2)
		write(1, str, len);
}

void	check_buf(t_pf *pf, char **p)
{
	if (pf->type)
	{
		if (pf->str_len + pf->buf_len < BU_SIZE)
		{
			fill_final(pf, pf->buff, 1, pf->buf_len);
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
				fill_final(pf, pf->buff, 1, pf->buf_len);
			}
			else
			{
				fill_final(pf, pf->str, 2, pf->str_len);
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
		if (pf->str_len + pf->buf_len < BU_SIZE)
		{
			fill_str_buff(pf, &*p);
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

}
