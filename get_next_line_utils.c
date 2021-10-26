/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 21:43:32 by einterdi          #+#    #+#             */
/*   Updated: 2021/10/26 21:38:44 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	if (str == NULL)
		return (0);
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != (unsigned char)c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*mem;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	mem = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (mem == NULL)
		return (NULL);
	while (s1 && s1[i])
		mem[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		mem[j++] = s2[i++];
	mem[j] = '\0';
	return (mem);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*mem;
	char	*str;

	str = (char *)s1;
	len = ft_strlen((char *)s1);
	mem = (char *)malloc(sizeof(char) * (len + 1));
	if (!mem)
		return (NULL);
	i = 0;
	while (i < len)
	{
		mem[i] = str[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mem;
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	if (s == NULL)
		return (0);
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	mem = (char *) malloc(len + 1);
	if (mem == NULL)
		return (NULL);
	while (i < len && str[i + start] != '\0')
	{
		mem[i] = str[i + start];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}

void	*ft_memcpy(void *dict, const void *str, size_t n)
{
	size_t	i;
	char	*dict2;
	char	*str2;

	i = 0;
	dict2 = (char *)dict;
	str2 = (char *)str;
	if (str2 == NULL && dict2 == NULL)
		return (0);
	while (i < n)
	{
		dict2[i] = str2[i];
		i++;
	}
	return (dict);
}
