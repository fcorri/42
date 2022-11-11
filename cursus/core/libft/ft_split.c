/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:02:09 by fcorri            #+#    #+#             */
/*   Updated: 2022/11/11 19:38:38 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_init_words(char const *s, char c)
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
	char const	*str;
	size_t	len;

	words = ft_init_words(s, c);
	output = malloc(sizeof(char *) * (words + 1));
	if (!output)
		return (NULL);
	output[words] = NULL;
	index = 0;
	str = s;
	while (words--)
	{
		str = ft_strtrim(str, &c);
		if (words != 1)
			len = ft_strchr(str, c) - str;
		else
			len = ft_strlen(str);
		output[index++] = ft_substr(str, 0, len);
		str += len;
	}
	return (output);
}

void main()
{
	char *str0 = ft_strdup("");
	char *str1 = ft_strdup("ciao ");
	char *str2 = ft_strdup(" ");
	char *str3 = ft_strdup("ciao");
	char *str4 = ft_strdup("ciao come stai ? ");
	char *str5 = ft_strdup("ciao come stai ?");
	char *str6 = ft_strdup(" ciao come stai ? ");

	int i=1;
	while(i--)
	{
		ft_split(str0, ' ');
		ft_split(str1, ' ');
		ft_split(str2, ' ');
		ft_split(str3, ' ');
		ft_split(str4, ' ');
		ft_split(str5, ' ');
		ft_split(str6, ' ');
	}
}
