/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:08:31 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/16 21:11:49 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define DBL_INF    0x7FF0000000000000
#define DBL_NINF   0xFFF0000000000000
#define DBL_NAN    0x7FF0000000100000
#define DBL_PZERO  0x0000000000000000
#define DBL_NZERO  0x8000000000000000

#define LDBL_INF   0x7FFF0000000000000000L
#define LDBL_NINF  0xFFFF0000000000000000L
#define LDBL_NAN   0x7FFF0000000001000000L
#define LDBL_PZERO 0x00000000000000000000L
#define LDBL_NZERO 0x80000000000000000000L

# define FTBF_MBITS_F 23
# define FTBF_MBITS_D 52
# define FTBF_MBITS_LD 64

# define FTBF_BIAS_F 127
# define FTBF_BIAS_D 1023
# define FTBF_BIAS_LD 16382


int 	main(void)
{

	static char	a01;
	static unsigned char a02;
	static short a03;
	static unsigned short a04;
	static int a05;
	static unsigned int a06;
	static long a07;
	static unsigned long a08;
	static long long a09;
	static unsigned long long a10;
	static char *a11;
	static void *a12;
int special;

/*    ft_printf("%%%"); /// -> %0
	printf("\n");
	printf("%%%"); /// -> %*/

/*	ft_printf("% u", 5);
	printf("\n");
	printf("% u", 5); /// ' ' undefined behaviour with u*/

	ft_printf("hello, %s.", "gavin");
	printf("\n");
	printf("hello, %s.", "gavin");


	return(0);
}