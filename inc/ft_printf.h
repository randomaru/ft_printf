/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:08:54 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/17 20:45:05 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ULL unsigned long long
# define LD long double
# define UI unsigned int
# define BU_SIZE 60

# define RED "\x1B[31m"
# define GRN "\x1b[32m"
# define YEL "\x1b[33m"
# define BLU "\x1b[34m"
# define PPL "\x1b[35m"
# define LBL "\x1b[36m"
# define GRA "\x1b[37m"
# define RST "\x1b[0m"

# define BOLD "\x1b[1m"
# define UNDER "\x1b[4m"
# define INVERT "\x1b[7m"

# define B_BLK "\x1b[40m"
# define B_RED "\x1b[41m"
# define B_GRN "\x1b[42m"
# define B_YEL "\x1b[43m"
# define B_BLU "\x1b[44m"
# define B_PPL "\x1b[45m"
# define B_LBL "\x1B[46m"
# define B_GRA "\x1B[47m"

# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"
# include <limits.h>
# include <math.h>

typedef struct			s_float
{
	unsigned long long	first;
	unsigned long long	second;
	char				*scnd;
	char				*frst;
	unsigned long long	i;
	unsigned long long	pos;
	char				*tmp;
	char				*res;
	int					not_f;
	int					flag;
}						t_float;

union					u_number
{
	int					i;
	long long int		lli;
	unsigned long long	ulli;
	long double			ld;
	char				c;
	char				*str;
}						;

typedef struct			s_pf
{
	char				*flags;
	int					width;
	int					precision;
	int					prec_width;
	char				*size;
	char				type;
	int					str_len;
	char				*str;
	int					percent;
	int					counter;
	int					symbol;
	int					symb_width;
	char				*sharp;
	char				*tmp_oxfs;
	int					num_len;
	union u_number		num;
	int					dot;
	int					plus;
	int					minus;
	int					space;
	int					float_dot;
	char				buff[BU_SIZE];
	int					buf_len;
}						t_pf;

int						ft_printf(const char *format, ...);
int						new_str(t_pf *pf, char **p);
int						pf_format(t_pf *pf, char **p, va_list ap);
int						is_flags(char *p);
void					find_flags(t_pf *pf, char **p);
int						is_width(char *p);
void					find_width(t_pf *pf, char **p);
int						is_precision(char **p, t_pf *pf);
void					find_precision(t_pf *pf, char **p);
int						is_size(char *p);
void					find_size(t_pf *pf, char **p);
int						parse_format(t_pf *pf);
int						find_str_size(t_pf *pf);
void					print_res(char *str, int len, int n);
void					fill_str_buff(t_pf *pf, char **p);
void					fill_str_str(t_pf *pf, char **p);
void					check_buf(t_pf *pf, char **p);
char					*find_tmp(t_pf *pf);
int						fill_final(t_pf *pf, char *str, int n, int len);
int						display_f(t_pf *pf);
char					*pf_itoa(unsigned long long n);
unsigned long long		ft_len_of_number(unsigned long long n);
char					*pf_strcpy(char *dst, const char *src, int j);
long double				ft_pow_double(long double n, unsigned long long pow);
int						handle_inf_nan(LD num, t_pf *pf, t_float *fl);
char					*add_null(t_pf *pf, t_float *fl, int what);
void					real_okrugl(t_float *fl, t_pf *pf, LD num);
char					*okrugl(LD num, ULL i, t_float *fl, int prec);
void					free_t_float(t_float *fl);
int						work_with_parts(t_float *fl, LD num, t_pf *pf);
void					put_if_precision_null(t_float *fl, t_pf *pf, LD num);
void					put_if_precision_not_null(t_float *fl,
													t_pf *pf, LD num);
char					*make_decimal(t_float *fl, t_pf *pf);
void					fill_char_from_int(ULL what, char *where);
char					*videl_memory_for_decimal(t_pf *pf, t_float *fl);
void					float_string_helper(t_float *fl, t_pf *pf, LD num);
char					*get_integer(LD num, t_float *fl);
char					*get_decimal(LD num, t_pf *pf, t_float *fl);
char					*put_in_str(t_pf *pf, t_float *fl, LD num);
t_float					*new_t_float(void);
void					free_t_pf(t_pf *pf, int n);
void					free_chars(t_pf *pf);
void					dop_free_end(t_pf *pf, int n);
char					*find_tmp(t_pf *pf);
void					fill_with_symb(char *str, int *i, char c, int len);
void					fill_with_sharp(t_pf *pf, char *str, int *i);

#endif
