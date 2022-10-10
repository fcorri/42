#include "libft.h"

void	*memmove(void *dest, const void *src, size_t n)
{
	const char	*p_src;
	char		*p_dest;

	if (src != dest)
	{
		p_src = src;
		p_dest = dest;
		if (src < dest)
			while (n--)
				p_dest[n] = p_src[n];
		else
			while (n--)
				*p_dest++ = *p_src++;
	}
	return (dest);
}
