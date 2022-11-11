/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:01:44 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/20 19:37:32 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' '
		|| c == '\f'
		|| c == '\n'
		|| c == '\r'
		|| c == '\t'
		|| c == '\v');
}

static int	ft_is_sign(const char *ptr, size_t *index)
{
	char	c;

	c = ptr[*index];
	if (c != '-' && c != '+')
		return (1);
	*index += 1;
	if (c == '-')
		return (-1);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	long	output;
	char	sign;
	size_t	index;

	output = 0;
	index = 0;
	while (ft_isspace(nptr[index]))
		index++;
	sign = ft_is_sign(nptr, &index);
	while (ft_isdigit(nptr[index]))
		output = output * 10 + (nptr[index++] - '0');
	output *= sign;
	return (output);
}
