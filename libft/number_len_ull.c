/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_len_ull.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 20:59:17 by tamarant          #+#    #+#             */
/*   Updated: 2019/10/25 20:59:17 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		number_len_ull(unsigned long long n)
{
	int len;

	len = 1;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
