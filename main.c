#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int		fd;
	int		rd;
	char	*str;

	fd = open("testtxt.txt", O_RDONLY);
	printf("==================\n");
	// str = get_next_line(fd);
	// printf("%s", str);
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
	close(fd);
}