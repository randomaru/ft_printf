/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:26:18 by tamarant          #+#    #+#             */
/*   Updated: 2019/11/27 16:55:07 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	new_str(t_pf *pf, char *p)
{
	int i;

	i = 0;
	while (*(p + i) != '\0')
	{
		pf->str_len += 1;
		if (*(p + i) == '%' && *(p + i + 1) != '%')
			break ;
		if (*(p + i) == '%' && *(p + i + 1) == '%')
			i++;
		i++;
	}
	if (!(pf->str = ft_memalloc(pf->str_len + 1)))
		return (0);
	i = 0;
	while (i < pf->str_len)
	{
		if (*p == '%')
		{
			pf->str[i] = '%';
			i++;
			p += 2;
			pf->percent += 1;
		} //// тогда неудобно двигать указатель(((
		else
		{
			pf->str[i] = *p;
			i++;
			p++;
		}
	}
	pf->str[i] = '\0';
	ft_putstr(pf->str);
	return (pf->str_len);
}