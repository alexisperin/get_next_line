/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:07:19 by aperin            #+#    #+#             */
/*   Updated: 2022/10/25 09:15:36 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_free(char **str1, char **str2)
{
	if (str1)
	{
		free(*str1);
		*str1 = 0;
	}
	if (str2)
	{
		free(*str2);
		*str2 = 0;
	}
	return (0);
}

char	*ft_strndup(char *str, int n)
{
	char	*dup;
	int		i;

	i = 0;
	if (n == 0)
	{
		while (str[i])
			i++;
		n = i;
	}
	else
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

int	found_nl(char *str, int n)
{
	int	i;

	if (!str || n == 0)
		return (0);
	i = 0;
	if (n == -1)
		while (str[i] && str[i] != '\n')
			i++;
	else
		while (str[i] && str[i] != '\n' && i < n)
			i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

char	*ft_strjoin_and_free(char *save, char *buf, int buf_len)
{
	int		i;
	int		j;
	char	*new_save;

	if (buf_len < 1)
		return (0);
	i = 0;
	while (save[i])
		i++;
	new_save = malloc((i + buf_len + 1) * sizeof(char));
	if (!new_save)
		return (0);
	i = -1;
	while (save[++i])
		new_save[i] = save[i];
	j = -1;
	while (++j < buf_len)
		new_save[i + j] = buf[j];
	new_save[i + j] = 0;
	free(save);
	return (new_save);
}
