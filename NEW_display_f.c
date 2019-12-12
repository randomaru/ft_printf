/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_str_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:35:41 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/12 19:12:24 by fboggs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_t_float(t_float *fl)
{
    if (fl->first)
        fl->first = 0;
    if (fl->second)
        fl->second = 0;
    if (fl->i)
        fl->i = 0;
    if (fl->frst)
        free(fl->frst);
    if (fl->scnd)
        free(fl->scnd);
    if (fl->tmp)
        free(fl->tmp);
    if (fl->res)
        free(fl->res);
    fl->res = NULL;
    if (fl->not_f)
        fl->not_f = 0;
    free(fl);
}

t_float     *new_t_float(void)
{
    t_float *fl;

    if (!(fl = (t_float*)malloc(sizeof(t_float))))
        return (NULL);
    fl->first = 0;
    fl->second = 0;
    fl->scnd = NULL;
    fl->frst = NULL;
    fl->i = 0;
    fl->pos = 0;
    fl->tmp = NULL;
    fl->res = NULL;
    fl->not_f = 2;
    return (fl);
}

char       *add_null(t_pf *pf, t_float *fl, int what)
{
	UI i;

	i = 0;
	if (what == 1)
	    while (*(fl->scnd + i) != '\0')
		    i++;
	while (i < (UI)pf->precision)
	{
		*(fl->scnd + i) = 48;
		i += 1;
	}
	*(fl->scnd + i) = '\0';
	return (fl->scnd);
}

ULL	ft_pow(ULL n, ULL pow)
{
    return (pow ? n * ft_pow(n, pow - 1) : 1);
}

LD ft_pow_double(LD n, ULL pow)
{
    return (pow ? n * ft_pow_double(n, pow - 1) : 1);
}

char    *get_integer(LD num, t_float *fl)
{
    fl->first = (ULL)num;
    if (!(fl->frst = pf_itoa(fl->first)))
        return (NULL);
    return (fl->frst);
}

char     *okrugl(LD num, ULL i, t_float *fl, int prec)
{
    int precsn;

    precsn = prec;
    if ((num) < 0.1 && num != 0 && i < prec)
    {
        *((fl->scnd) + i) = '0';
        i += 1;
        okrugl(num * 10 + ft_pow_double(0.1, precsn), i,
                fl, prec--);
    }
    return (fl->scnd);
}

void    fill_char_from_int(ULL what, char *where)
{
    int i;

    i = ft_len_of_number(what);
    *(where + i) = '\0';
    i -= 1;
    while (what && i >= 0)
    {
        *(where + i) = ((what % 10) + 48);
        i--;
        what = what / 10;
    }
}

char *videl_memory_for_decimal(t_pf *pf, t_float *fl)
{
    if (pf->precision > 0)
    {
        if (!(fl->scnd = ft_memalloc(pf->precision + 1)))
            return (NULL);
    }
    else if (pf->precision == 0)
    {
        if (!(fl->scnd = ft_memalloc(pf->precision + 2))) // т,к, нам надо записать в строку число и конец строки. поэтому выделение 1 байта нам не подходит -Ю это только для символа конца строки
            return (NULL);
    }
    return (fl->scnd);
}

char *make_decimal(t_float *fl, t_pf *pf)
{
    if (pf->precision > 0)
    {
            if (pf->precision == 19)
                fl->second = (fl->second % 10 > 4) ? (fl->second + 1) :
                        (fl->second);
            else
                fl->second = (fl->second % 10 > 4) ? (fl->second / 10 + 1) :
                        (fl->second / 10);
            if (fl->second == 0)
                return (fl->scnd);
            if (!(fl->tmp = ft_memalloc(ft_len_of_number(fl->second) + 1)))
                return (NULL);
            fill_char_from_int(fl->second, fl->tmp);
            fl->scnd = pf_strcpy(fl->scnd, fl->tmp, ft_strlen(fl->scnd));
            return (fl->scnd);
    }
    return (fl->scnd);
}

char    *get_decimal(LD num, t_pf *pf, t_float *fl)
{
    if (!(fl->scnd = videl_memory_for_decimal(pf, fl)))
        return (NULL);
    ((pf->precision == 19) ? (fl->second = (ULL)((num - fl->first) *
            ft_pow(10, pf->precision)))
                           : (fl->second = (ULL)((num - fl->first) *
                                   ft_pow(10, pf->precision + 1))));
    if ((num - fl->first < 0.1) && pf->precision > 1)
        fl->scnd = okrugl((LD)(num - fl->first +
                ft_pow_double(0.1, pf->precision)),  fl->i, fl,
                        pf->precision - 1);
    if (pf->precision + 1 == 1) // 0
        fill_char_from_int(fl->second, fl->scnd);
    else
        {
            if (!(fl->scnd = make_decimal(fl, pf)))
                return (NULL);
        }
    return (fl->scnd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:09:48 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/07 21:13:20 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    real_okrugl(t_float *fl, t_pf *pf, LD num)
{
    if (pf->precision == 0)
    {
        if (*(fl->scnd) == 53)
            (((fl->first) % 2 == 0) ? 0 :
                ((fl->first += 1) &&
                    (fl->frst = pf_itoa(fl->first))));
        else
            ((*(fl->scnd) > 52) ? (fl->first += 1) &&
                (fl->frst = pf_itoa(fl->first)) : 0);
    }
    else if ((pf->precision == 1 && (*(fl->scnd + 1) == '0')) ||
                ((fl->second % 10) > 0 && (*(fl->scnd + 1) == '0') &&
                    fl->tmp == NULL) || ((*(fl->scnd + 1) == '0') &&
                        (num - fl->first > 0.901)))
    {
        fl->first += 1;
        fill_char_from_int(fl->first, fl->frst);
        fl->scnd = add_null(pf, fl, 0);
    }
}

void    put_if_precision_null(t_float *fl, t_pf *pf, LD num)
{
    real_okrugl(fl, pf, num);
    fl->pos = 0;
    while (*(fl->frst + fl->pos) != '\0')
    {
        *(fl->res + fl->pos) = *(fl->frst + fl->pos);
        fl->pos++;
    }
}

void    put_if_precision_not_null(t_float *fl, t_pf *pf, LD num)
{
    real_okrugl(fl, pf, num);
    fl->pos = 0;
    while (*(fl->frst + fl->pos) != '\0')
    {
        *(fl->res + fl->pos) = *(fl->frst + fl->pos);
        fl->pos++;
    }
    *(fl->res + fl->pos) = '.';
    fl->pos++;
    while (*(fl->scnd + fl->i) != '\0')
    {
        *(fl->res + fl->pos) = *(fl->scnd + fl->i);
        fl->pos++;
        fl->i++;
    }
}

char    *put_in_str(t_pf *pf, t_float *fl, LD num)
{
    if (!(fl->res = ft_memalloc((ft_strlen(fl->frst)) + ((pf->precision == 0) ?
            0 : (ft_strlen(fl->scnd) + 1)) + (((*pf->flags == '#') &&
                    pf->precision == 0) ? -1 : 0) + 1)))
        return (NULL);
    if (pf->precision == 0)
        put_if_precision_null(fl, pf, num);
    else
        put_if_precision_not_null(fl, pf, num);
    *(fl->res + fl->pos) = '\0';
    return (fl->res);
}

int   handle_inf_nan(LD num, t_pf *pf, t_float *fl)
{
    if ((1.0 / 0.0) == num)
    {
        if (!(fl->res = (pf->type == 'F' ? (ft_strdup("INF")) :
                (ft_strdup("inf")))))
            return (-1);
        return (1);
    }
    else if ((-1.0 / 0.0) == num)
    {
        if (!(fl->res = (pf->type == 'F' ? (ft_strdup("-INF")) :
                (ft_strdup("-inf")))))
            return (-1);
        return (1);
    }
    else if (num != num)
    {
        if (!(fl->res = (pf->type == 'F' ? (ft_strdup("NAN")) :
                (ft_strdup("nan")))))
            return (-1);
        return (1);
    }
    return (0);
}

int    work_with_parts(t_float *fl, LD num, t_pf *pf)
{
    if (fl->not_f == 0)
    {
        if (1/num == (-1.0 / 0.0)) // из свойст числа -0  - виикпедия
            pf->minus = 1;
        else
            pf->minus = ((num < 0) ? 1 : 0); ///  || (num == -0)
        ((pf->minus == 1) ? ((num = -num) && (fl->pos = 1)) : 0);
        ((pf->precision == -1) ? (pf->precision = 6) : 0);
        if (!(fl->frst = get_integer(num, fl)))
            return (-1);
        if (!(fl->scnd = get_decimal(num, pf, fl)))
            return (-1);
        if (fl->scnd != NULL && pf->precision > 0)
            (((UI)ft_strlen(fl->scnd) < pf->precision) ?
                (fl->scnd = add_null(pf, fl, 1)) : 0);
        if (!(fl->res = put_in_str(pf, fl, num)))
            return (-1);
    }
    return (0);
}

int    display_f(t_pf *pf)
{
    LD          num;
    t_float     *fl;

    num = pf->num.ld;
    if (!(fl = new_t_float()))
        return (0);
    fl->not_f = handle_inf_nan(num, pf, fl);
    if (fl->not_f == 0)
    {
        if (work_with_parts(fl, num, pf) == -1)
            return (-1);
    }
    else if (fl->not_f == -1)
        return (-1);
    pf->tmp_oxfs = ft_strdup(fl->res);
    free_t_float(fl);
    return (1);
}
// одно из особых состояний числа с плавающей запятой.
// Используется во многих математических библиотеках и математических сопроцессорах.
// Данное состояние может возникнуть в различных случаях, например,
// когда предыдущая математическая операция завершилась с неопределённым результатом или если в ячейку памяти
// попало не удовлетворяющее условиям число.

