/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:21:28 by sharsune          #+#    #+#             */
/*   Updated: 2022/11/21 17:58:45 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	read_file(t_gnl *stash, int fd)
{
	char	*buffer;
	size_t	read_val;

	read_val = 1;
	while (!ft_strchr(stash->content,'\n') && read_val)
	{		
		buffer = malloc(sizeof(char)*(BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		buffer[BUFFER_SIZE] = '\0';
		read_val = read(fd, buffer, BUFFER_SIZE);
		stash->content = strjoin_free(stash->content, buffer, &stash->line_len, read_val);
	}
	//fprintf(stderr, "%zu\n", stash->line_len);
	fprintf(stderr, "%s\n", stash->content);
}

//static char	*return_line(char *stash)
//{

//}

char	*get_next_line(int fd)
{
	static  t_gnl stash;
	stash.line_len = 0;
	//char	*line;

	read_file(&stash, fd);
	//line = return_line(stash);
	return (0);



}
