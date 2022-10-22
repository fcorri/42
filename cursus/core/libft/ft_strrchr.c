/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:22:12 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/22 16:47:47 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	input;
	size_t	index;
	int		found;

	input = c;
	index = 0;
	found = 0;
	while (s[index])
	{
		if (s[index] == input)
		{
			found = 1;
			s += index;
			index = 0;
		}
		index++;
	}
	if (found)
		return ((char *) s);
	else if (s[index] == input)
		return ((char *)(s + index));
	return (NULL);
}
