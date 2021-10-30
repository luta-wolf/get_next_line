/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:09:35 by einterdi          #+#    #+#             */
/*   Updated: 2021/10/28 21:38:43 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_remainder(char **tail)
{
	char		*line;
	char		*pn;
	char		*tmp_tail;

	if (*tail != NULL)
	{
		if (ft_strchr(*tail, '\n'))
		{
			pn = ft_strchr(*tail, '\n');
			tmp_tail = ft_strdup(pn + 1);
			*(pn + 1) = '\0';
			line = ft_strdup(*tail);
			free(*tail);
			*tail = tmp_tail;
		}
		else
		{
			line = *tail;
			*tail = NULL;
		}
	}
	else
		line = ft_strdup("");
	return (line);
}

char	*ft_reading(int fd, char *line, char **tail, int rd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;
	char	*pn;

	while (rd > 0 && !ft_strchr(line, '\n') && !(*tail))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == 0 && *line == '\0')
		{
			free(line);
			return (NULL);
		}
		buffer[rd] = '\0';
		if (ft_strchr(buffer, '\n'))
		{
			pn = ft_strchr(buffer, '\n');
			*tail = ft_strdup(pn + 1);
			*(pn + 1) = '\0';
		}
		tmp = line;
		line = ft_strjoin(line, buffer);
		free(tmp);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*tail;
	char		*line;
	char		buf[1];
	int			rd;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, buf, 0) < 0)
		return (NULL);
	rd = 1;
	line = ft_remainder(&tail);
	line = ft_reading(fd, line, &tail, rd);
	return (line);
}
