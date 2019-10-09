/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:28:41 by tamarant          #+#    #+#             */
/*   Updated: 2019/09/25 14:45:18 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;

	s1 = (char*)dst;
	s2 = (char*)src;
	if (dst < src)
	{
		while (len--)
			*s1++ = *s2++;
	}
	if (dst > src)
	{
		while (len--)
			s1[len] = s2[len];
	}
	return (dst);
}
