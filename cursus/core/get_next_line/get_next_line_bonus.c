#include "get_next_line_bonus.h"

static char    *ft_strdup(char *s, size_t len)
{
    char    *output;
    size_t  index;

    output = malloc(len + 1); 
    if (!output)
        return (NULL);
    index = -1; 
    while (++index < len)
        output[index] = s[index];
    output[index] = '\0';
    return (output);
}

static char    *ft_strjoin(char **s1, char *s2, size_t br) 
{
    char    *output;
    size_t  len1;
    size_t  index;

    if (!*s1)
        output = ft_strdup(s2, br);
    else
    {   
        len1 = ft_strlen_gnl(*s1);
        output = malloc(len1 + br + 1); 
        if (!output)
            return (NULL);
        index = -1; 
        while (++index < len1)
            output[index] = (*s1)[index];
        index = -1;
        while (++index < br)
            output[len1 + index] = s2[index];
        output[len1 + index] = '\0';
        free(*s1);
    }
    *s1 = output;
    return (output);
}

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
		*line = ft_strdup(newline + 1, ft_strlen_gnl(newline + 1));
		return (ft_free_and_return(tmp, buffer, output));
	}
	tmp = *line;
	*line = NULL;
	return (ft_free_and_return(NULL, buffer, tmp));
}

char	*get_next_line(int fd)
{
	static char	*line[1024];
	char		*buffer;
	ssize_t		br;
	char		*newline;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE);
	br = read(fd, buffer, BUFFER_SIZE);
	while (br > 0)
	{
		if (!ft_strjoin(&(line[fd]), buffer, br))
			return (ft_free_and_return(line[fd], buffer, NULL));
		newline = ft_strchr_gnl(line[fd], '\n');
		if (newline)
			return (ft_return(&(line[fd]), newline, buffer));
		br = read(fd, buffer, BUFFER_SIZE);
	}
	if (line[fd])
		return (ft_return(&(line[fd]), ft_strchr_gnl(line[fd], '\n'), buffer));
	return (ft_free_and_return(line[fd], buffer, NULL));
}
