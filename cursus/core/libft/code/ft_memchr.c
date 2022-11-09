/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:20:52 by fcorri            #+#    #+#             */
/*   Updated: 2022/11/09 17:17:40 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p_s;
	unsigned char		input;
	size_t				index;

	if (n != 0)
	{
		p_s = s;
		input = c;
		index = 0;
		while (n && p_s[index] != input)
		{
			index++;
			n--;
		}
		if (n == 0)
			return (NULL);
		return ((void *)(p_s + index));
	}
	return (NULL);
}
