/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:29:04 by fcorri            #+#    #+#             */
/*   Updated: 2023/01/16 16:30:10 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static char	**ft_free_and_return(char **output, int null)
{
	size_t	index;
	char	**tmp;
	char	*str;

	if (null)
	{
		index = 2;
		str = output[index];
		while (str)
		{
			free(str);
			str = output[index];
		}
		free(output);
		return (NULL);
	}
	index = (size_t) output[1] + 1;
	tmp = output;
	output = malloc(sizeof(char *) * index);
	if (!output)
		return (ft_free_and_return(tmp, 1));
	while (index--)
		output[index] = tmp[2 + index];
	free(tmp);
	return (output);
}

static int	ft_init_arr(char ***output)
{
	*output = malloc(sizeof(char *) * 3);
	if (*output)
	{
		(*output)[0] = (char *) 1;
		(*output)[1] = 0;
		(*output)[2] = NULL;
		return (1);
	}
	return (0);
}

static int	ft_concat(char ***arr, char *next_str)
{
	char	**tmp;
	size_t	len;
	size_t	n;
	size_t	index;

	tmp = *arr;
	len = (size_t) tmp[0];
	n = (size_t) tmp[1];
	if (n + 1 > len - 1)
	{
		*arr = malloc(sizeof(char *) * (len * 2 + 2));
		if (!*arr)
			return (0);
		(*arr)[0] = (char *)(len * 2);
		index = 1;
		while (++index < n + 2)
			(*arr)[index] = tmp[index];
		(*arr)[n + 2] = next_str;
		(*arr)[len + 2] = NULL;
		free(tmp);
	}
	else
		(*arr)[n + 2] = next_str;
	(*arr)[1] = (char *) n + 1;
	return (1);
}

static char	*ft_len_and_str(char *input, char c, size_t *n)
{
	size_t	len;
	char	*output;

	output = input;
	len = (size_t) ft_strchr(input, c);
	if (len)
		len -= (size_t) input;
	else
		len = (size_t)(ft_strchr(input, '\0') - input);
	if (len)
		output = ft_substr(input, 0, len);
	*n = len;
	return (output);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	size_t	index;
	size_t	len;
	char	*str;

	if (!s)
		return (NULL);
	if (!ft_init_arr(&output))
		return (ft_free_and_return(output, 1));
	index = 0;
	while (s[index])
	{
		str = ft_len_and_str((char *) s + index, c, &len);
		if (!str || (len && !ft_concat(&output, str)))
			return (ft_free_and_return(output, 1));
		if (s[index + len])
			index += len + 1;
		else
			index += len;
	}
	return (ft_free_and_return(output, 0));
}
