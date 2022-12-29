#include "get_next_line.h"

char	*ft_strchr(char *s, char input)
{
	char	read;

	read = *s;
	while (read && read != input)
		read = *++s;
	if (read == input)
		return ((char *) s);
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	char	*tmp;

	tmp = s;
	while (*s)
		s++;
	return (s - tmp);
}

char	*ft_strdup(char *s, size_t len)
{
	char	*output;
	size_t	index;

	output = malloc(len + 1);
	if (!output)
		return (NULL);
	index = -1;
	while (++index < len)
		output[index] = s[index];
	output[index] = '\0';
	return (output);
}

char	*ft_strjoin(char **s1, char *s2, size_t br)
{
	char	*output;
	size_t	len1;
	size_t	index;

	if (!*s1)
		output = ft_strdup(s2, br);
	else
	{
		len1 = ft_strlen(*s1);
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
