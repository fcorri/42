#include "libft.h"

unsigned long	ft_init_word(unsigned char c)
{
	unsigned long	word;

	word = c | (c << 8);
	word |= word << 16;
	if (sizeof(unsigned long) > 4)
		word |= ((word << 16) << 16);
	return (word);
}

unsigned long	ft_init_one(void)
{
	unsigned long	one;

	one = 0x01 | (0x01 << 8);
	one |= one << 16;
	if (sizeof(unsigned long) > 4)
		one |= ((one << 16) << 16);
	return (one);
}

void	ft_move_word(size_t dest, size_t src)
{
	int	right;
	int	left;
	size_t	size;

	size = sizeof(unsigned long);
	right = dest & (size - 1);
	if (right == 0)
		*(unsigned long *)dest = *(unsigned long *)src;
	else
	{
		left = (size - right);
		*(unsigned long *)(dest + left) = (*(unsigned long *)(dest + left)
				>> right * 8) << right * 8
			| *(unsigned long *)src >> left * 8;
		*(unsigned long *)(dest - right) = (*(unsigned long *)(dest - right)
				<< left * 8) >> left * 8
			| *(unsigned long*)src << right * 8;
	}
}

size_t	ft_move_words(size_t *p_dest, size_t *p_src, size_t n)
{
	size_t	dest;
	size_t	src;
	size_t	quozient;
	size_t	size;

	dest = *p_dest;
	src = *p_src;
	size = sizeof(unsigned long);
	quozient = n / size;
	if (!quozient)
		return (n);
	n -= quozient * size;
	while (quozient--)
	{
		dest -= size;
		src -= size;
		ft_move_word(dest, src);
	}
	*p_dest = dest - 1;
	*p_src = src - 1;
	return (n);
}

void	ft_set_words(uintptr_t *p_dest, unsigned long word, size_t *p_n)
{
	unsigned long	*dest;
	size_t	quozient;
	size_t	size;
	size_t	n;

	dest = (unsigned long *)*p_dest;
	size = sizeof(unsigned long);
	n = *p_n;
	quozient = n / size;
	n -= quozient * size;
	if (!quozient)
		return ;
	while (quozient--)
		*dest++ = word;
	*p_dest = (uintptr_t) dest;
	*p_n = n;
}
