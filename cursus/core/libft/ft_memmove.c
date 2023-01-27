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
		n = ft_move_words(&dest, &src, n);
	}
	while (n--)
		*((unsigned char *) dest--) = *((unsigned char *) src--);
	return (p_dest);
}
