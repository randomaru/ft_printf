/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:44:25 by tamarant          #+#    #+#             */
/*   Updated: 2019/09/25 14:45:18 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_clear_table(char **tables, int i)
{
	int index;

	index = 0;
	if (!tables)
		return (NULL);
	while (index < i)
	{
		ft_memdel((void**)&tables[index]);
		index++;
	}
	ft_memdel((void**)&tables);
	return (NULL);
}
