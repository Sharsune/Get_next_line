/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:22:41 by sharsune          #+#    #+#             */
/*   Updated: 2022/11/21 17:59:27 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

typedef struct t_gnl{
char	*content;
size_t	line_len;
} t_gnl;

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*gnl_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*strjoin_free(char const *s1, char const *s2, size_t *line_len, size_t buf_len);
size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize, size_t index);






#endif
