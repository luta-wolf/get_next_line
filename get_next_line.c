/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 21:40:24 by einterdi          #+#    #+#             */
/*   Updated: 2021/10/22 17:29:36 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//External functs: read, malloc, fr
#include "get_next_line.h"
#define BUFFER_SIZE 42

char *get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1];
	char tmp[BUFFER_SIZE + 1];
	ssize_t rd;
	char *str;

	rd = 1;
	if (read(fd, str, 0) < 0)
		return (NULL);


	while (rd)
	{
		rd = read(fd, tmp, BUFFER_SIZE);
		tmp[rd] = '\0';

		if (ft_strchr(tmp ,'\n'))
			break;
	}
	printf("%s\n ____ rd=%zu", tmp, rd);
	return (str);
}
