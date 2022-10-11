/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:07:21 by aperin            #+#    #+#             */
/*   Updated: 2022/10/11 10:28:02 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "get_next_line.h"

char	*read_line(int fd, char **line, char **buf);
char	*split_nl(char **str);

char	*get_next_line(int fd)
{
	static char	*rest = 0;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX)
		return (0);
	if (!rest)
		rest = ft_strndup("", 0);
	buf = malloc(BUFFER_SIZE * sizeof(char));
	if (!rest || !buf)
		return (gnl_free(&rest, &buf));
	line = read_line(fd, &rest, &buf);
	if (line && !found_nl(line))
	{
		line = ft_strndup(line, 0);
		free(rest);
		rest = 0;
	}
	return (line);
}

char	*read_line(int fd, char **rest, char **buf)
{
	int		ret;

	while (!found_nl(*rest))
	{
		ret = read(fd, *buf, BUFFER_SIZE);
		if (ret == -1)
			return (gnl_free(rest, buf));
		if (ret == 0)
			break ;
		*rest = ft_strjoin_and_free(rest, *buf, ret);
		if (!(*rest))
			return (gnl_free(rest, buf));
	}
	free(*buf);
	if (ret == 0 && (*rest)[0] == 0)
		return (gnl_free(rest, 0));
	return (split_nl(rest));
}

char	*split_nl(char **str)
{
	char	*before_nl;
	char	*after_nl;
	int		before_len;
	int		after_len;

	if (!found_nl(*str))
		return (*str);
	before_len = 0;
	after_len = 0;
	while ((*str)[before_len] != '\n')
		before_len++;
	before_nl = ft_strndup(*str, before_len + 1);
	if (!before_nl)
		return (gnl_free(str, 0));
	while ((*str)[before_len + 1 + after_len])
		after_len++;
	after_nl = ft_strndup(*str + before_len + 1, after_len);
	if (!after_nl)
		return (gnl_free(str, &before_nl));
	free(*str);
	*str = after_nl;
	return (before_nl);
}
