/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:29:04 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/23 01:33:26 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_init_output_null(void)
{
	char	**output;

	output = malloc(sizeof(char *));
	output[0] = NULL;
	return (output);
}

int		ft_other_in(const char *s, char input)
{
	size_t	index;
	char	c;

	index = 0;
	c = s[index];
	while (c != '\0')
	{
		if (c != input)
			return (1);
		c = s[++index];
	}
	return (0);
}

char	**ft_init_output(const char *s, char input)
{
	char	**output;

	if ((!s || !input) && !ft_other_in(s, input))
		return (ft_init_output_null());
	output = malloc(sizeof(char *) * 2);
	output[0] = ft_strdup(s);
	output[1] = NULL;
	return (output);
}

size_t	ft_calculate_len(const char *s, size_t index, char input)
{
	size_t	len;
	char	c;

	len = 0;
	c = s[index];
	while (c != input)
	{
		len++;
		c = s[++index];
	}
	return (len);
}

size_t	ft_arrcpy(char **dest, char **src)
{
	size_t	index;

	index = 0;
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	free(src);
	return (index);
}

char	**ft_arrcat(char **arr, char *str)
{
	size_t	index;
	char	**output;

	index = 0;
	while (arr[index])
		index++;
	output = malloc(sizeof(char *) * (index + 2));
	index = ft_arrcpy(output, arr);
	output[index] = str;
	output[index + 1] = NULL;
	return (output);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	char	*str;
	size_t	index;
	size_t	len;

	output = ft_init_output(s, c);
	index = 0;
	while (s[index])
	{
		len = ft_calculate_len(s, index, c);
		if (len)
		{
			str = malloc(len + 1);
			ft_strlcpy(str, s + index, len + 1);
			output = ft_arrcat(output, str);
		}
		index += len + 1;
	}
	return (output);
}
