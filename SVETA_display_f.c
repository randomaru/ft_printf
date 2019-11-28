#include "ft_printf.h"

char       *add_null(t_pf *pf, char *scnd)
{
	unsigned int i;

	i = 0;
	while (*(scnd + i) != '\0')
		i++;
	while (i < pf->precision)
	{
		*(scnd + i) = 48;
		i += 1;
	}
	*(scnd + i) = '\0';
	return (scnd);
}

unsigned long long	ft_pow(unsigned long long n, unsigned long long pow)
{
    return (pow ? n * ft_pow(n, pow - 1) : 1);
}

char    *get_integer(double num, unsigned long long *first)
{
    char    *frst;

    frst = NULL;
    *first = (unsigned long long)num;
    ///frst = ft_memalloc(ft_len_of_number(*first));
    frst = pf_itoa(*first);
    return (frst);
}

char     *okrugl(double num, unsigned long long first, unsigned long long i, char *scnd)
{
    if ((num) < 0.1 && num != 0)
    {
        *(scnd + i) = '0';
        i += 1;
        okrugl(num * 10, first, i, scnd);
    }
    return (scnd);
}

char    *get_decimal(double num, unsigned long long first, unsigned long long *second, t_pf *pf)
{
    char    *scnd = NULL;
    unsigned long long i;
    char *ch;
    double nado = 10 * (num - first);

//    while ((int)nado > 0)
//    {
//        if (((int)nado % 10 == 0))
//            break;
//        frm->len_decimal++;
//        nado *= 10;
//    }
    i = 0;
    if (!(scnd = ft_memalloc(pf->precision))) /// необходимо выделить память для случая с функцией okrugl
        return (NULL);
    ((pf->precision == 19) ? (*second = (num - first) * ft_pow(10, pf->precision))
						   : (*second = (num - first) * ft_pow(10, pf->precision + 1)));
 // комментарий под мэйном
    if ((num - first < 0.1) && pf->precision > 1) //&& frm->precision > 4) // не всегда срабатывает
        scnd = okrugl(num - first, first, i, scnd);
    if (pf->precision + 1 == 1)
        scnd = pf_itoa(*second);
    else
    {
        if (pf->precision == 19)
            *second = (*second % 10 > 4) ? (*second + 1) : (*second);
      /* else if (*second % 99 == 0) // некорректно
            *second = (*second / 10);*/
        else
            *second = (*second % 10 > 4) ? (*second/10 + 1) : (*second/10); // когда происходит некорректное разкругление(?!), то остаток от деления на 10 = 9.
          /* if (frm->precision == 1 && *second == 10)
                *second = 9;*/
           /*if (ft_len_of_number(scnd) > 0 && !*second)
               return (scnd);*/
        ch = pf_itoa(*second);
        scnd = ft_strjoin(scnd, ch);
        free(ch);
        return (scnd);
    }
    return (scnd);
    // Необходимо потестить, потому что есть инфа в интернете что надо +1 когда %10 > 4
    // Да, походу необходимо когда > 4, сейчас потестила на примере ("%.2f", 123.99); здесь получается дробная часть = 9899999.. и когда я подгоняю под точность то остается 98
    // почему именно 4?? Потому что идет округление
    // на примере ("%.1f", 123.99); некорректный вывод 123.10, возможно исправится когда я пропишу округление
}

char    *put_in_str(t_pf *pf, char *frst, char *scnd, int znak, unsigned long long first, unsigned int i)
{
    char    *res;

    if (!(res = ft_memalloc((ft_strlen(frst)) + (ft_strlen(scnd)) + 1
							+ (((pf->precision == 0) && (*pf->flags != '#')) ? 0 : 1) + ((znak == 1) ? 1 : 0))))
        return (NULL);
    if (pf->precision == 0) // прописать вывод когда без дробной части с округлением!
    {
        ((*scnd > 52) ? (first += 1) && (frst = pf_itoa(first)) : 0);
        ((znak == 1) ? *res = '-' : 0);
        while (*frst != '\0')
            *(res + i++) = *frst++;
        ((*pf->flags == '#') ? (*(res + i) = '.') && (i += 1) : 0);
    }
    else
    {
        if (pf->precision == 1 && (*(scnd + 1) == '0'))// && frm->len_decimal > 1)///
        {
            first += 1;
            frst = pf_itoa(first);
            *scnd = '0';
            scnd = ft_memalloc(pf->precision + 1);
            *scnd = '0';
        }
            //((*scnd == '10') ? (first += 1) && (frst = pf_itoa(first)) && (*scnd = '0') : 0);
        ((znak == 1) ? *res = '-' : 0);
        while (*frst != '\0')
            *(res + i++) = *frst++;
        *(res + i) = '.';
        i++;
        while (*scnd != '\0')
            *(res + i++) = *scnd++;
    }
    *(res + i) = '\0';
    return (res);
}

int    display_f(t_pf *pf)
{
    double num;
    unsigned long long first;
    unsigned long long second;
    char *res;
    unsigned int i;
    int znak;

    znak = 0;
    i = 0;
    first = 0;
    second = 0;
//    num = (double)va_arg(pf->arg, double);
	num = (double)pf->num.d;
    znak = (num < 0 ? 1 : 0);
    ((znak == 1) ? ((num = - num) && (i = 1)) : 0);
    ((pf->precision == -1) ? (pf->precision = 6) : 0);
    char *frst = get_integer(num, &first);
    char *scnd = get_decimal(num, first, &second, pf);
    (((int)ft_strlen(scnd) < pf->precision) ? (scnd = add_null(pf, scnd)) : 0); // случай когда дробная часть меньше чем точность. Пример ("%.4f", 12.2);
    res = put_in_str(pf, frst, scnd, znak, first, i);
    ft_putstr(res);
    pf->str = res;
//    free(res);
    free(frst);
    free(scnd);
    return (i - 1);
}