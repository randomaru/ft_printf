
#include "ft_printf.h"

void    ft_putnbr_max(long long int nb)
{
	if (nb == LONG_MIN)
		ft_putstr("-9223372036854775808");
	if (nb < 0 && nb != LONG_MIN)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10 && nb != LONG_MIN)
	{
		ft_putnbr_max(nb / 10);
		ft_putnbr_max(nb % 10);
	}
	else if (nb != LONG_MIN)
	{
		ft_putchar(nb + '0');
	}
}
