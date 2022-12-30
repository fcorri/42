#include "get_next_line.h"

static char	*ft_free_and_return(char *line, char *buffer, char *output)
{
	free(line);
	free(buffer);
	return (output);
}

static char	*ft_return(char **line, char *newline, char *buffer)
{
	char	*output;
	char	*tmp;

	if (!**line)
		return (ft_free_and_return(*line, buffer, NULL));
	if (newline)
	{
		output = ft_strdup(*line, newline - *line + 1);
		tmp = *line;
		*line = ft_strdup(newline + 1, (ft_strchr(newline + 1, '\0') - newline + 1));
		return (ft_free_and_return(tmp, buffer, output));
	}
	tmp = *line;
	*line = NULL;
	return (ft_free_and_return(NULL, buffer, tmp));
}

static char	*ft_check_words(char *src, char c)
{
	unsigned long	word;
	unsigned long	input;
	unsigned long	one;
	char			*output;
	char			*zero;

	ft_init(&input, c, &one);
	output = NULL;
	zero = NULL;
	while (1)
	{
		ft_checkword(src, input, one, &output);
		if (c)
			ft_checkword(src, '\0', one, &zero);
		if (output && (output <= zero || !zero))
			return (output);
		else if (zero)
			return (NULL);
		src += sizeof(word);
	}
}

char	*ft_strchr(char *src, char c)
{
	char		word;

	while ((size_t) src % sizeof(unsigned long))
	{
		word = *src++;
		if (word == c)
			return (src - 1);
		if (word == '\0')
			return (NULL);
	}
	return (ft_check_words(src, c));
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	ssize_t		br;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE);
	br = read(fd, buffer, BUFFER_SIZE);
	while (br > 0)
	{
		if (!ft_strjoin(&line, buffer, br))
			return (ft_free_and_return(line, buffer, NULL));
		newline = ft_strchr(line, '\n');
		if (newline)
			return (ft_return(&line, newline, buffer));
		br = read(fd, buffer, BUFFER_SIZE);
	}
	if (line)
		return (ft_return(&line, ft_strchr(line, '\n'), buffer));
	return (ft_free_and_return(line, buffer, NULL));
}
