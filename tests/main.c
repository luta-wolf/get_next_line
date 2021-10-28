/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:57:32 by einterdi          #+#    #+#             */
/*   Updated: 2021/10/28 21:35:13 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

#define col0 "\e[1;38;2;200;;m"
#define col1 "\e[1;38;2;;200;m"
#define col2 "\e[1;38;2;;;200m"
#define col3 "\e[1;38;2;200;;200m"
#define un "\e[m"

int main()
{
	char *line;
	int fd1;
	int fd2;
	int fd3;
	int fd4;

	char *str[10];
	str[0] = "test.txt";
	 str[1] = "test0.txt";
	 str[2] = "test2.txt";
	str[3] = "test3.txt";

	fd1 = open(str[0], O_RDONLY);
	 fd2 = open(str[1], O_RDONLY);
	fd3 = open(str[2], O_RDONLY);
	fd4 = open(str[3], O_RDONLY);
	for (size_t i = 0; i < 10; i++)
	{
		line = get_next_line(fd1);
		printf("fd: %d %s : |%s%s%s|", fd1, str[0], col0, line, un);
		free(line);

		line = get_next_line(fd2);
		printf("fd: %d %s : |%s%s%s|", fd2, str[1], col1, line, un);
		free(line);

		line = get_next_line(fd3);
		printf("fd: %d %s : |%s%s%s|", fd3, str[2], col2, line, un);
		free(line);

		line = get_next_line(fd4);
		printf("fd: %d %s : |%s%s%s|", fd4, str[3], col3, line, un);
		free(line);
	}


	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	return (0);
}
