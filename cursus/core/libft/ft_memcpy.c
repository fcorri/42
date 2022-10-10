#include "libft.h"

void	*memcpy(void *dest, const void *src, size_t n)
{
	const char	*p_src;
	char		*p_dest;

	if (src == dest)
		return (dest);
	p_src = src;
	p_dest = dest;
	while (n--)
		*p_dest++ = *p_src++;
	return (dest);
}
