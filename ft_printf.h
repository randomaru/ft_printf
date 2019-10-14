/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:08:54 by tamarant          #+#    #+#             */
/*   Updated: 2019/10/14 19:50:25 by tamarant         ###   ########.fr       */
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
}					t_pf;

void    ft_putnbr_max(long long int nb);

void 	string(char *str);
int		d_i(int nbr);
void	u(unsigned int nbr);

int 	ft_printf(char *apFormat, ...);
void	format_flags(char *p, va_list ap, t_pf *pf);
void	type(char *p, va_list *ap, t_pf *pf);


#endif
