/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:08:31 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/07 21:41:52 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int 	main(void)
{
	static unsigned char 		uch_pos_1 = 100;
	static unsigned long long	ull_pos_1 = 22337203685477;
	static unsigned int			ui_pos_1 = 878023;
	static unsigned short		ush_pos_1 = 3047;
	static unsigned long		ul_pos_1 = 22337203685477;
	static unsigned long long 	ullmax = 9223372036854775807;
	static unsigned long  		ulmax = 9223372036854775807;


/*    ft_printf("%%%"); /// -> %0
	printf("\n");
	printf("%%%"); /// -> %*/

/*	ft_printf("% u", 5);
	printf("\n");
	printf("% u", 5); /// ' ' undefined behaviour with u*/

	ft_printf("%9.1s", NULL);
	printf("\n");
	printf("%9.1s", NULL);

/*	ft_printf("%hhu", 100);
	printf("\n");
	printf("%hhu", (unsigned char)100);
	printf("\n");


	ft_printf("%-3o", 15);
	printf("\n");
	printf("%-3o", 15);
	printf("\n");

	ft_printf("%llu %hhu %llo", ull_pos_1, uch_pos_1, ull_pos_1);
	printf("\n");
	printf("%llu %hhu %llo", ull_pos_1, uch_pos_1, ull_pos_1);
	printf("\n");

	ft_printf("%-3o", 0);
	printf("\n");
	printf("%-3o", 0);
	printf("\n");

	ft_printf("%hhu", 100);
	printf("\n");
	printf("%hhu", (unsigned char)100);
	printf("\n");

	ft_printf("%-3o", 0);
	printf("\n");
	printf("%-3o", 0);
	printf("\n");

	ft_printf("%.5o", 21);
	printf("\n");
	printf("%.5o", 21);*/


/*
	ft_printf("this %.6i number", -267);
	printf("\n");
	printf("this %.6i number", -267);*/

	return(0);
}