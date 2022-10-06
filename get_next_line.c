/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:07:21 by aperin            #+#    #+#             */
/*   Updated: 2022/10/06 18:34:13 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*read_line(int fd, char *line, char *buf);

char	*get_next_line(int fd)
{
	static char	*line = 0;
	char		*buf;
	char		*res;

	if (!line)
	{
		line = malloc(sizeof(char));
		if (!line)
			return (0);
		line[0] = 0;
	}
	if (found_nl(line))
		res = remove_nl(line);
	else
	{
		buf = malloc(BUFFER_SIZE * sizeof(char));
		if (!buf)
			return (gnl_free(line, 0));
		res = read_line(fd, line, buf);
	}
	if (!res)
		return (gnl_free(line, buf));
	return (res);
}

char	*read_line(int fd, char *line, char *buf)
{
}

static char	*gnl_free(char *line, char *buf)
{
	free(line);
	free(buf);
	return (0);
}
