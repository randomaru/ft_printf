

#include "ft_printf.h"

t_float	*new_t_float(void)
{
    t_float *floatty;

    if (!(floatty = (t_float*)malloc(sizeof(t_float))))
        return (NULL);
    floatty->first = 0;
    floatty->second = 0;
    floatty->scnd = NULL;
    floatty->frst= NULL;
    floatty->znak = 0;
    return (floatty);
}

char       *add_null(t_pf *pf, t_float *floatty, int what)
{
	unsigned int i;

	i = 0;
	if (what == 1)
	    while (*(floatty->scnd + i) != '\0')
		    i++;
	while (i < (unsigned int)pf->precision)
	{
		*(floatty->scnd + i) = 48;
		i += 1;
	}
	*(floatty->scnd + i) = '\0';
	return (floatty->scnd);
}

unsigned long long	ft_pow(unsigned long long n, unsigned long long pow)
{
    return (pow ? n * ft_pow(n, pow - 1) : 1);
}

char    *get_integer(long double num, t_float *floatty)
{
    floatty->first = (unsigned long long)num;
    floatty->frst = pf_itoa(floatty->first);
    return (floatty->frst);
}

char     *okrugl(long double num, unsigned long long i, t_float *floatty, int prec)
{
    if ((num) < 0.1 && num != 0 && i < prec)
    {
        *((floatty->scnd) + i) = '0';
        i += 1;
        okrugl(num * 10, i, floatty, prec--);
    }
    return (floatty->scnd);
}

void    fill_char_from_int(unsigned long long what, char *where)
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

char    *get_decimal(long double num, t_pf *pf, t_float *floatty)
{
    unsigned long long i;
    char *ch;

    i = 0;
    if (!(floatty->scnd = ft_memalloc(pf->precision + 1))) /// +\0
        return (NULL);
    ((pf->precision == 19) ? (floatty->second = (unsigned long long) ((num - floatty->first) *
                                                                      ft_pow(10, pf->precision)))
                           : (floatty->second = (unsigned long long) ((num - floatty->first) *
                                                                      ft_pow(10, pf->precision + 1))));
    // комментарий под мэйном
    if ((num - floatty->first < 0.1) && pf->precision > 1) {//&& frm->precision > 4) // не всегда срабатывает
        floatty->scnd = okrugl((double) (num - floatty->first), i, floatty, pf->precision);
    }
    if (pf->precision + 1 == 1) // 0
        fill_char_from_int(floatty->second, floatty->scnd);
    else {
        if (pf->precision == 19)
            floatty->second = (floatty->second % 10 > 4) ? (floatty->second + 1) : (floatty->second);
        else
            floatty->second = (floatty->second % 10 > 4) ? (floatty->second / 10 + 1) : (floatty->second / 10);
       if (floatty->second == 0)
            return (floatty->scnd);
        ch = ft_memalloc(ft_len_of_number(floatty->second + 1)); // для \0
        fill_char_from_int(floatty->second, ch);
        if (ft_strlen(floatty->scnd) + 1 == pf->precision && ft_len_of_number(floatty->second) > 1)
            floatty->scnd = pf_strcpy(floatty->scnd, ch, (int)(ft_strlen(floatty->scnd) - ft_len_of_number(floatty->second) + 1)); /////мы добавили тут приведение к инту
        else if (ft_strlen(floatty->scnd) == pf->precision)
            *(floatty->scnd + ft_strlen(floatty->scnd) - 1) = *ft_strcpy((floatty->scnd + ft_strlen(floatty->scnd) - 1), ch);
        else
           floatty->scnd = pf_strcpy(floatty->scnd, ch, ft_strlen(floatty->scnd));
        free(ch);
        return (floatty->scnd);
    }
    return (floatty->scnd);
}

char    *put_in_str(t_pf *pf, unsigned int i, t_float *floatty, long double num)
{
    char    *res;

    if (!(res = ft_memalloc((ft_strlen(floatty->frst)) + ((floatty->scnd == NULL) ? 0 : (ft_strlen(floatty->scnd) + 1))
							+ (((*pf->flags == '#') && pf->precision == 0) ? -1 : 0) /*+ ((floatty->znak == 1) ? 1 : 0)*/ + 1))) /// мб неверно выделяеся память
        return (NULL);
    if (pf->precision == 0) // прописать вывод когда без дробной части с округлением!
    {
        if (*(floatty->scnd) == 53)
            (((floatty->first) % 2 == 0) ? 0 : ((floatty->first += 1) && (floatty->frst = pf_itoa(floatty->first))));
        else
            ((*(floatty->scnd) > 52) ? (floatty->first += 1) && (floatty->frst = pf_itoa(floatty->first)) : 0);
////        ((floatty->znak == 1) ? *res = '-' : 0);
		i = 0;
        while (*(floatty->frst) != '\0') {
            *(res + i++) = *(floatty->frst++);///
        }
       // ((*pf->flags == '#') ? (*(res + i) = '.') && (i += 1) : 0);
    }
    else
    {
        if ((pf->precision == 1 && (*(floatty->scnd + 1) == '0')) || ((num - floatty->first) > 0.9 && (*(floatty->scnd + 1) == '0')))// && frm->len_decimal > 1)///
        {
            floatty->first += 1;
            fill_char_from_int(floatty->first, floatty->frst);
            floatty->scnd = add_null(pf, floatty, 0);
        }
//        ((floatty->znak == 1) ? *res = '-' : 0);
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

int    display_f(t_pf *pf)
{
    long double num;
    char *res;
    unsigned int i;
    t_float *floatty;

    i = 0;
   /* if (*(pf->size) == 'L')
        num = (long double)pf->num.ld;
    else*/

	    num = pf->num.ld;

    /*if ((1.0 / 0.0) == num || (-1.0 / 0.0) == num)
    {
       res = (pf->type == 'F' ? "INF" : "inf");
    }
    else if (num != num)
        res = (pf->type == 'F' ? "NAN" : "nan");
    else {*/
        if (!(floatty = new_t_float()))
            return (0);
//        floatty->znak = (num < 0 ? 1 : 0);
//        ((floatty->znak == 1) ? ((num = -num) && (i = 1)) : 0);
		pf->minus = (num < 0 ? 1 : 0);
		((pf->minus == 1) ? ((num = -num) && (i = 1)) : 0);
        ((pf->precision == -1) ? (pf->precision = 6) : 0);
        floatty->frst = get_integer(num, floatty);
        floatty->scnd = get_decimal(num, pf, floatty);
        if (floatty->scnd != NULL)
            (((int) ft_strlen(floatty->scnd) < pf->precision) ? (floatty->scnd = add_null(pf, floatty, 1)) : 0); // случай когда дробная часть меньше чем точность. Пример ("%.4f", 12.2);
        res = put_in_str(pf, i, floatty, num);
//        ft_putstr(res);
        pf->tmp_oxfs = res;
    return (i - 1);
}