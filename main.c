#include <stdio.h>
#include <stdarg.h>
#include "libft.h"

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
				char *str = NULL;
				str = va_arg(ap,char*);
				ft_putstr(str);
			}
			else if (*p == 'i')
			{
				int num = 0;
				num = va_arg(ap, int);
				ft_putchar((char)(num + 48));
			}
		}
		else if (*p == '\n')
			ft_putchar('\n');
		p++;
	}

}

int 	main(void)
{
	test("%s\n %i\n %s\n, %i", "Hello", 5, "cat cat", 1);
	return(0);
}