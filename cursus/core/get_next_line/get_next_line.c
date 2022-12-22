#include "get_next_line.h"

static void	*ft_return_null(char *line, char *buffer)
{
	free(line);
	free(buffer);
	return (NULL);
}

static char	*ft_return_new(char **line, char *newline, char *buffer)
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

static char	*ft_return_last(char **line)
{
	char	*output;

	output = *line;
	*line = NULL;
	return (output);
}

char	*get_next_line(int fd, size_t BUFFER_SIZE)
{
	static char	*line;
	char		*buffer;
	ssize_t		rb;
	char		*newline;

	buffer = calloc(BUFFER_SIZE + 1, 1);
	rb = read(fd, buffer, BUFFER_SIZE);
	while (rb != -1 && rb != 0)
	{
		if (!ft_strjoin(&line, buffer))
			ft_return_null(line, buffer);
		newline = strchr(line, '\n');
		if (newline)
			return (ft_return_new(&line, newline, buffer));
		rb = read(fd, buffer, BUFFER_SIZE);
		buffer[rb] = '\0';
	}
	if (line && *line)
	{
		newline = strchr(line, '\n');
		if (newline)
			return (ft_return_new(&line, newline, buffer));
		return (ft_return_last(&line));
	}
	return (NULL);
}
