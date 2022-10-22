/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:39:14 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/22 18:53:47 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_in(const char *set, char c)
{
	size_t	index;
	char	comp;

	index = 0;
	comp = set[index];
	while (comp)
	{
		if (comp == c)
			return (1);
		comp = set[++index];
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;

	start = 0;
	len = ft_strlen(s1);
	while (ft_find_in(set, s1[len - 1]))
		len--;
	while (ft_find_in(set, s1[start++]))
		len--;
	return (ft_substr(s1, start - 1, len));
}
