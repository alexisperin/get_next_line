/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:07:21 by aperin            #+#    #+#             */
/*   Updated: 2022/10/25 09:19:15 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "get_next_line.h"

char	*split_nl(char **save)
{
	char	*before_nl;
	char	*after_nl;
	int		before_len;
	int		after_len;

	if (!found_nl(*save, -1))
		return (*save);
	before_len = 0;
	after_len = 0;
	while ((*save)[before_len] != '\n')
		before_len++;
	before_nl = ft_strndup(*save, before_len + 1);
	if (!before_nl)
		return (gnl_free(save, 0));
	while ((*save)[before_len + 1 + after_len])
		after_len++;
	after_nl = ft_strndup(*save + before_len + 1, after_len);
	if (!after_nl)
		return (gnl_free(save, &before_nl));
	free(*save);
	*save = after_nl;
	return (before_nl);
}

char	*read_line(int fd, char **save, char *buf)
{
	int		ret;

	if (found_nl(*save, -1))
		return (split_nl(save));
	ret = 0;
	while (!found_nl(buf, ret))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (0);
		if (ret == 0)
			break ;
		*save = ft_strjoin_and_free(*save, buf, ret);
		if (!(*save))
			return (0);
	}
	if (ret == 0 && *(save)[0] == 0)
		return (0);
	return (split_nl(save));
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (!save)
		save = ft_strndup("", 0);
	buf = malloc(BUFFER_SIZE * sizeof(char));
	if (!save || !buf)
		return (gnl_free(&save, &buf));
	line = read_line(fd, &save, buf);
	free(buf);
	if (!line)
		return (gnl_free(&save, 0));
	if (!found_nl(line, -1))
	{
		line = ft_strndup(line, 0);
		gnl_free(&save, 0);
	}
	return (line);
}
