/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:22:30 by sharsune          #+#    #+#             */
/*   Updated: 2022/11/21 17:22:32 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize, size_t index)
{
	if (dstsize <= 0)
		return (0);
	if (dstsize > 0)
	{
		while (src[index] != '\0')
		{
			if (index == dstsize)
				break ;
			dst[index] = src[index];
			index++;
			//fprintf(stderr, "%s\n", dst);
		}
	}
	//printf("index is:%zu\n", index);
	dst[index] = '\0';
	return (index);
}

char	*gnl_strdup(const char *s1)
{
	size_t			i;
	unsigned char	*new;

	i = 0;
	new = malloc(sizeof (char) * 2);
	if (!new)
		return (0);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return ((char *)new);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0' && *s != (char)c)
	{
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*strjoin_free(char const *s1, char const *s2, size_t *line_len, size_t buf_len)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	index;
	char	*newcontent;

	index = 0;	
	if (!s1)
	{
		s1 = gnl_strdup("");
		*line_len = 1;
	}
	if (!s1 || !s2)
		return (0);
	s1_len = *line_len;
	s2_len = buf_len;
	*line_len = (s1_len + s2_len);
	//fprintf(stderr, "%zu\n", *line_len);
	newcontent = malloc(sizeof (char) * ( *line_len + 1));
	if (newcontent)
	{
		gnl_strlcpy(newcontent, s1, s1_len, index);
		//fprintf(stderr, "%s\n", newcontent);
		gnl_strlcpy(newcontent, s2, s2_len, index);
		//fprintf(stderr, "%s\n", newcontent);
		free ((void *)s1);
		free ((void *)s2);
		return (newcontent);
	}
	return (NULL);
}