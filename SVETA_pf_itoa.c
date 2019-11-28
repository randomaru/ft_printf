//#include "libft.h"
#include "ft_printf.h"
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

static char		ft_str_of_numbers(unsigned long long nb, char *str, unsigned long long i, int sign)
{
    unsigned long long number;

    number = nb;
    str[i] = '\0';
    if (sign)
        str[0] = '-';
    str[i] = '\0'; // !!!!!!!!!!!!
    while (number)
    {
        str[i - 1] = (number % 10) + 48;
        i--;
        number = number / 10;
    }
    return ((char)str);
}

char			*pf_itoa(unsigned long long n)
{
    char	*out;
    unsigned long long		len;
    int		sign;

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