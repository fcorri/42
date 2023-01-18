#include <stdio.h>
#include "get_next_line.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int reading = open("./lorem", O_RDONLY);
	int	writing = open("./output", O_WRONLY);
	char *line;
	while ((line = get_next_line(reading)))
	{
		write(writing, line, ft_strlen(line));
		free(line);
	}
	close(reading);
	close(writing);
	return (0);
}
