#include <stdio.h>
#include <fcntl.h>

#include "get_next_line.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*str;

	(void) ac;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error: open\n");
		exit(1);
	}
	str = get_next_line(fd);
	while (str)
	{
		printf("%s\n", str);
		free(str);
		str = get_next_line(fd);
	}
	str = get_next_line(fd);
	if (str)
		printf("str not null at the end\n");
	return (0);
}