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
		*line = ft_strdup(newline + 1, ft_strlen(newline + 1));
		return (ft_free_and_return(tmp, buffer, output));
	}
	tmp = *line;
	*line = NULL;
	return (ft_free_and_return(NULL, buffer, tmp));
}

static void	ft_check_word(char *src, unsigned long input, unsigned long one, char **output, char **zero)
{
	unsigned long	word;

	word = *(unsigned long *)src ^ input;
	word = ((word - one) & ~word) & (one << 7);
	if (word != 0)
	{
		*output = src;
		while (*output != input)
			output++;
	}
	word = *(unsigned long *)src ^ 0x0;
	word = ((word - one) & ~word) & (one << 7);
	if (word != 0)
	{
		zero = src;
		while (*(char *)zero != 0)
			zero++;
	}
}

static char	*ft_memchr(char *s, char c)
{
	unsigned long	input;
	unsigned long	one;
	char		word;
	char		*output;
	char		*zero;

	while ((size_t) s % sizeof(unsigned long))
	{
		word = *s++;
		if (word == c)
			return (s - 1);
		if (word == '\0')
			return (NULL);
	}
	ft_init(&input, c, &one, &output, &zero);
	while (output && zero)
	{
		ft_check_word(s, input, one, &output, &zero);
		s = s + sizeof(unsigned long);
	}
	if (output && zero && output <= zero)
		return (output);
	return (NULL);
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
