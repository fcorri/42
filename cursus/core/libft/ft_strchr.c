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

static void	ft_init(unsigned long *input, char c, unsigned long *one)
{
	unsigned long	word;
	size_t			size;

	size = sizeof(unsigned long);
	word = c | (c << 8);
	word |= (word << 16);
	if (size > 4)
		word |= ((word << 16) << 16);
	*input = word;
	word = 0x01010101L;
	if (size > 4)
		word |= ((word << 16) << 16);
	*one = word;
}

static void	ft_checkword(char *src, unsigned long input, unsigned long one,
	char **output)
{
	unsigned long	word;

	word = (*(unsigned long *)src) ^ input;
	word = ((word - one) & ~word) & (one << 7);
	if (word != 0)
	{
		*output = src;
		while (**output != (char) input)
			(*output)++;
	}
}

static char	*ft_check_words(char *src, char c)
{
	unsigned long	word;
	unsigned long	input;
	unsigned long	one;
	char			*output;
	char			*zero;

	ft_init(&input, c, &one);
	output = NULL;
	zero = NULL;
	while (1)
	{
		ft_checkword(src, input, one, &output);
		ft_checkword(src, '\0', one, &zero);
		if (output && (output <= zero || !zero))
			return (output);
		else if (zero)
			return (NULL);
		src += sizeof(word);
	}
}

char	*ft_strchr(const char *src, int c)
{
	char	word;
	size_t	size;

	size = sizeof(unsigned long);
	while ((size_t) src % size)
	{
		word = *src++;
		if (word == (char) c)
			return ((char *)(src - 1));
		if (word == '\0')
			return (NULL);
	}
	return (ft_check_words((char *)src, c));
}
