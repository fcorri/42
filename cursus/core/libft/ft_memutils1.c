#include "libft.h"

size_t	ft_chr_words(size_t *p_dest, unsigned long input, size_t n)
{
	size_t			dest;
	unsigned long	word;
	unsigned long	one;
	size_t			quozient;
	size_t			size;

	dest = *p_dest;
	one = ft_init_one();
	size = sizeof(unsigned long);
	quozient = n / size;
	while (quozient--)
	{
		word = *((unsigned long *) dest) ^ input;
		word = ((word - one) & ~word) & (one << 7);
		if (word != 0)
			break ;
		n -= size;
		dest += size;
	}
	*p_dest = dest;
	return (n);
}

int	ft_cmp_bytes(size_t *p_p1, size_t *p_p2, size_t *p_n)
{
	size_t	p1;
	size_t	p2;
	int		remainder;
	size_t	size;

	p1 = *p_p1;
	p2 = *p_p2;
	size = sizeof(unsigned long);
	remainder = p1 & (size - 1);
	*p_n -= (size - remainder);
	while (size - remainder && *(unsigned char *)p1 == *(unsigned char *)p2)
	{
		remainder++;
		p1++;
		p2++;
	}
	*p_p1 = p1;
	*p_p2 = p2;
	return (size - remainder);
}

unsigned long	ft_read_word(size_t src)
{
	int		right;
	int		left;
	size_t	size;

	size = sizeof(unsigned long);
	right = src & (size - 1);
	if (right == 0)
		return (*(unsigned long *)src);
	left = size - right;
	return (
		*(unsigned long *)(src - right) >> (right * 8)
		| *(unsigned long *)(src + left) << (left * 8)
	);
}

int	ft_cmp_words(size_t *p_p1, size_t *p_p2, size_t *p_n)
{
	size_t	p1;
	size_t	p2;
	int		quozient;
	size_t	size;

	p1 = *p_p1;
	p2 = *p_p2;
	size = sizeof(unsigned long);
	quozient = *p_n / size;
	*p_n -= quozient * size;
	while (quozient--)
	{
		if (*(unsigned long *)p1 != ft_read_word(p2))
		{
			*p_p1 = p1;
			*p_p2 = p2;
			return (ft_cmp_bytes(p_p1, p_p2, p_n));
		}
		p1 += size;
		p2 += size;
	}
	*p_p1 = p1;
	*p_p2 = p2;
	return (0);
}

size_t	ft_cpy_words(size_t *p_dest, size_t *p_src, size_t n)
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
		*((unsigned long *) dest) = ft_read_word(src);
		dest += size;
		src += size;
	}
	*p_dest = dest;
	*p_src = src;
	return (n);
}
