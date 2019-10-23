/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:55:11 by tamarant          #+#    #+#             */
/*   Updated: 2019/10/23 21:27:12 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_format(t_pf *pf)
{
	int i = 0;

	pf->str = "\0";
	while (pf->flags[i] != '\0')
	{
		if (pf->flags[i] == '#' && ft_strchr("oxX", pf->type))
		{
			if (pf->type == 'o')
				pf->str = ft_strjoin("0", pf->str);
			else if (pf->type == 'x')
				pf->str = ft_strjoin("0x", pf->str);
			else if (pf->type == 'x')
				pf->str = ft_strjoin("0X", pf->str);
		}
//		if (pf->flags[i] == '+' && !(ft_strchr("oxX", pf->type)))
//		{
//		}
		if (pf->flags[i] == '-')
		{

		}
	}
}