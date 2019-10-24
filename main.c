/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:08:31 by tamarant          #+#    #+#             */
/*   Updated: 2019/10/24 15:24:28 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	main(void)
{
//	printf("pf %010d\n", 123);
//	ft_printf("ft %010d\n", 123);

//	ft_putstr(itoa_base(9223372036854775807, 16));
//	ft_putchar('\n');
//
//	printf("%x\n", 233);
//	printf("%lx\n", 2147483647);
	//int i = printf("%-#10o", 16);
	//int j = ft_printf("ls %%\nldfl%% %% %% ");

	//printf("%+-010d", 14);


//	printf("%#-5x\n", 16);
//	printf("%-#x\n", 16);

//	printf("%010+d\n", 14);
//	printf("%010+-d\n", 14);
//	printf("%-+010d\n", 14);
//
//	printf("%#o\n", 16);

	printf("%+05d\n", 15);
	printf("%-05d\n", 15);

	return(0);
}