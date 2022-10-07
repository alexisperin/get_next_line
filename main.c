/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:00:13 by aperin            #+#    #+#             */
/*   Updated: 2022/10/07 14:49:36 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*split_nl(char **str);

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	/*
	while (line)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	*/
	close(fd);
}
