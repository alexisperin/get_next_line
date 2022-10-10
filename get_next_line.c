/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:07:21 by aperin            #+#    #+#             */
/*   Updated: 2022/10/10 09:24:07 by aperin           ###   ########.fr       */
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
	printf("	buf malloc\n");
	line = read_line(fd, line, buf);
	return (line);
}

char	*read_line(int fd, char *line, char *buf)
{
	int		ret;
	char	*res;

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
	printf("	free buf (read_line)\n");
	free(buf);
	printf("	buf freed (read_line)\n");
	if (found_nl(line))
	{
		res = split_nl(&line);
		free(line);
		return (res);
	}
	if (line[0] == 0)
		return (gnl_free(line, 0));
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
	if (!before_nl)
		return (gnl_free(*str, 0));
	after_len = 0;
	while ((*str)[before_len + 1 + after_len])
		after_len++;
	after_nl = ft_strndup(*str + before_len + 1, after_len);
	if (!after_nl)
	{
		gnl_free(*str, before_nl);
		return (0);
	}
	printf("	free str (split_nl)\n");
	free(*str);
	*str = after_nl;
	return (before_nl);
}

char	*gnl_free(char *str1, char *str2)
{
	printf("	free str1 (gnl_free)\n");
	free(str1);
	printf("	free str2 (gnl_free)\n");
	free(str2);
	return (0);
}
