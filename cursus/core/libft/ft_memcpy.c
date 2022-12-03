/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:21:00 by fcorri            #+#    #+#             */
/*   Updated: 2022/11/21 15:12:13 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	ft_read_word(size_t src)
{
	int	right;
	int	left;

	right = src % sizeof(unsigned long);
	if (right == 0)
		return (*(unsigned long *)src);
	left = sizeof(unsigned long) - right;
	return (
		*(unsigned long *)(src - right) >> (right * 8)
		| *(unsigned long *)(src + left) << (left * 8)
	);
}

static size_t	ft_set_words(size_t *p_dest, size_t *p_src, size_t n)
{
	size_t	dest;
	size_t	src;
	size_t	quozient;

	dest = *p_dest;
	src = *p_src;
	quozient = n / sizeof(unsigned long);
	n -= quozient * sizeof(unsigned long);
	while (quozient--)
	{
		*((unsigned long *) dest) = ft_read_word(src);
		dest += sizeof(unsigned long);
		src += sizeof(unsigned long);
	}
	*p_dest = dest;
	*p_src = src;
	return (n);
}

void	*ft_memcpy(void *p_dest, const void *p_src, size_t n)
{
	size_t	dest;
	size_t	src;
	size_t	remainder;

	if (!n || p_dest == p_src)
		return (p_dest);
	dest = (size_t) p_dest;
	src = (size_t) p_src;
	if (n >= 4 * sizeof(unsigned long))
	{
		remainder = dest % sizeof(unsigned long);
		n -= remainder;
		while (remainder--)
			*((unsigned char *) dest++) = *((unsigned char *) src++);
		n = ft_set_words(&dest, &src, n);
	}
	while (n--)
		*((unsigned char *) dest++) = *((unsigned char *) src++);
	return (p_dest);
}
