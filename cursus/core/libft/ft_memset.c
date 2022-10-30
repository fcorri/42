/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:20:19 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/28 15:07:21 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	/*	This is the address used to store unsigned long words or bytes*/
	long			dest;
	/*	This should be, normally, the biggest type supported by a single load 
		and store */
	unsigned long	word;
	unsigned char	input;

	dest = (long) s;
	input = c;
	if (n >= 8)
	{
		/*	Build the word to save on memory */
		word = input;
		word = (word << 8) | word;
		word = (word << 16) | word;
		if (sizeof(word) > 4)
			word = (word << 32) | word;
		/*	Align dest in memory, copying input */
		while (dest % sizeof(word) != 0)
		{
			((unsigned char *) dest)[0] = input;
			dest++;
			n--;
		}
		/*	Copy 1 words per iteration until less than sizeof(word) bytes remain*/
		while (n / sizeof(word))
		{
			((unsigned long *) dest)[0] = word;
			dest += sizeof(word);
			n -= sizeof(word);
		}
	}
	/*	Copy 1 byte per iteration until none remains*/
	while (n--)
	{
		((unsigned char *) dest)[0] = input;
		dest++;
	}
	return (s);
}
