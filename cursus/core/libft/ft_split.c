/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:02:09 by fcorri            #+#    #+#             */
/*   Updated: 2022/11/12 18:18:52 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_init_words(char const *s, char c)
{
	size_t	output;
	size_t	index;

	if (!s)
		return (0);
	output = 0;
	index = 0;
	if (s[index] && s[index] != c)
		output++;
	while (s[index] && s[index + 1])
	{
		if (s[index] == c && s[index + 1] != c)
			output++;
		index++;
	}
	return (output);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**output;
	size_t	index;
	size_t	len;

	words = ft_init_words(s, c);
	output = malloc(sizeof(char *) * (words + 1));
	if (!output)
		return (NULL);
	output[words] = NULL;
	index = 0;
	while (words)
	{
		len = 0;
		while (*s == c)
			s++;
		while (*s && *s != c)
		{
			len++;
			s++;
		}
		output[index++] = ft_substr(s - len, 0, len);
		words--;
	}
	return (output);
}
