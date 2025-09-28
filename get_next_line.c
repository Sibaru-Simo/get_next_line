/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidna_7 <who??@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 06:18:21 by sidna_7           #+#    #+#             */
/*   Updated: 2025/09/28 08:02:14 by sidna_7          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int	ft_check(char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_read(int fd, char *buffer, char *leftover)
{
	char	*res;
	char	*tmp;
	ssize_t	bytes_read;

	if (leftover)
		res = ft_strdup(leftover);
	else
		res = ft_strdup("");
	bytes_read = 1;
	while (bytes_read > 0 && !ft_check(res, 10))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(res);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		tmp = res;
		res = ft_strjoin(res, buffer);
		free(tmp);
	}
	return (res);
}

char	*ft_line(char *full_buf)
{
	char	*line;
	size_t	index;
	size_t	len;

	index = 0;
	if (ft_check(full_buf, 10))
	{
		len = ft_line_len(full_buf, 10);
		line = ft_calloc(len + 1, sizeof(char));
		if (!line)
			return (NULL);
		while (index < len)
		{
			line[index] = full_buf[index];
			index++;
		}
		line[index] = '\0';
	}
	else
		line = ft_strdup(full_buf);
	return (line);
}

char	*ft_leftover(char *full_buf, char **leftover)
{
	char	*tmp;

	if (ft_check(full_buf, 10))
	{
		tmp = ft_strchr(full_buf, 10);
		if (*leftover)
			free(*leftover);
		if (tmp)
			*leftover = ft_strdup(tmp + 1);
		else
			*leftover = NULL;
	}
	else
	{
		if (*leftover)
			free(*leftover);
		*leftover = NULL;
	}
	return (*leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*full_buf;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	full_buf = ft_read(fd, buffer, leftover);
	if (!full_buf || !*full_buf)
	{
		if (leftover)
			free(leftover);
		leftover = NULL;
		return (NULL);
	}
	line = ft_line(full_buf);
	ft_leftover(full_buf, &leftover);
	free(full_buf);
	return (line);
}
