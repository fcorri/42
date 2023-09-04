/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:01:44 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/04 13:19:00 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_remove_initial_spaces(const char **str)
{
	char	c;

	c = **str;
	while (c == ' '
		|| c == '\f'
		|| c == '\n'
		|| c == '\r'
		|| c == '\t'
		|| c == '\v')
	{
		*str += 1;
		c = **str;
	}
}

static int	ft_is_sign(const char **ptr)
{
	char	c;

	c = **ptr;
	if (c != '-' && c != '+')
		return (1);
	*ptr += 1;
	if (c == '-')
		return (-1);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	long	output;
	long	temp;
	int		sign;

	output = 0;
	ft_remove_initial_spaces(&nptr);
	sign = ft_is_sign(&nptr);
	while (ft_isdigit(*nptr))
	{
		temp = output * 10 + (*nptr - '0');
		if (temp < output)
		{
			if (sign > 0)
				return (-1);
			else
				return (0);
		}
		else
			output = temp;
		nptr++;
	}
	output *= sign;
	return (output);
}
