/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:22:12 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/11 19:46:41 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p_s;
	char	input;

	p_s = (char *)s;
	input = c;
	while (*p_s++ != 0)
		;
	while (p_s != s && *--p_s != input)
		;
	if (*p_s == input)
		return (p_s);
	return (NULL);
}
