/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:00:13 by aperin            #+#    #+#             */
/*   Updated: 2022/10/10 16:03:53 by aperin           ###   ########.fr       */
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
	int i = 0;

	fd = open("test", O_RDONLY);
	line = get_next_line(fd);
	while (i < 10)
	{
		printf("%s", line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}
