#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;

	d_len = ft_strlen(dst);
	while (size - 1 > d_len && *src)
		*(dst + d_len++) = *src++;
	if (size - d_len - 1)
		return (size);
	*(dst + d_len) = '\0';
	return (d_len + ft_strlen(src));
}
