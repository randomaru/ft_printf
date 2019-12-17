/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:31:58 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/17 21:57:37 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#define DBL_INF    0x7FF0000000000000
#define DBL_NINF   0xFFF0000000000000
#define DBL_NAN    0x7FF0000000100000
#define DBL_PZERO  0x0000000000000000
#define DBL_NZERO  0x8000000000000000
int main()
{
	ft_printf("\n");
	ft_printf("%%\n");
	ft_printf("%d\n", 42);
	ft_printf("%d%d\n", 42, 41);
	ft_printf("%d%d%d\n", 42, 43, 44);
	ft_printf("%ld\n", 2147483647);
	ft_printf("%lld\n", 9223372036854775807);
	ft_printf("%x\n", 505);
	ft_printf("%X\n", 505);
	ft_printf("%p\n", &ft_printf);
	ft_printf("%20.15d\n", 54321);
	ft_printf("%-10d\n", 3);
	ft_printf("% d\n", 3);
	ft_printf("%+d\n", 3);
	ft_printf("%010d\n", 1);
	ft_printf("%hhd\n", 0);
	ft_printf("%jd\n", 9223372036854775807);
	ft_printf("%zd\n", 4294967295);
	ft_printf("%\n");
	ft_printf("%U\n", 4294967295);
	ft_printf("%u\n", 4294967295);
	ft_printf("%o\n", 40);
	ft_printf("%%#08x\n", 42);
	ft_printf("%x\n", 1000);
	ft_printf("%#X\n", 1000);
	ft_printf("%s\n", NULL);
	ft_printf("%S\n", L"ݗݜशব");
	ft_printf("%s%s\n", "test", "test");
	ft_printf("%s%s%s\n", "test", "test", "test");
	ft_printf("%C\n", 15000);
	return (0);
}