#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*input;

	input = ft_itoa(n);
	write(fd, input, ft_strlen(input));
	free(input);
}
