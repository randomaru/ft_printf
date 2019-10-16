/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:05:29 by tamarant          #+#    #+#             */
/*   Updated: 2019/10/16 20:50:29 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	format(t_pf *pf)
{
	char	*new;
	char	*tmp;
	int 	len;
	int		i;

	i = 0;
	len = ft_strlen(pf->result);
	if (pf->width > 0)
	{
		if (pf->width > len)
		{
			len = pf->width - len;
			if (!(new = ft_memalloc(len + 1)))
				return (0);
			while(i < len)
				new[i++] = pf->flag;
			tmp = ft_strjoin(new, pf->result);
			pf->result = tmp;
		}
		return (1);
	}
	return (0);
}