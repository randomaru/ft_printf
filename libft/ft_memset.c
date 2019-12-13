/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:32:47 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/13 20:27:57 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*res;

	i = 0;
	res = (unsigned char *)b;
	if (len > 0)
	{
		while (i < len)
			res[i++] = (unsigned char)c;
	}
	return (b);
}
