/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:21:17 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/20 16:01:16 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*p_dest;
	const char	*p_src;

	if (src != dest)
	{
		p_dest = dest;
		p_src = src;
		if (src < dest)
			while (n--)
				p_dest[n] = p_src[n];
		else
			ft_memcpy(dest, src, n);
	}
	return (dest);
}
