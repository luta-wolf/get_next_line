/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 21:40:24 by einterdi          #+#    #+#             */
/*   Updated: 2021/10/24 22:44:35 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//External functs: read, malloc, free
#include "get_next_line.h"
#include <string.h>

void test(char *str)
{
	printf("test %p %p %s\n", &str, str, str);
	str = ft_strdup("111111");
	printf("test %p %p %s\n", &str, str, str);
}

static char *ft_logic(char **sttr)
{
	static int finish;
	char *s;
	int start = 0;
	char *str;

//	printf("log %p, %p\n", *sttr, sttr);

	str = *sttr;
	start = finish;
	while (str[finish] && str[finish] != '\n')
		finish++;
	s = ft_substr(str + start, 0, (finish - start + 1));
	finish++;
	if (str[finish] == '\0')
	{
		free(*sttr);
		*sttr = NULL;
	}
	return (s);
}

char *get_next_line(int fd)
{
	static char *str;
	static int tmp;
	char *buffer;
	int rd;
	char *new_line;
	char buf[1];
	rd = 1;

	tmp = 0;
	if (read(fd, buf, 0) < 0 || fd < 0)
		return (NULL);

	if(!str && !tmp)
	{
		tmp = 1;
		buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	 	if (buffer == NULL)
	 		return (NULL);
		while (rd)
		{
			if (!str)
				str = ft_strdup("");
//			if (!str)
//				return (NULL);
			new_line = str;
//			printf("%p\n", str);
			rd = read(fd, buffer, BUFFER_SIZE);

			buffer[rd] = '\0';
			str = ft_strjoin(str, buffer);
			free(new_line);
//			if (!str)
//				return (NULL);

		}
		free(buffer);

	}

	printf("main1 %p %p %s\n", &str, str, str);
	test(str);
	printf("main2 %p %p %s\n", &str, str, str);
//	printf("%s\n", str);
	if (str)
		new_line = ft_logic(&str);
	else
		new_line = NULL;
	// if (*str == '\0')
	// {
	// 	free(str);
	// 	return (NULL);
	// }
	return (new_line);
}
