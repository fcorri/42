/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:14:03 by fcorri            #+#    #+#             */
/*   Updated: 2022/11/21 15:04:00 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	ft_init_word(unsigned char c)
{
	unsigned long	output;

	output = c;
	output = (output << 8) | output;
	output = (output << 16) | output;
	if (sizeof(output) > 4)
		output = ((output << 16) << 16) | output;
	return (output);
}

static size_t	ft_set_words(size_t *p_dest, unsigned long word, size_t n)
{
	size_t	dest;
	size_t	quozient;
	size_t	size;

	dest = *p_dest;
	size = sizeof(unsigned long);
	quozient = n / size;
	if (!quozient)
		return (n);
	n -= quozient * size;
	while (quozient--)
	{
		*((unsigned long *) dest) = word;
		dest += size;
	}
	*p_dest = dest;
	return (n);
}

void	*ft_memset(void *p_dest, int c, size_t n)
{
	size_t	dest;
	size_t	div_result;
	size_t	size;

	if (!n)
		return (p_dest);
	dest = (size_t) p_dest;
	size = sizeof(unsigned long);
	if (n >= 4 * size)
	{
		div_result = dest & (size - 1);
		n -= (size - div_result);
		while (size - div_result++)
			*((unsigned char *) dest++) = (unsigned char) c;
		n = ft_set_words(&dest, ft_init_word(c), n);
	}
	while (n--)
		*((unsigned char *) dest++) = (unsigned char) c;
	return (p_dest);
}
