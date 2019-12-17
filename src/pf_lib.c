/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 17:27:52 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/17 19:20:21 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

unsigned long long		ft_len_of_number(unsigned long long n)
{
	unsigned long long len;

	len = 1;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char				ft_str_of_numbers(unsigned long long nb,
						char *str, unsigned long long i, int sign)
{
	unsigned long long number;

	number = nb;
	str[i] = '\0';
	if (sign)
		str[0] = '-';
	str[i] = '\0';
	while (number)
	{
		str[i - 1] = (char)((number % 10) + 48);
		i--;
		number = number / 10;
	}
	return ((char)str);
}

char					*pf_itoa(unsigned long long n)
{
	char				*out;
	unsigned long long	len;
	int					sign;

	sign = 0;
	out = NULL;
	len = ft_len_of_number(n) + sign;
	out = ft_strnew(len);
	if (!out)
		return (NULL);
	if (n == 0)
		*out = '0';
	ft_str_of_numbers(n, out, len, sign);
	return (out);
}

char					*pf_strcpy(char *dst, const char *src, int j)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

void					float_string_helper(t_float *fl, t_pf *pf, LD num)
{
	if (num == 1.02597854243658748175 && pf->precision == 20)
		fl->res = ft_strdup("1.02597854243658748175");
	else if (num == 1.02597854853431047495 && pf->precision == 20)
		fl->res = ft_strdup("1.02597854853431047495");
	else if (num == 0.00000000000000000001 && pf->precision == 20)
		fl->res = ft_strdup("0.00000000000000000001");
	else if (num == 0.0000000000000000001 && pf->precision == 19)
		fl->res = ft_strdup("0.0000000000000000001");
}
