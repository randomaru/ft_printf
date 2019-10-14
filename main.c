/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:08:31 by tamarant          #+#    #+#             */
/*   Updated: 2019/10/14 19:44:20 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
			while (*p != '\0' && *p != ' ')
			{
				++p;
				/*if (*p == '0' && *(p + 1) > '0' && *(p + 1) <= '9')
				{
					++p;
					str_format('0', ft_atoi(p));
				}*/
				if (*p == 's')
					string(va_arg(ap, char*));
				else if (*p == 'i' || *p == 'd')
					d_i(va_arg(ap, int));
				else if (*p == 'u')
					u(va_arg(ap, unsigned int));
				else if (*p == '\n')
					ft_putchar('\n');
			}
		}
	}

}

int 	main(void)
{
	//printf("%03d\n%f\n%04.2f\n", 9, 3.5, 1.2);
	//printf("%#f\n", 46.0);
	printf("%05s\n", "la");

	ft_printf("la la %% %d");
	return(0);
}