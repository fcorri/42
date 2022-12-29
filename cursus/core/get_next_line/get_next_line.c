#include "get_next_line.h"

static void	*ft_return_null(char *line, char *buffer)
{
	if (line)
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
	tmp = ft_strdup(newline + 1, ft_strlen(newline + 1));
	free(*line);
	*line = tmp;
	free(buffer);
	return (output);
}

static char	*ft_return_last(char **line, char *buffer)
{
	char	*output;

	output = *line;
	*line = NULL;
	free(buffer);
	return (output);
}

/*char	*ft_return(char *line, char *buffer)
{
	char	*newline;

	free(buffer);
	if (line && *line)
		newline = ft_strchr(line, '\n');
		if (newline)
			return (ft_return_new());
		return (ft_return_last());
	return (ft_return_null());
}*/

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	ssize_t		br;
	char		*newline;

	buffer = malloc(BUFFER_SIZE);
	br = read(fd, buffer, BUFFER_SIZE);
	while (br > 0)
	{
		if (!ft_strjoin(&line, buffer, br))
			ft_return_null(line, buffer);
		newline = strchr(line, '\n');
		if (newline)
			return (ft_return_new(&line, newline, buffer));
		br = read(fd, buffer, BUFFER_SIZE);
	}
	if (line && *line)
	{
		newline = strchr(line, '\n');
		if (newline)
			return (ft_return_new(&line, newline, buffer));
		return (ft_return_last(&line, buffer));
	}
	return (ft_return_null(line, buffer));
//	return (ft_return(&line, buffer));
}
