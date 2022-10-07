/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:07:19 by aperin            #+#    #+#             */
/*   Updated: 2022/10/07 14:12:00 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(char *str, int n)
{
	char	*dup;
	int		i;

	i = 0;
	while (str[i] && i < n)
		i++;
	dup = malloc((i + 1) * sizeof(char));
	if (!dup)
		return (0);
	i = 0;
	while (str[i] && i < n)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

int	found_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

char	*ft_strjoin_and_free(char *line, char *buf, int buf_len)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	while (line[i])
		i++;
	new_line = malloc((i + buf_len + 1) * sizeof(char));
	if (!new_line)
		return (gnl_free(line, buf));
	i = 0;
	while (line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	j = 0;
	while (j < buf_len)
	{
		new_line[i + j] = buf[j];
		j++;
	}
	new_line[i + j] = 0;
	free(line);
	return (new_line);
}
