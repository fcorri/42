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

void	*ft_memcpy(void *p_dest, const void *p_src, size_t n)
{
	size_t	dest;
	size_t	src;
	size_t	remainder;
	size_t	size;

	if (!n || p_dest == p_src)
		return (p_dest);
	dest = (size_t) p_dest;
	src = (size_t) p_src;
	size = sizeof(unsigned long);
	if (n >= 4 * size)
	{
		remainder = dest % size;
		n -= (size - remainder);
		while (size - remainder++)
			*((unsigned char *) dest++) = *((unsigned char *) src++);
		n = ft_cpy_words(&dest, &src, n);
	}
	while (n--)
		*((unsigned char *) dest++) = *((unsigned char *) src++);
	return (p_dest);
}
