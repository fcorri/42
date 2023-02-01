/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:56:06 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/19 18:23:56 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static void	ft_copy_words(size_t dest, size_t src, size_t n)
{
	
}

size_t	ft_strlcpy_new(char *p_dest, const char *p_src, size_t n)
{
	size_t	dest;
	size_t	src;
	size_t	size;
	size_t	remainder;
	char	input;

	dest = (size_t) p_dest;
	src = (size_t) p_src;
	size = sizeof(unsigned long);
	remainder = (size_t) p_dest % size;
	if (remainder)
	{
		input = *(unsigned char *)src++;
		while (input && size - remainder++)
		{
			*(unsigned char *)dest++ = input;
			n--;
			input = *(unsigned char *)src++;
		}
	}
	if (n && input)
		ft_copy_words(dest, src - 1, n);
	return (ft_strlen(p_src));
}
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	if (size == 0)
	{
		index = -1;
		while (++index < size - 1 && src[index])
			dst[index] = src[index];
		dst[index] = 0;
	}
	return (ft_strlen(src));
}
