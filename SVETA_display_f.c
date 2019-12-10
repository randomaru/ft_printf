#include "ft_printf.h"

void	free_t_float(t_float *floatty)
{
    floatty->first = 0;
    floatty->second = 0;
    if (floatty->frst)
        free(floatty->frst);
    if (floatty->scnd)
        free(floatty->scnd);
    free(floatty);
}

t_float     *new_t_float(void)
{
    t_float *floatty;

    if (!(floatty = (t_float*)malloc(sizeof(t_float))))
        return (NULL);
    floatty->first = 0;
    floatty->second = 0;
    floatty->scnd = NULL;
    floatty->frst = NULL;
    return (floatty);
}

char       *add_null(t_pf *pf, t_float *floatty, int what)
{
	UI i;

	i = 0;
	if (what == 1)
	    while (*(floatty->scnd + i) != '\0')
		    i++;
	while (i < (UI)pf->precision)
	{
		*(floatty->scnd + i) = 48;
		i += 1;
	}
	*(floatty->scnd + i) = '\0';
	return (floatty->scnd);
}

ULL	ft_pow(ULL n, ULL pow)
{
    return (pow ? n * ft_pow(n, pow - 1) : 1);
}

LD ft_pow_double(LD n, ULL pow)
{
    return (pow ? n * ft_pow_double(n, pow - 1) : 1);
}

char    *get_integer(LD num, t_float *floatty)
{
    floatty->first = (ULL)num;
    floatty->frst = pf_itoa(floatty->first);
    return (floatty->frst);
}

char     *okrugl(LD num, ULL i, t_float *floatty, int prec)
{
    int precsn;

    precsn = prec;
    if ((num) < 0.1 && num != 0 && i < prec)
    {
        *((floatty->scnd) + i) = '0';
        i += 1;
        okrugl(num * 10 + ft_pow_double(0.1, precsn), i, floatty, prec--);
    }
    return (floatty->scnd);
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

char    *get_decimal(LD num, t_pf *pf, t_float *floatty)
{
    ULL i;
    char *ch;

    i = 0;
    if (!(floatty->scnd = ft_memalloc(pf->precision + 1))) /// +\0
        return (NULL);
    ((pf->precision == 19) ? (floatty->second = (ULL)((num - floatty->first) *
            ft_pow(10, pf->precision)))
                           : (floatty->second = (ULL)((num - floatty->first) *
                                   ft_pow(10, pf->precision + 1))));
    if ((num - floatty->first < 0.1) && pf->precision > 1)
        floatty->scnd = okrugl((LD)(num - floatty->first +
                ft_pow_double(0.1, pf->precision)), i, floatty, pf->precision - 1);
    if (pf->precision + 1 == 1) // 0
        fill_char_from_int(floatty->second, floatty->scnd);
    else
        {
            if (pf->precision == 19)
                floatty->second = (floatty->second % 10 > 4) ? (floatty->second + 1) : (floatty->second);
            else
                floatty->second = (floatty->second % 10 > 4) ? (floatty->second / 10 + 1) : (floatty->second / 10);
            if (floatty->second == 0)
                return (floatty->scnd);
            ch = ft_memalloc(ft_len_of_number(floatty->second) + 1); // для \0
                fill_char_from_int(floatty->second, ch);
           /* if (ft_strlen(floatty->scnd) + 1 == pf->precision && ft_len_of_number(floatty->second) > 1)
                floatty->scnd = pf_strcpy(floatty->scnd, ch, (UI)(ft_strlen(floatty->scnd) - ft_len_of_number(floatty->second) + 1)); /////мы добавили тут приведение к инту
            else if (ft_strlen(floatty->scnd) == pf->precision)
                *(floatty->scnd + ft_strlen(floatty->scnd) - 1) = *ft_strcpy((floatty->scnd + ft_strlen(floatty->scnd) - 1), ch);*/
            //else
                floatty->scnd = pf_strcpy(floatty->scnd, ch, ft_strlen(floatty->scnd));
            free(ch);
            return (floatty->scnd);
        }
    return (floatty->scnd);
}

char    *put_in_str(t_pf *pf, UI i, t_float *floatty, LD num)
{
    char    *res;

    if (!(res = ft_memalloc((ft_strlen(floatty->frst)) + ((floatty->scnd == NULL) ? 0 : (ft_strlen(floatty->scnd) + 1))
							+ (((*pf->flags == '#') && pf->precision == 0) ? -1 : 0) + 1))) /// мб неверно выделяеся память
        return (NULL);
    if (pf->precision == 0)
    {
        if (*(floatty->scnd) == 53)
            (((floatty->first) % 2 == 0) ? 0 : ((floatty->first += 1) && (floatty->frst = pf_itoa(floatty->first))));
        else
            ((*(floatty->scnd) > 52) ? (floatty->first += 1) && (floatty->frst = pf_itoa(floatty->first)) : 0);
		i = 0;
        while (*(floatty->frst) != '\0')
            *(res + i++) = *(floatty->frst++);
    }
    else
    {
        if ((pf->precision == 1 && (*(floatty->scnd + 1) == '0')) || ((num - floatty->first) > 0.9 && (*(floatty->scnd + 1) == '0')))// && frm->len_decimal > 1)///
        {
            floatty->first += 1;
            fill_char_from_int(floatty->first, floatty->frst);
            floatty->scnd = add_null(pf, floatty, 0);
        }
		int j = 0;
        i = 0;
        while (*(floatty->frst) != '\0')
            *(res + i++) = *(floatty->frst++);
        *(res + i) = '.';
        i++;
        while (floatty->scnd[j] != '\0')
            *(res + i++) = *(floatty->scnd++);
    }
    *(res + i) = '\0';
    return (res);
}

/*int   handle_inf_nan(LD num, t_pf *pf, int what, char **res)
{
    if (what == 1 || what == 3 || what == 2)
    {
        if (!(*res = malloc(sizeof(char) * 4)))
            return (0);
        if (what == 1)
            *res = (pf->type == 'F' ? "INF\0" : "inf\0");
        else if (what == 3)
            *res = (pf->type == 'F' ? "NAN\0" : "nan\0");
        else
        {
            if (!(*res = malloc(sizeof(char) * 5)))
                return (0);
            *res = (pf->type == 'F' ? "-INF\0" : "-inf\0");
        }
    }
    return (1);
}*/

int   handle_inf_nan(LD num, t_pf *pf, int what, char **res)
{
	if (what == 1 || what == 3 || what == 2)
	{
		if (!(*res = malloc(sizeof(char) * 4)))
			return (0);
		if (what == 1)
			*res = (pf->type == 'F' ? "INF\0" : "inf\0");
		else if (what == 3)
			*res = (pf->type == 'F' ? "NAN\0" : "nan\0");
		else
		{
			if (!(*res = malloc(sizeof(char) * 5)))
				return (0);
			*res = (pf->type == 'F' ? "-INF\0" : "-inf\0");
		}
	}
	return (1);
}

int    display_f(t_pf *pf)
{
    LD num;
    char *res;
    UI i;
    t_float *floatty = NULL;

    i = 0;
    num = pf->num.ld;
    if ((1.0 / 0.0) == num)
        handle_inf_nan(num, pf, 1, &res);
    else if ((-1.0 / 0.0) == num)
        handle_inf_nan(num, pf, 2, &res);
    else if (num != num)
        handle_inf_nan(num, pf, 3, &res);
    else
        {
        if (!(floatty = new_t_float()))
            return (0);
        if (1/num == (-1.0 / 0.0)) // из свойст числа -0  - виикпедия
            pf->minus = 1;
        else
            pf->minus = ((num < 0) ? 1 : 0); ///  || (num == -0)
        ((pf->minus == 1) ? ((num = -num) && (i = 1)) : 0);
        ((pf->precision == -1) ? (pf->precision = 6) : 0);
        floatty->frst = get_integer(num, floatty);
        floatty->scnd = get_decimal(num, pf, floatty);
        if (floatty->scnd != NULL)
            (((UI)ft_strlen(floatty->scnd) < pf->precision) ? (floatty->scnd = add_null(pf, floatty, 1))
                                                              : 0); // случай когда дробная часть меньше чем точность. Пример ("%.4f", 12.2);
        res = put_in_str(pf, i, floatty, num);
    }
    pf->tmp_oxfs = res;
    return (1);
}

// одно из особых состояний числа с плавающей запятой.
// Используется во многих математических библиотеках и математических сопроцессорах.
// Данное состояние может возникнуть в различных случаях, например,
// когда предыдущая математическая операция завершилась с неопределённым результатом или если в ячейку памяти
// попало не удовлетворяющее условиям число.

