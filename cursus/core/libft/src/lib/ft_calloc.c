/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:32:46 by fcorri            #+#    #+#             */
/*   Updated: 2023/03/12 19:50:49 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	buffer_len;
	char	*output;

	buffer_len = nmemb * size;
	if (buffer_len < nmemb || buffer_len < size)
		buffer_len = 0;
	output = ft_malloc_soul(buffer_len);
	if (!output)
		return (NULL);
	ft_memset(output, 0, buffer_len);
	return (output);
}
