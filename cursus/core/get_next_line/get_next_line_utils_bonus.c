#include "get_next_line_bonus.h"

char	*ft_strchr_gnl(char *s, char input)
{
	char	read;

	read = *s;
	while (read && read != input)
		read = *++s;
	if (read == input)
		return ((char *) s);
	return (NULL);
}

size_t	ft_strlen_gnl(char *s)
{
	char	*tmp;

	tmp = s;
	while (*s)
		s++;
	return (s - tmp);
}
