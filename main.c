/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:00:13 by aperin            #+#    #+#             */
/*   Updated: 2022/10/06 17:03:43 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!src)
		return (0);
	if (!dst || size < 1)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

char	*ft_strdup(const char *str)
{
	int		len;
	char	*dup;

	len = (int) ft_strlen(str);
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (0);
	ft_strlcpy(dup, str, len + 1);
	return (dup);
}

void	func(void)
{
	static char	*x = 0;
	static int	i = 0;

	if (!x)
		x = ft_strdup("aaaaa");

	x[i] = 'a' + i;
	i++;
	printf("%s\n", x);
}

int	main(void)
{
	/*
	func();
	func();
	func();
	func();
	func();
	*/
	get_next_line(0);
	return (0);
}
