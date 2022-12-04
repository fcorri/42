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

static _Bool	ft_check_bytes(size_t *p_p1, size_t *p_p2, size_t *p_n,
					size_t *p_index)
{
	size_t	p1;
	size_t	p2;
	int		remainder;
	size_t	size;

	p1 = *p_p1;
	p2 = *p_p2;
	size = sizeof(unsigned long);
	remainder = p1 & (size - 1);
	if (!remainder)
		return (0);
	*p_n -= (size - remainder);
	while (size - remainder++)
	{
		if (*(unsigned char *)p1++ == *(unsigned char *)p2++)
			break ;
	}
	*p_index = --p1 - *p_p1;
	*p_p1 = p1;
	*p_p2 = --p2;
	if (remainder)
		return (1);
	return (0);
}

static unsigned long	ft_read_word(size_t src)
{
	int		right;
	int		left;
	size_t	size;

	size = sizeof(unsigned long);
	right = src % size;
	if (right == 0)
		return (*(unsigned long *)src);
	left = size - right;
	return (
		*(unsigned long *)(src - right) >> (right * 8)
		| *(unsigned long *)(src + left) << (left * 8)
	);
}

static _Bool	ft_check_words(size_t *p_p1, size_t *p_p2, size_t *p_n,
					size_t *output)
{
	size_t	p1;
	size_t	p2;
	int		temp;
	size_t	n;

	p1 = *p_p1;
	p2 = *p_p2;
	n = *p_n;
	temp = n / sizeof(unsigned long);
	while (temp--)
	{
		if (*(unsigned long *)p1 != ft_read_word(p2))
		{
			if (*(unsigned char *)p1 != *(unsigned char *)p2)
				return (p1);
			return (ft_check_bytes(p_p1, p_p2, n, output));
		}
		p1 += sizeof(unsigned long);
		p2 += sizeof(unsigned long);
		n -= sizeof(unsigned long);
	}
	*p_p1 = p1;
	*p_p2 = p2;
	*p_n = n;
	return (sizeof(unsigned long));
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	p1;
	size_t	p2;
	size_t	index;
	int		output;

	if (n == 0)
		return (0);
	p1 = (size_t) s1;
	p2 = (size_t) s2;
	if (n >= 4 * sizeof(unsigned long))
	{
		index = 0;
		if (ft_check_bytes(&p1, &p2, &n, &index))
			return (*(unsigned char *)(p1 + index)
				- *(unsigned char *)(p2 + index));
	}
	while (n--)
	{
		output = *(unsigned char *)p1++ - *(unsigned char *)p2++;
		if (output)
			return (output);
	}
	return (*(unsigned char *)p1 - *(unsigned char *)p2);
}
