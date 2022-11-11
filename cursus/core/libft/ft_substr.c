/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:22:50 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/22 17:18:54 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t first, size_t second)
{
	if (first < second)
		return (first);
	return (second);
}

static size_t	ft_init_buffer(const char *str, unsigned int start, size_t len)
{
	size_t	buffer;

	buffer = ft_strlen(str) + 1;
	if (start >= buffer)
		return (1);
	return (ft_min(len, buffer - start));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;
	size_t	buffer;

	buffer = ft_init_buffer(s, start, len + 1);
	output = ft_calloc(buffer, 1);
	if (!output)
		return (NULL);
	if (buffer != 1)
		ft_strlcpy(output, s + start, len + 1);
	return (output);
}
