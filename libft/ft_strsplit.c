/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 20:15:42 by tamarant          #+#    #+#             */
/*   Updated: 2019/11/27 16:55:08 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			if (s[i] == c)
				i++;
			else
			{
				word++;
				while (s[i] != c && s[i] != '\0')
					i++;
			}
		}
	}
	return (word);
}

static size_t		ft_words_len(char const *s, char c, size_t j)
{
	size_t	len;

	len = 0;
	while (s[j] != c && s[j] != '\0')
	{
		len++;
		j++;
	}
	return (len);
}

static void			free_res(char **res, int i)
{
	while (i-- > -1)
	{
		free(res[i]);
		res[i] = NULL;
	}
	free(res);
	res = NULL;
}

char				**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	word;
	char	**res;

	i = 0;
	j = 0;
	word = ft_count_words(s, c);
	if (!(res = (char**)malloc(sizeof(char*) * (word + 1))))
		return (NULL);
	while (i < word && s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		len = ft_words_len(s, c, j);
		if (!(res[i++] = ft_strsub(s, j, len)))
		{
			free_res(res, i);
			return (NULL);
		}
		j = j + len;
	}
	res[i] = NULL;
	return (res);
}
