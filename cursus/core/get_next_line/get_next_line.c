#include "get_next_line.h"

static char	*ft_return(char **line, char *newline, char *buffer)
{
	char	*output;
	char	*tmp;
	size_t	len;

	len = newline - *line + 1;
	output = malloc(sizeof(char) * (len + 1));
	memcpy(output, *line, len);
	output[len] = '\0';
	tmp = ft_strdup(++newline);
	free(*line);
	*line = tmp;
	free(buffer);
	return (output);
}

char	*get_next_line(int fd, size_t BUFFER_SIZE)
{
	static char	*line;
	char		*buffer;
	ssize_t		rb;
	char		*newline;

	buffer = calloc(BUFFER_SIZE, 1);
	rb = read(fd, buffer, BUFFER_SIZE);
	while (rb != -1 && rb != 0)
	{
		if(!ft_strjoin(&line, buffer))
			return (NULL);
		newline = strchr(line, '\n');
		if (newline)
			return (ft_return(&line, newline, buffer));
		rb = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (NULL);
}
