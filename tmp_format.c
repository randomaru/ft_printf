/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:05:29 by tamarant          #+#    #+#            /*   Updated: 2019/11/27 16:55:07 by mac              ###   ########.fr       */
 */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	tmp_format(t_pf *pf)
{
	char	*new;
	char	*tmp;
	int 	len;
	int		i;

	i = 0;
	len = ft_strlen(pf->str);
	if (pf->width > 0)
	{
		if (pf->width > len)
		{
			len = pf->width - len;
			if (!(new = ft_memalloc(len + 1)))
				return (0);
			while(i < len)
				new[i++] = pf->flags;
			tmp = ft_strjoin(new, pf->str);
			pf->str = tmp;
		}
		return (1);
	}
	return (0);
}