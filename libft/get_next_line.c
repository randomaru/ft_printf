/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:47:52 by tamarant          #+#    #+#             */
/*   Updated: 2019/11/27 16:55:08 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*next_symbols(const int fd, char **text, int len)
{
	char *text_sub;

	text_sub = NULL;
	if (text)
	{
		if (len == 0)
		{
			if (!(text_sub = ft_strsub(text[fd], 1,
					ft_strlen(text[fd]) - 1)))
				return (NULL);
		}
		else
		{
			if (!(text_sub = ft_strsub(text[fd], len + 1,
					ft_strlen(text[fd]) - len)))
				return (NULL);
		}
	}
	return (text_sub);
}

static int		new_line(const int fd, char **line, char **text, int read_b)
{
	int		len;
	char	*text_sub;

	len = 0;
	while (text[fd][len] != '\n' && text[fd][len] != '\0')
		len++;
	text_sub = next_symbols(fd, text, len);
	if (text[fd][len] == '\n')
	{
		if (!(*line = ft_strsub(text[fd], 0, len)))
			return (-1);
		ft_strdel(&text[fd]);
		if (!(text[fd] = ft_strdup(text_sub)))
			return (-1);
	}
	else if (text[fd][len] == '\0')
	{
		if (read_b == BUFF_SIZE)
			return (get_next_line(fd, line));
		if (!(*line = ft_strdup(text[fd])))
			return (-1);
		ft_strdel(&text[fd]);
	}
	free(text_sub);
	return (1);
}

static int		read_text(const int fd, char **line)
{
	static char	*text[MAX_FD];
	char		*text_tmp;
	char		buffer[BUFF_SIZE + 1];
	int			read_bytes;

	while ((read_bytes = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[read_bytes] = '\0';
		if (text[fd] == NULL)
		{
			if (!(text_tmp = ft_strdup(buffer)))
				return (-1);
		}
		else if (!(text_tmp = ft_strjoin_free(text[fd], buffer, 1)))
			return (-1);
		if (!(text[fd] = ft_strdup(text_tmp)))
			return (-1);
		free(text_tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (read_bytes == 0 && (text[fd] == NULL || text[fd][0] == '\0'))
		return (0);
	return (new_line(fd, line, text, read_bytes));
}

int				get_next_line(const int fd, char **line)
{
	if (fd < 0 || (!line) || BUFF_SIZE < 1 || read(fd, NULL, 0) == -1)
		return (-1);
	return (read_text(fd, line));
}
