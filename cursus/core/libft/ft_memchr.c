/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:20:52 by fcorri            #+#    #+#             */
/*   Updated: 2022/11/09 17:17:40 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	ft_input(unsigned char c)
{
	unsigned long	input;

	input = c | (c << 8);
	input |= input << 16;
	if (sizeof(unsigned long) > 4)
		input |= ((input << 16) << 16);
	return (input);
}

static unsigned long	ft_init_one(void)
{
	unsigned long	one;

	one = 0x01 | (0x01 << 8);
	one |= one << 16;
	if (sizeof(unsigned long) > 4)
		one |= ((one << 16) << 16);
	return (one);
}

static size_t	ft_check_words(size_t *p_dest, size_t n, unsigned long input)
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

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	dest;
	size_t	remainder;
	size_t	size;

	if (n == 0)
		return (NULL);
	dest = (size_t) s;
	size = sizeof(unsigned long);
	if (n >= 4 * size)
	{
		remainder = dest % size;
		n -= (size - remainder);
		while (size - remainder++)
			if (*((unsigned char *) dest++) == (unsigned char) c)
				return ((void *)(dest - 1));
		n = ft_check_words(&dest, n, ft_input(c));
	}
	while (n--)
	{
		if (*((unsigned char *) dest++) == (unsigned char) c)
			return ((void *)(dest - 1));
	}
	return (NULL);
}
