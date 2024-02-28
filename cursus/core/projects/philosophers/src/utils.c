/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:42:49 by fcorri            #+#    #+#             */
/*   Updated: 2023/10/30 18:22:15 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_p.h"

int	ft_error(char *string, size_t len)
{
	write(2, string, len);
	return (0);
}

int	ft_atoi(char *str)
{
	int		output;
	int		tmp;
	int		i;
	char	digit;

	i = 0;
	output = 0;
	digit = str[i++];
	if (digit == '-' || digit < '0' || '9' < digit)
		return (-1);
	while (digit && ('0' <= digit && digit <= '9'))
	{
		tmp = output * 10;
		if (tmp < output)
			return (-1);
		output = tmp + (digit - '0');
		if (output < tmp)
			return (-1);
		digit = str[i++];
	}
	if (digit != '\0' || output > 1000)
		return (-1);
	return (output);
}

time_t	ft_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
