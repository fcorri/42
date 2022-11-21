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
	if (sizeof(unsigned long) > 4)
		output = ((output << 16) << 16) | output;
	return (output);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	dest;
	size_t	word;
	size_t	quozient;

	dest = (size_t) s;
	if (n >= sizeof(unsigned long))
	{
		word = ft_init_word(c);
		quozient = n / sizeof(word);
		n -= quozient * sizeof(word);
		while (quozient--)
		{
			*((unsigned long *) dest) = word;
			dest += sizeof(word);
		}
	}
	while (n--)
		*((unsigned char *) dest++) = (unsigned char) c;
	return (s);
}
