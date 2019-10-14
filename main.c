#include "ft_printf.h"

void 	test(char *apFormat, ...)
{
	va_list ap;
	char	*p;

	va_start(ap, apFormat);
	p = apFormat;
	while (*p != '\0')
	{
		if (*p == '%')
		{
			++p;
			if (*p == 's')
			{
				/*char *str = NULL;
				str = va_arg(ap,char*);
				ft_putstr(str);*/
				string(va_arg(ap, char*));
			}
			else if (*p == 'i' || *p == 'd')
			{
				/*int num = 0;
				num = va_arg(ap, int);
				ft_putchar((char)(num + 48));*/
				d_i(va_arg(ap, int));
			}
			else if (*p == 'u')
				u(va_arg(ap, unsigned int));
		}
		else if (*p == '\n')
			ft_putchar('\n');
		p++;
	}

}

int 	main(void)
{
	int n;
	//test("%s\n %i\n %s\n, %i\n", "Hello", 5, "cat cat", 1);
/*	printf("%d\n", -2147483649);
	test("%d\n", -2147483649);
	printf("%d\n", -+1);
	test("%d\n", -+1);*/

	printf("%u\n", 429496729700);
	test("%u\n", 429496729700);

	return(0);
}