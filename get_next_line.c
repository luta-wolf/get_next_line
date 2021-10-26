/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:09:35 by einterdi          #+#    #+#             */
/*   Updated: 2021/10/26 23:48:17 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_logic(char *line, char *buffer)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
		i++;
	ft_strlcpy(buffer, (line + i + 1), ft_strlen(line));
	line[i + 1] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];
	int			rd;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (NULL);
	rd = 1;
	line = NULL;
	if (buffer[0])
		line = ft_strjoin(line, buffer);
	else
		line = ft_strdup("");
	while (rd)
	{
		tmp = line;
		rd = read(fd, buffer, BUFFER_SIZE);
		buffer[rd] = '\0';
		line = ft_strjoin(line, buffer);
		free(tmp);
		buffer[0] = '\0';
		if (ft_strchr(line, '\n') != 0)
			return (ft_logic(line, buffer));
	}
	if (ft_strlen(line) != 0 && line != NULL && rd == 0)
		return (line);
	free(line);
	return (NULL);
}
