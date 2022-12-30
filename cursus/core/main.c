#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line/get_next_line.h"

int	main(void)
{
	int		fd;
	int		r;
	char	*line;

	fd = open("lorem", O_RDONLY);
	r = open("output", O_WRONLY);
	while ((line = get_next_line(fd)))
	{
		write(r, line, strlen(line));
		free(line);
	}
	free(line);
	close(fd);
	close(r);
	return (0);
}
