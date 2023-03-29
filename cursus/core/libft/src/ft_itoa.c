/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:06:20 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/31 15:32:56 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static long	ft_mod(int n)
{
	long	output;

	output = n;
	if (n < 0)
		return (output * -1);
	return (output);
}

static size_t	ft_digits(int n)
{
	size_t	digits;
	long	copia_n;

	if (n == 0)
		return (1);
	digits = 0;
	if (n < 0)
		digits++;
	copia_n = ft_mod(n);
	while (copia_n)
	{
		digits++;
		copia_n /= 10;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	size_t	digits;
	char	*output;
	long	c_n;

	digits = ft_digits(n);
	output = malloc(sizeof(char) * (digits + 1));
	if (!output)
		return (NULL);
	output[digits--] = '\0';
	c_n = ft_mod(n);
	while (digits + 1)
	{
		output[digits--] = (c_n % 10) + '0';
		c_n /= 10;
	}
	if (n < 0)
		output[0] = '-';
	return (output);
}
