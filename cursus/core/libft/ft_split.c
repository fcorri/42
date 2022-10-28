/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:29:04 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/24 19:22:13 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_others_in(const char *s, char input)
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

static char	**ft_init_output(const char *s, char input)
{
	char	**output;

	if (!s || ft_others_in(s, input) || (s && input))
	{
		output = malloc(sizeof(char *));
		output[0] = NULL;
	}
	else
	{
		output = malloc(sizeof(char *) * 2);
		output[0] = ft_strdup(s);
		output[1] = NULL;
	}
	return (output);
}

static size_t	ft_calculate_len(const char *s, size_t index, char input)
{
	size_t	len;
	char	c;

	len = 0;
	c = s[index];
	while (c && c != input)
	{
		len++;
		c = s[++index];
	}
	return (len);
}

static char	**ft_arrcat(char **arr, char *str)
{
	size_t	index;
	char	**output;

	index = 0;
	while (arr[index])
		index++;
	output = malloc(sizeof(char *) * (index + 2));
	index = 0;
	while (arr[index])
	{
		output[index] = arr[index];
		index++;
	}
	free(arr);
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
	if (s && output[0] == NULL)
	{
		while (s[index])
		{
			len = ft_calculate_len(s, index, c);
			if (len)
			{
				str = malloc(len + 1);
				ft_strlcpy(str, s + index, len + 1);
				output = ft_arrcat(output, str);
				index += len;
			}
			else
				index++;
		}
	}
	return (output);
}
