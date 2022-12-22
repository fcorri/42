#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line/get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		r;
	char	*line;
	size_t	BUFFER_SIZE;

	if (argc == 1)
		return (0);
	BUFFER_SIZE = atoi(argv[1]);
	fd = open("lorem", O_RDONLY);
	r = open("output", O_WRONLY);
	while ((line = get_next_line(fd, BUFFER_SIZE)))
		write(r, line, strlen(line));
	free(line);
	close(fd);
	close(r);
	return (0);
}
