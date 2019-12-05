/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:55:11 by tamarant          #+#    #+#             */
/*   Updated: 2019/11/27 16:55:07 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*

#include "ft_printf.h"

void	to_str(t_pf *pf)
{
	if (pf->type == 'd' || pf->type == 'i')
		pf->str = ft_lltoa(pf->num.lli);
	if (ft_strchr("uoxX", pf->type))
		pf->str = ft_llutoa(pf->num.ulli);
	pf->str_len = ft_strlen(pf->str);
}

int		str_format(t_pf *pf)
{
	int i = 0;
	int width = 0;
	char *tmp = NULL;

	while (pf->flags[i] != '\0')
	{
		if (pf->flags[i] == '#' && ft_strchr("oxX", pf->type))
		{
			if (pf->type == 'o')
			{
				if (!(pf->str = ft_strjoin_free("0", pf->str, 2)))
					return (0);
			}
			else if (pf->type == 'x')
			{
				if (!(pf->str = ft_strjoin_free("0x", pf->str, 2)))
					return (0);
			}
			else if (pf->type == 'x')
			{
				if (!(pf->str = ft_strjoin_free("0X", pf->str,2)))
					return (0);
			}
		}
		if (pf->flags[i] == '+' && !(ft_strchr("uoxXscp", pf->type)))
		{
			if (pf->num.lli > 0 || pf->num.lli == 0 )
			{
				if (!(pf->str = ft_strjoin_free("+", pf->str, 2)))
					return (0);
			}
			else
			{
				if (!(pf->str = ft_strjoin_free("-", pf->str,2 )))
					return (0);
			}
			pf->str_len = ft_strlen(pf->str);
		}
		if (pf->flags[i] == '-' && pf->width > 0)
		{
			if ((width = pf->width - pf->str_len) <= 0)
				return (0);
			if (!(tmp = ft_memalloc(width + 1)))
				return (0); ////ERROR
			while (width--)
				*tmp = ' ';
			if (!(pf->str = ft_strjoin_free(pf->str, tmp,2)))
				return (0);
		}
		if (pf->flags[i] == '0' && pf->width > 0 && !(ft_strchr(pf->flags, '-')))
		{
			if ((width = pf->width - pf->str_len) <= 0)
				return (0);
			if (!(tmp = ft_memalloc(width + 1)))
				return (0); ////ERROR
			int k = 0;
			while (width--)
			{
				tmp[k] = '0';
				k++;
			}
			if (!(pf->str = ft_strjoin_free(tmp, pf->str, 3)))
			///если вернется NULL, то теряется указатель на pf->str
				return (0);
		}
		i++;
	}
	if (tmp)
		free(tmp);
	return (1);
}*/
