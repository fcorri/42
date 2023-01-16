#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

int main(void)
{
	int	reading = open("lorem", O_RDONLY);
	char	**output;
	char	*buffer;
	size_t	i = 0;
	char	*line;

	buffer = (char *) malloc(sizeof(char) * 446);
	read(reading, buffer, 447);
	output = ft_split("          ", ' ');
	while ((line = output[i++]))
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		free(line);
	}
	close(reading);
	free(output);
	return (0);
}
