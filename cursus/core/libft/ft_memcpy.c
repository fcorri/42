/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:21:00 by fcorri            #+#    #+#             */
/*   Updated: 2022/11/16 18:44:01 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_set_padding(size_t dest, size_t src)
{
	size_t	remainder;
	int		output;

	remainder = dest % sizeof(unsigned long);
	output = remainder;
	while (remainder--)
		*((unsigned char *) dest++) = *((unsigned char *) src++);
	return (output);
}

static unsigned long	ft_init_word(size_t src)
{
	unsigned long	output;
	unsigned long	input;
	int				offset;

	offset = src % sizeof(unsigned long);
	input = *((unsigned long *)(src - offset));
	input = input >> offset * 8;
	output = *((unsigned long *)(src + (sizeof(unsigned long) - offset)));
	output = (output << ((sizeof(unsigned long) - offset) * 8)) | input;
	return (output);
}

static size_t	ft_set_words(size_t dest, size_t src, size_t n)
{
	unsigned long	word;
	size_t			quozient;
	size_t			output;

	quozient = n / sizeof(word);
	output = quozient;
	while (quozient--)
	{
		*((unsigned long *) dest) = ft_init_word(src);
		dest += sizeof(word);
		src += sizeof(word);
	}
	return (output);
}

void	ft_increment_by(size_t *dest, size_t *src, size_t *n, size_t bytes)
{
	*n -= bytes;
	*dest += bytes;
	*src += bytes;
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	p_dest;
	size_t	p_src;
	size_t	wrote;

	if (!dest && !src)
		return (NULL);
	if (dest == src)
		return (dest);
	p_dest = (size_t) dest;
	p_src = (size_t) src;
	if (n >= 8)
	{
		wrote = ft_set_padding(p_dest, p_src);
		if (wrote)
			ft_increment_by(&p_dest, &p_src, &n, wrote);
		wrote = ft_set_words(p_dest, p_src, n) * sizeof(unsigned long);
		if (wrote)
			ft_increment_by(&p_dest, &p_src, &n, wrote);
	}
	while (n--)
		*((unsigned char *) p_dest++) = *((unsigned char *) p_src++);
	return (dest);
}
