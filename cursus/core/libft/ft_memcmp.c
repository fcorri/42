/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:21:08 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/20 16:42:44 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_bytes(size_t *p_p1, size_t *p_p2, size_t *p_n)
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

static unsigned long	ft_read_word(size_t src)
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

static int	ft_check_words(size_t *p_p1, size_t *p_p2, size_t *p_n)
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
			return (ft_check_bytes(p_p1, p_p2, p_n));
		}
		p1 += size;
		p2 += size;
	}
	*p_p1 = p1;
	*p_p2 = p2;
	return (0);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	p1;
	size_t	p2;
	int		output;

	if (n == 0)
		return (0);
	p1 = (size_t) s1;
	p2 = (size_t) s2;
	if (n >= 4 * sizeof(unsigned long)
		&& (ft_check_bytes(&p1, &p2, &n) || ft_check_words(&p1, &p2, &n)))
		return (*(unsigned char *)p1 - *(unsigned char *)p2);
	while (n--)
	{
		output = *(unsigned char *)p1++ - *(unsigned char *)p2++;
		if (output != 0)
			return (output);
	}
	return (0);
}
