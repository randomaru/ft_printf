/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:08:31 by tamarant          #+#    #+#             */
/*   Updated: 2019/10/17 18:08:48 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	main(void)
{
/*	printf("pf %010d\n", 123);
	ft_printf("ft %010d\n", 123);

	ft_putstr(itoa_base(9223372036854775807, 16));
	ft_putchar('\n');

	printf("%x\n", 233);
	printf("%lx\n", 2147483647);

	printf("%x\n", 2147483649);
	ft_printf("%x\n", 2147483649);
	printf("\n");

	printf("%lx\n", 4294967295);
	ft_printf("%lx\n", 4294967295);
	printf("\n");

	printf("%llx\n", 9223372036854775808);
	ft_printf("%llx\n", 9223372036854775808);
	printf("\n");

	printf("%llx\n", 18446744073709551615);
	ft_printf("%llx\n", 18446744073709551615);*/

	printf("%X\n", 2147483649);
	ft_printf("%X\n", 2147483649);
	printf("\n");

	printf("%lX\n", 4294967295);
	ft_printf("%lX\n", 4294967295);
	printf("\n");

	printf("%llX\n", 9223372036854775808);
	ft_printf("%llX\n", 9223372036854775808);
	printf("\n");

	printf("%llX\n", 18446744073709551615);
	ft_printf("%llX\n", 18446744073709551615);
	return(0);
}