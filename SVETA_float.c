
#include "ft_printf.h"

char       *add_null(t_format *frm, char *scnd)
{
	unsigned int i;

	i = 0;
	while (*(scnd + i) != '\0')
		i++;
	while (i < frm->precision)
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
    ///frst = ft_memalloc(ft_len_of_number(*first) + 1);///
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
/*12.0009 -> 12.900
12.89 .1 -> 0.89 %10 = 9 -> 0.89 /10 +1 = 0.9
		19.99 .1 -> 20.0 => 19.10*/
char    *get_decimal(double num, unsigned long long first, unsigned long long *second, t_pf *pf)
{
    char    *scnd;
    unsigned long long i;
    char *ch;

    i = 0;
    scnd = ft_memalloc(pf->precision);
    if ((num - (double)first < 0.1) && pf->precision > 2) //&& frm->precision > 4)
        scnd = okrugl(num - (double)first, first, i, scnd);
    ((pf->precision == 19) ? (*second = (num - (double)first) * (double)ft_pow(10, pf->precision))
						   : (*second = (num - (double)first) * (double)ft_pow(10, pf->precision + 1)));
 // комментарий под мэйном
    if (pf->precision + 1 == 1)
        scnd = pf_itoa(*second);
    else
    {
        if (pf->precision == 19)///
            *second = (*second % 10 > 4) ? (*second + 1) : (*second);
        else if (((*second % 99 == 9) || (*second % 99 == 0))) /// некорректно ///
            *second = (*second / 10);
        else
            *second = (*second % 10 > 4) ? (*second/10 + 1) : (*second/10); // когда происходит некорректное разкругление(?!), то остаток от деления на 10 = 9.
        ch = pf_itoa(*second);///
        return (ft_strjoin(scnd, ch)); //// обработать нулл и стр_джоин_фри
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
        if (pf->precision == 1)
            ((*scnd > 52) ? (first += 1) && (frst = pf_itoa(first)) && (*scnd = '0') : 0);
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

//12.96548 .5 -> 12.90000
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
    num = (double)pf->num.d;
    znak = (num < 0 ? 1 : 0);
    ((znak == 1) ? ((num = - num) && (i = 1)) : 0);
    ((pf->precision == -1) ? (pf->precision = 6) : 0);
    char *frst = get_integer(num, &first);
    char *scnd = get_decimal(num, first, &second, pf);
//    12.91 .6 ->12.910000
    ((ft_strlen(scnd) < pf->precision) ? (scnd = add_null(pf, scnd)) : 0); // случай когда дробная часть меньше чем точность. Пример ("%.4f", 12.2);8765
    res = put_in_str(pf, frst, scnd, znak, first, i);
    /*if (!(res = ft_memalloc((ft_strlen(frst)) + (ft_strlen(scnd)) + 1 + (((frm->precision == 0) && (*frm->flag != '#')) ? 0 : 1)+ ((znak == 1) ? 1 : 0))))
        return (-1);*/
    /*if (frm->precision == 0) // прописать вывод когда без дробной части с округлением!
    {
        if (*scnd > 52) // Для округления целой части
        {
            first += 1;
            frst = pf_itoa(first);
        }
        ((znak == 1) ? *res = '-' : 0);
        while (*frst != '\0')
            *(res + i++) = *frst++;
        ((*frm->flag == '#') ? (*(res + i) = '.') && (i += 1) : 0);
    }
    else
        {
            ((znak == 1) ? *res = '-' : 0);
        while (*frst != '\0')
            *(res + i++) = *frst++;
        *(res + i) = '.';
        i++;
        while (*scnd != '\0')
            *(res + i++) = *scnd++;
    }
    *(res + i) = '\0';*/
    pf->str = res;
    ft_putstr(res);
    return (i - 1);
}