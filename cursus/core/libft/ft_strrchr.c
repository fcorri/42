#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	while (*s++ != 0)
		;
	while (*s-- != c)
		;
	return ((char *) s + 1);
}
