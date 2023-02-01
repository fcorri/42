/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:32:08 by fcorri            #+#    #+#             */
/*   Updated: 2023/01/18 19:10:54 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t len)
{
	size_t	output;
	size_t	buffer_len;

	buffer_len = nmemb * len;
	if (buffer_len && (buffer_len < nmemb || buffer_len < len))
		buffer_len = -1;
	output = (size_t) malloc(buffer_len);
	if (!output)
		return (NULL);
	if (!buffer_len)
		return ((void *)output);
	output += (buffer_len - 1);
	buffer_len -= (output % sizeof(unsigned long) + 1);
	while (output % sizeof(unsigned long))
		*(char *)output-- = 0;
	*(char *)output = 0;
	while (buffer_len >= sizeof(unsigned long))
	{
		output -= sizeof(unsigned long);
		*(unsigned long *)output = 0;
		buffer_len -= sizeof(unsigned long);
	}
	while (buffer_len--)
		*(char *)output-- = 0;
	return ((void *)output);
}
