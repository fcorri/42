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

static char	**ft_free_and_return_null(char **output)
{
	size_t	index;
	char	*tmp;

	index = 2;
	tmp = output[index];
	while (tmp)
	{
		free(tmp);
		tmp = output[index];
	}
	free(output);
	return (NULL);
}

static char	**ft_return(char **output)
{
	char	**tmp;
	size_t	n;

	n = (size_t) output[1] + 1;
	tmp = output;
	output = malloc(sizeof(char *) * n);
	while (n--)
		output[n] = tmp[2 + n];
	free(tmp);
	return (output);
}

static char	**ft_init_arr(void)
{
	char	**output;

	output = malloc(sizeof(char *) * 3);
	if (output)
	{
		output[0] = (char *) 1;
		output[1] = 0;
		output[2] = NULL;
	}
	return (output);
}

static void	ft_concat_arr(char ***output, char *next)
{
	char	**tmp;
	size_t	len;
	size_t	n;
	size_t	index;

	tmp = *output;
	len = (size_t) tmp[0];
	n = (size_t) tmp[1];
	if (n + 1 > len - 1)
	{
		*output = malloc(sizeof(char *) * (len * 2 + 2));
		if (!*output)
			return ;
		(*output)[0] = (char *)(len * 2);
		(*output)[n + 2] = next;
		index = 1;
		while (++index < n + 2)
			(*output)[index] = tmp[index];
		(*output)[len + 2] = NULL;
		free(tmp);
	}
	else
		(*output)[n + 2] = next;
	(*output)[1] = (char *) n + 1;
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	size_t	index;
	size_t	len;
	char	*str;

	if (!s)
		return (NULL);
	output = ft_init_arr();
	if (!output)
		return (ft_free_and_return_null(output));
	index = 0;
	while (s[index])
	{
		len = (size_t) ft_strchr(s + index, c);
		if (len)
			len -= ((size_t) s + index);
		else
			len = (size_t) ft_strchr(s + index, '\0');
		if (len)
		{
			str = malloc(sizeof(char) * (len + 1));
			ft_strlcpy(str, s + index, len + 1);
			ft_concat_arr(&output, str);
		}
		index += len + 1;
	}
	return (ft_return(output));
}
