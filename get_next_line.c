/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 21:40:24 by einterdi          #+#    #+#             */
/*   Updated: 2021/10/20 19:14:22 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//External functs: read, malloc, fr
#include "get_next_line.h"
#define BUFFER_SIZE 42


char *get_next_line(int fd)
{

	ssize_t rd;
	char *str;

	if (read(fd, str, 0) < 0)
		return (NULL);

	printf("FD: %i\n", fd);
	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE +1));
	while (1)
	{
		rd = read(fd, str, BUFFER_SIZE);
		str[rd] = '\0';
		printf("%s", str);
		if (rd == 0)
			break;
	}
	return (str);
}
