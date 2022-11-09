/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:21:35 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/22 16:47:10 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	input;
	char	read;

	input = c;
	read = *s;
	while (read && read != input)
		read = *++s;
	if (read == input)
		return ((char *) s);
	return (NULL);
}
