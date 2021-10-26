/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:09:35 by einterdi          #+#    #+#             */
/*   Updated: 2021/10/26 22:11:15 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_logic(char *line, char *buffer)
{
	int i;

	i = 0;
	while (line[i] != '\n')
		i++;
//	printf("Line all: %s\n", line);
	ft_memcpy(buffer, (line + i + 1), ft_strlen(line) - i - 1);
//	printf("Buffer: %s\n", buffer);
	ft_bzero(line + i, ft_strlen(line + i + 1));
//	printf("Line short: %s\n", line);
	return (line);
}



char *get_next_line(int fd)
{
	char *line;
	static char buffer[BUFFER_SIZE + 1];
	int rd;
	char *tmp;

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
		ft_bzero(buffer, BUFFER_SIZE +1);
		if (ft_strchr(line, '\n') != 0)
			return (ft_logic(line, buffer));
	}
	if (line == NULL && rd == 0)
		return (line);
	free(line);
	return (NULL);
}
