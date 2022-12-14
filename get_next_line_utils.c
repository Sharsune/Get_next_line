/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:22:30 by sharsune          #+#    #+#             */
/*   Updated: 2022/12/14 16:51:12 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;

	index = 0;
	if (dstsize <= 0)
		return ;
	if (dstsize > 0)
	{
		while (src[index] != '\0')
		{
			if (index == dstsize)
				break ;
			dst[index] = src[index];
			index++;
		}
	}
	dst[index] = '\0';
}

char	*gnl_strdup(const char *s1)
{
	size_t			i;
	unsigned char	*new;

	i = 0;
	new = malloc(sizeof(char) * 2);
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
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*strjoin_free(char const *s1, char const *s2, \
size_t *line_len, int buf_len)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*newcontent;

	if (!s1)
		s1 = gnl_strdup("");
	if (!s1 || !s2)
		return (0);
	s1_len = *line_len;
	s2_len = buf_len;
	*line_len = (s1_len + s2_len);
	newcontent = malloc(sizeof(char) * (*line_len + 1));
	if (newcontent)
	{
		gnl_strlcpy(newcontent, s1, s1_len);
		gnl_strlcpy(&newcontent[s1_len], s2, s2_len);
		free((void *)s1);
		free((void *)s2);
		newcontent[*line_len] = '\0';
		return (newcontent);
	}
	return (NULL);
}
