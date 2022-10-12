/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:21:17 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/12 19:05:52 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*p_src;
	char		*p_dest;

	if (src != dest)
	{
		p_src = src;
		p_dest = dest;
		if (src < dest)
			while (n--)
				p_dest[n] = p_src[n];
		else
			ft_memcpy(dest, src, n);
	}
	return (dest);
}
