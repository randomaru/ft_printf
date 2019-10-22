/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:08:54 by tamarant          #+#    #+#             */
/*   Updated: 2019/10/22 19:34:34 by tamarant         ###   ########.fr       */
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
	char			flags[2];
	int 			width;
	int 			precision;
	char			size[2];
	char 			*type;
	int 			str_len;
	char 			*str;
	int 			slash_n;
	int 			counter;
}					t_pf;

void			ft_putnbr_max(long long int nb);
char			*ft_lltoa(long long int n);
char			*ft_llutoa(unsigned long long int n);
char			*itoa_base(int value, int base);
char			*ulltoa_base(unsigned long long int value, int base);
char 			*to_uppercase(char *str);

void			tmp_format_flags(char *p, va_list ap, t_pf *pf);
void			tmp_type(char *p, va_list ap, t_pf *pf);
int				tmp_format(t_pf *pf);

int					ft_printf(char *apFormat, ...);
int 				new_str(t_pf *pf, char *p);
int					pf_format(t_pf *pf, char *p);

int 				is_flags(char *p);
void				find_flags(t_pf *pf, char **p);
int 				is_width(char *p);
void				find_width(t_pf *pf, char **p);
int					is_precision(char *p);
void				find_precision(t_pf *pf, char **p);
int 				is_size(char *p);
void				find_size(t_pf *pf, char **p);
#endif
