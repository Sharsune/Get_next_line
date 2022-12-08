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

#include "get_next_line_bonus.h"

static void	read_file(t_gnl *stash, int fd)
{
	char	*buffer;
	int		read_val;

	read_val = 1;
	while (!ft_strchr (stash->content, '\n') && read_val)
	{		
		buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		read_val = read(fd, buffer, BUFFER_SIZE);
		if (read_val < 0)
		{
			free (buffer);
			return ;
		}
		buffer[read_val] = '\0';
		stash->content = strjoin_free(stash->content, buffer, \
		&stash->line_len, read_val);
	}
}

static char	*return_line(t_gnl *stash)
{
	size_t	i;
	char	*return_line;

	i = 0;
	while (stash->content[i] != '\n')
	{
		i++;
		if (stash->content[i] == '\0')
		{
			i--;
			break ;
		}
	}
	return_line = malloc(sizeof (char) * (i + 2));
	if (!return_line)
		return (NULL);
	gnl_strlcpy(return_line, stash->content, (i + 1));
	return (return_line);
}

static void	delete_stash_line(t_gnl *stash)
{
	char	*new_stash;
	size_t	i;

	i = 0;
	while (stash->content[i] != '\n' && stash->content[i] != '\0')
		i++;
	if (stash->content[i] == '\n')
		i++;
	stash->line_len = (stash->line_len - i);
	new_stash = malloc(sizeof(char) * (stash->line_len + 1));
	if (!new_stash)
	{
		free (stash->content);
		return ;
	}
	new_stash[stash->line_len] = 0;
	gnl_strlcpy(new_stash, &stash->content[i], stash->line_len);
	free (stash->content);
	stash->content = new_stash;
}

char	*get_next_line(int fd)
{
	static t_gnl	stash[FILE_MAX];
	char			*line;

	if (fd < 0 || fd > FILE_MAX)
		return (NULL);
	read_file(&stash[fd], fd);
	if (!stash[fd].content)
		return (NULL);
	if (!*stash[fd].content)
	{
		free(stash[fd].content);
		stash[fd].content = NULL;
		return (NULL);
	}
	line = return_line(&stash[fd]);
	delete_stash_line(&stash[fd]);
	return (line);
}
