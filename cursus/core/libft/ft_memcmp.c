/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:21:08 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/20 16:42:44 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p_s1;
	const unsigned char	*p_s2;
	size_t				index;

	if (n == 0)
		return (0);
	p_s1 = s1;
	p_s2 = s2;
	index = 0;
	while (n-- && p_s1[index] == p_s2[index])
		index++;
	if (n + 1 == 0)
		index--;
	return (p_s1[index] - p_s2[index]);
}
