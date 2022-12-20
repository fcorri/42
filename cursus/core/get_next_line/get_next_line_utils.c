#include "get_next_line.h"
#include <bsd/string.h>

char	*ft_strdup(char *s)
{
	char	*output;
	size_t	buffer_len;

	buffer_len = strlen(s) + 1;
	output = malloc(buffer_len);
	if (!output)
		return (NULL);
	memcpy(output, s, buffer_len);
	return (output);
}

char	*ft_strjoin(char **s1, char *s2)
{
	char	*output;
	size_t	len1;
	size_t	len2;

	if (!*s1)
		output = ft_strdup(s2);
	else
	{
		len1 = strlen(*s1);
		len2 = strlen(s2);
		output = calloc(len1 + len2 + 1, 1);
		if (!output)
			return (NULL);
		strlcpy(output, *s1, len1 + 1);
		strlcat(output + len1, s2, len2 + 1);
		free(*s1);
	}
	*s1 = output;
	return (output);
}
