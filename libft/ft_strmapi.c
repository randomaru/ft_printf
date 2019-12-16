/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:42:36 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/16 14:37:51 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*fs;

	i = 0;
	if (s && f)
	{
		if (!(fs = (char*)malloc(sizeof(*fs) * (ft_strlen((char*)s) + 1))))
			return (NULL);
		while (s[i] != '\0')
		{
			fs[i] = f(i, s[i]);
			i++;
		}
		fs[i] = '\0';
		return (fs);
	}
	else
		return (NULL);
}
