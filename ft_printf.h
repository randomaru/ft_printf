/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:08:54 by tamarant          #+#    #+#             */
/*   Updated: 2019/10/16 20:18:25 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <limits.h>

typedef struct		s_pf
{
	char			flag;
	int 			width;
	int 			presicion;
	char 			*type;
	char 			*result;
}					t_pf;

void    ft_putnbr_max(long long int nb);

int 	ft_printf(char *apFormat, ...);
void	format_flags(char *p, va_list ap, t_pf *pf);
void	type(char *p, va_list ap, t_pf *pf);

char			*ft_lltoa(long long int n);
char			*ft_llutoa(unsigned long long int n);
char			*itoa_base(int value, int base);

int				format(t_pf *pf);

#endif
