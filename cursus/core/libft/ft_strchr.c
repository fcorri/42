#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s++ != c)
		;
	return ((char *) s - 1);
}
