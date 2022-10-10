#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*pntr;
	char	input;

	pntr = s;
	input = c;
	while (n--)
		pntr[n] = input;
	return (s);
}
