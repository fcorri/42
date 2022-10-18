/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:25:41 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/18 18:51:53 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*output;
	size_t	buffer_len;

	buffer_len = ft_strlen(s) + 1;
	output = malloc(buffer_len);
	if (!output)
		return (NULL);
	ft_strlcpy(output, s, buffer_len);
	return (output);
}
