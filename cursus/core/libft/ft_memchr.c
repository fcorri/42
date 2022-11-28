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

static unsigned long	ft_init_input(unsigned char c)
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

static void	ft_check_words(size_t *p_dest, size_t *p_n,
	unsigned long input, unsigned long one)
{
	size_t			dest;
	unsigned long	word;
	size_t			quozient;
	size_t			n;

	dest = *p_dest;
	n = *p_n;
	quozient = n / sizeof(unsigned long);
	while (quozient--)
	{
		word = *((unsigned long *) dest) ^ input;
		word = ((word - one) & ~word) & (one << 7);
		if (word != 0)
			break ;
		n -= sizeof(unsigned long);
		dest += sizeof(unsigned long);
	}
	*p_dest = dest;
	*p_n = n;
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			dest;
	unsigned long	input;
	unsigned long	one;

	if (n != 0)
	{
		dest = (size_t) s;
		input = ft_init_input(c);
		one = ft_init_one();
		ft_check_words(&dest, &n, input, one);
		while (n--)
		{
			if (*((unsigned char *) dest++) == (unsigned char) c)
				return ((void *)(dest - 1));
		}
	}
	return (NULL);
}
