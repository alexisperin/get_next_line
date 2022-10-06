/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:07:19 by aperin            #+#    #+#             */
/*   Updated: 2022/10/06 18:32:12 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*remove_nl(char *str)
{
	char	*before_nl;
	char	*after_nl;
	int		before_nl_len;
	int		after_nl_len;

	before_nl_len = 0;
	while (str[before_nl_len] != '\n')
		before_nl_len++;
	before_nl = ft_strndup(str, before_nl_len + 1);
	if (before_nl)
	{
		after_nl_len = 0;
		while (str[before_nl_len + after_nl_len])
			after_nl_len++;
		after_nl = ft_strndup(&str[before_nl_len + 1], after_nl_len);
		if (!after_nl)
		{
			free(before_nl);
			return (0);
		}
	}
	free(str);
	str = after_nl;
	return (before_nl);
}
