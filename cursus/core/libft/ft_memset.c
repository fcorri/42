/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:14:03 by fcorri            #+#    #+#             */
/*   Updated: 2022/11/16 18:13:47 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_init_word(unsigned long *word, unsigned char c)
{
	*word = c;
	*word = (*word << 8) | *word;
	*word = (*word << 16) | *word;
	if (sizeof(word) > 4)
		*word = (*word << 32) | *word;
}

static size_t	ft_set_padding(size_t dest, unsigned char c, size_t n)
{
	size_t	remainder;

	remainder = dest % sizeof(unsigned long);
	n -= remainder;
	while (remainder--)
		*((unsigned char *) dest++) = c;
	return (n);
}

static size_t	ft_set_words(size_t dest, unsigned long word, size_t n)
{
	size_t	quozient;

	quozient = n / sizeof(word);
	n -= quozient * sizeof(word);
	while (quozient--)
	{
		*((unsigned long *) dest) = word;
		dest += sizeof(word);
	}
	return (n);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			dest;
	unsigned long	word;

	dest = (size_t) s;
	if (n >= 8)
	{
		ft_init_word(&word, c);
		n = ft_set_padding(dest, (unsigned char) c, n);
		n = ft_set_words(dest, word, n) * sizeof(word);
	}
	while (n--)
		*((unsigned char *) s++) = (unsigned char) c;
	return (s);
}
