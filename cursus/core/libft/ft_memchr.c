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
		n = ft_chr_words(&dest, ft_init_word(c), n);
	}
	while (n--)
	{
		if (*((unsigned char *) dest++) == (unsigned char) c)
			return ((void *)(dest - 1));
	}
	return (NULL);
}
