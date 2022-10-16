#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	int		cont;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	cont = 0;
	while (size > d_len + 1 + cont++ && *src)
		*(dst++ + d_len) = *src++;
	if (size < d_len + cont)
		return (size + s_len);
	*(dst + d_len) = '\0';
	return (d_len + s_len);
}
