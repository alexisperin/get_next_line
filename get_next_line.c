/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:07:21 by aperin            #+#    #+#             */
/*   Updated: 2022/10/07 14:27:37 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*read_line(int fd, char *line, char *buf);
char	*split_nl(char **str);
char	*gnl_free(char *line, char *buf);

char	*get_next_line(int fd)
{
	static char	*line = 0;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (!line)
	{
		line = ft_strndup("", 0);
		if (!line)
			return (0);
	}
	buf = malloc(BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (gnl_free(line, 0));
	return (read_line(fd, line, buf));
}

char	*read_line(int fd, char *line, char *buf)
{
	int	ret;

	while (!found_nl(line))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (gnl_free(line, buf));
		if (ret == 0)
			break ;
		line = ft_strjoin_and_free(line, buf, ret);
		if (!line)
			return (0);
	}
	free(buf);
	if (found_nl(line))
		return (split_nl(&line));
	if (line[0] == 0)
	{
		printf("test\n");
		return (gnl_free(line, 0));
	}
	return (line);
}

char	*split_nl(char **str)
{
	char	*before_nl;
	char	*after_nl;
	int		before_len;
	int		after_len;

	before_len = 0;
	while ((*str)[before_len] != '\n')
		before_len++;
	before_nl = ft_strndup(*str, before_len + 1);
	if (before_nl)
	{
		after_len = 0;
		while ((*str)[before_len + 1 + after_len])
			after_len++;
		after_nl = ft_strndup(*str + before_len + 1, after_len);
		if (!after_nl)
		{
			free(before_nl);
			return (0);
		}
	}
	free(*str);
	*str = after_nl;
	return (before_nl);
}

char	*gnl_free(char *line, char *buf)
{
	free(line);
	free(buf);
	return (0);
}
