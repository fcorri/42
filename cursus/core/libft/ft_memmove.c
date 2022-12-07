/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:21:17 by fcorri            #+#    #+#             */
/*   Updated: 2022/11/21 15:44:33 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_set_word(size_t dest, size_t src)
{
	int	right;
	int	left;

	right = dest % sizeof(unsigned long);
	if (right == 0)
		*(unsigned long *)dest = *(unsigned long *)src;
	else
	{
		left = (sizeof(unsigned long) - right);
		*(unsigned long *)(dest + left) = (*(unsigned long *)(dest + left)
				>> right * 8) << right * 8
			| *(unsigned long *)src >> left * 8;
		*(unsigned long *)(dest - right) = (*(unsigned long *)(dest - right)
				<< left * 8) >> left * 8
			| *(unsigned long*)src << right * 8;
	}
}

static size_t	ft_set_words(size_t *p_dest, size_t *p_src, size_t n)
{
	size_t	dest;
	size_t	src;
	size_t	quozient;
	size_t	size;

	dest = *p_dest;
	src = *p_src;
	size = sizeof(unsigned long);
	quozient = n / size;
	if (!quozient)
		return (n);
	n -= quozient * size;
	while (quozient--)
	{
		dest -= size;
		src -= size;
		ft_set_word(dest, src);
	}
	*p_dest = dest - 1;
	*p_src = src - 1;
	return (n);
}

void	*ft_memmove(void *p_dest, const void *p_src, size_t n)
{
	size_t	dest;
	size_t	src;
	size_t	remainder;

	if (!n || p_dest == p_src)
		return (p_dest);
	if (p_src > p_dest)
		return (ft_memcpy(p_dest, p_src, n));
	dest = (size_t) p_dest + n - 1;
	src = (size_t) p_src + n - 1;
	if (n >= 4 * sizeof(unsigned long))
	{
		remainder = src % sizeof(unsigned long);
		n -= remainder + 1;
		while (remainder--)
			*((unsigned char *) dest--) = *((unsigned char *) src--);
		*((unsigned char *) dest) = *((unsigned char *) src);
		n = ft_set_words(&dest, &src, n);
	}
	while (n--)
		*((unsigned char *) dest--) = *((unsigned char *) src--);
	return (p_dest);
}
