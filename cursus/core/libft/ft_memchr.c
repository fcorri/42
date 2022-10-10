#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p_s;
	unsigned char		input;

	p_s = s;
	input = c;
	while (n-- > 0 && *p_s++ != input)
		;
	if (*p_s == input)
		return ((void *) p_s);
	return (NULL);
}
