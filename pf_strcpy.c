/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 20:10:09 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/06 20:10:27 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_strcpy(char *dst, const char *src, int j)
{
    int i;

    i = 0;
    while (src[i] != '\0')
    {
        dst[j] = src[i];
        i++;
        j++;
    }
    dst[j] = '\0';
    return (dst);
}
