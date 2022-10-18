/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:01:44 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/18 18:57:25 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	char	input;

	input = (char) c;
	return (input == ' '
		|| input == '\f'
		|| input == '\n'
		|| input == '\r'
		|| input == '\t'
		|| input == '\v');
}

int	ft_atoi(const char *nptr)
{
	long	output;
	char	sign;
	char	*c_nptr;

	output = 0;
	sign = 1;
	c_nptr = (char *) nptr;
	while (ft_isspace(*c_nptr))
		c_nptr++;
	if (*c_nptr == '-')
	{
		c_nptr++;
		sign = -1;
	}
	else if (*c_nptr == '+')
		c_nptr++;
	while (ft_isdigit(*c_nptr))
		output = output * 10 + (*c_nptr++ - '0');
	output *= sign;
	return (output);
}
