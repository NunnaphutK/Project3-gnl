#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		rd;
	char	*str;

	fd = open("testtxt.txt", O_RDONLY);
	// get_next_line(fd);
	printf("==================\n");
	str = get_next_line(fd);
	printf("%s", str);
	// int i = 10;
	// while (i > 0)
	// {
	// 	str = get_next_line(fd);
	// 	printf("%s", str);
	// 	free(str);
	// 	i--;
	// }
	close(fd);
}