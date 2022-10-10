/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:07:19 by aperin            #+#    #+#             */
/*   Updated: 2022/10/10 16:19:21 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(char *str, int n)
{
	char	*dup;
	int		i;

	i = 0;
	if (n == 0)
	{
		while (str[i])
			i++;
	}
	else
	{
		while (str[i] && i < n)
			i++;
	}
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

char	*ft_strjoin_and_free(char *rest, char *buf, int buf_len)
{
	int		i;
	int		j;
	char	*new_rest;

	if (buf_len < 1)
		return (rest);
	i = 0;
	while (rest[i])
		i++;
	new_rest = malloc((i + buf_len + 1) * sizeof(char));
	if (!new_rest)
		return (0);
	i = -1;
	while (rest[++i])
		new_rest[i] = rest[i];
	j = -1;
	while (++j < buf_len)
		new_rest[i + j] = buf[j];
	new_rest[i + j] = 0;
	free(rest);
	rest = 0;
	return (new_rest);
}
