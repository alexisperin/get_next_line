/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:07:21 by aperin            #+#    #+#             */
/*   Updated: 2022/10/28 15:10:52 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "get_next_line_bonus.h"

static char	*after_nl(char *save, size_t nl_index)
{
	size_t	i;
	char	*res;

	i = 0;
	while (save[nl_index + i])
		i++;
	if (!i)
		return (gnl_free(save, 0));
	res = malloc((i + 1) * sizeof(char));
	if (!res)
		return (gnl_free(save, 0));
	i = 0;
	while (save[nl_index + i])
	{
		res[i] = save[nl_index + i];
		i++;
	}
	res[i] = 0;
	free(save);
	return (res);
}

static char	*until_nl(char *save, size_t *nl_index)
{
	size_t	i;
	char	*res;

	if (save[0] == 0)
		return (0);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	*nl_index = i;
	res = malloc((i + 1) * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (i < *nl_index)
	{
		res[i] = save[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

static char	*read_line(int fd, char *save)
{
	char	*buf;
	int		ret;
	size_t	save_len;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (gnl_free(save, 0));
	buf[0] = 0;
	ret = 1;
	save_len = ft_strlen(save);
	while (ret && !found_nl(buf))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (gnl_free(save, buf));
		buf[ret] = 0;
		save_len += ret;
		save = strjoin_free(save, buf, save_len);
		if (!save)
			return (gnl_free(buf, 0));
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*res;
	size_t		nl_index;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE < 1)
		return (0);
	if (!found_nl(save[fd]))
	{
		save[fd] = read_line(fd, save[fd]);
		if (!save[fd])
			return (0);
	}
	res = until_nl(save[fd], &nl_index);
	if (!res)
	{
		free(save[fd]);
		save[fd] = 0;
		return (0);
	}
	save[fd] = after_nl(save[fd], nl_index);
	return (res);
}
