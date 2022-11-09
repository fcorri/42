/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:32:46 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/20 19:37:59 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check_overflow(size_t nmemb, size_t size)
{
	size_t	mul;

	mul = nmemb * size;
	if (mul < nmemb)
		return (0);
	return (mul);
}

static void	*ft_error(void)
{
	errno = ENOMEM;
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	buffer_len;
	char	*output;

	buffer_len = ft_check_overflow(nmemb, size);
	if (!buffer_len)
		return (ft_error());
	output = malloc(buffer_len);
	ft_bzero(output, buffer_len);
	return (output);
}
