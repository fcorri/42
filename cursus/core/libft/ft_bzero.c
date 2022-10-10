#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*pntr;

	pntr = s;
	while (n--)
		pntr[n] = '\0';
}
