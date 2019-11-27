/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:40:11 by tamarant          #+#    #+#             */
/*   Updated: 2019/11/27 16:55:07 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	is_flags(char *p)
{
	if (*p == '#' || *p == '0' || *p == '+' || *p == '-')
		return (1);
	return (0);
}

int 	is_width(char *p)
{
	if (*p > '0' && *p < '9')
		return (1);
	return (0);
}

int		is_precision(char *p)
{
	if (*p == '.' && (*(p + 1) >= '0' && *(p + 1) <= '9'))
		return (1);
	return (0);
}

int 	is_size(char *p)
{
	if (ft_strchr("hl", *p))
		return (1);
	return (0);
}