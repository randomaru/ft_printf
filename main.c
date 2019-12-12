/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:08:31 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/12 20:08:06 by tamarant         ###   ########.fr       */
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
	static unsigned char 		uch_pos_1 = 100;
	static unsigned long long	ull_pos_1 = 22337203685477;
	static unsigned int			ui_pos_1 = 878023;
	static unsigned short		ush_pos_1 = 3047;
	static unsigned long		ul_pos_1 = 22337203685477;
	static unsigned long long 	ullmax = 9223372036854775807;
	static unsigned long  		ulmax = 9223372036854775807;

	double special;
	*((unsigned long *)(&special)) = DBL_INF;
	static char *s_hidden = "hi low\0don't print me lol\0";


/*    ft_printf("%%%"); /// -> %0
	printf("\n");
	printf("%%%"); /// -> %*/

/*	ft_printf("% u", 5);
	printf("\n");
	printf("% u", 5); /// ' ' undefined behaviour with u*/

////	ft_printf("%lld", -522337203685470ll);
////	printf("\n");
////	printf("%lld", -522337203685470ll);

/*    ft_printf("{%f}{%lf}{%Lf}", 1.42, 1.42, 1.42l);
	printf("\n");
	printf("{%f}{%lf}{%Lf}", 1.42, 1.42, 1.42l);*/
	int c = 10;
	int *p = &c;

	int a = ft_printf("%.0%");
	printf("\n");
	int b = printf("%.0%");
	printf("\nmoii=%i\norig=%i", a, b);


	return(0);
}