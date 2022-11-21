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
	size_t	quozient;

	if (p_dest == p_src)
		return (p_dest);
	dest = (size_t) p_dest;
	src = (size_t) p_src;
	if (n >= sizeof(unsigned long))
	{
		quozient = n / sizeof(unsigned long);
		n -= quozient * sizeof(unsigned long);
		while (quozient--)
		{
			*((unsigned long *) dest) = *((unsigned long *) src);
			dest += sizeof(unsigned long);
			src += sizeof(unsigned long);
		}
	}
	while (n--)
		*((unsigned char *) dest++) = *((unsigned char *) src++);
	return (p_dest);
}
