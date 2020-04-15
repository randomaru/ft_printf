/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 15:43:26 by mac               #+#    #+#             */
/*   Updated: 2020/04/15 16:43:46 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int 	main(int argc, char **argv)
{
	int orig = 0;
	int my = 0;
	char *str = "The fish listened intently to what the frogs had to say.";

	ft_printf(LBL"Hello! It's my ft_printf!\nLet's test some basic features:\n"RST);
	ft_printf( YEL"String = \"%s\"\nwith field precision == 17 and newline in the end.\n"RST, str);
	ft_printf(RED"---Original printf---\n"RST);
	ft_printf("The number of printed characters: %i\n", orig = printf("%.17s\n", str));
	ft_printf(PPL"---ft_printf---\n"RST);
	ft_printf("The number of printed characters: %i\n", my = ft_printf("%.17s\n", str));
	if (orig == my)
		ft_printf(BLU"Congrats! ft_printf repeats the behavior of the original function! \n"RST);
	ft_printf("Let's try ft_printf with some ints\nlong int = %li\nminimum field width = 30, flag = 0\n", LONG_MAX);
	ft_printf(RED"---Original printf---\n"RST);
	ft_printf("The number of printed characters: %i\n", orig = printf("%030li\n", LONG_MAX));
	ft_printf(PPL"---ft_printf---\n"RST);
	ft_printf("The number of printed characters: %i\n", my = ft_printf("%030li\n", LONG_MAX));
	if (orig == my)
		ft_printf(BLU"Congrats! ft_printf repeats the behavior of the original function! \n"RST);
	return (0);
}
