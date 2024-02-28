/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:59:52 by filippo           #+#    #+#             */
/*   Updated: 2023/10/31 18:35:28 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_p.h"

void	ft_lock_and_set(pthread_mutex_t *mutex, int *value, int set)
{
	pthread_mutex_lock(mutex);
	*value = set;
	pthread_mutex_unlock(mutex);
}

void	ft_lock_and_set_time_t(pthread_mutex_t *mutex, time_t *value, \
	time_t set)
{
	pthread_mutex_lock(mutex);
	*value = set;
	pthread_mutex_unlock(mutex);
}

int	ft_lock_and_get(pthread_mutex_t *mutex, int *value)
{
	int	output;

	pthread_mutex_lock(mutex);
	output = *value;
	pthread_mutex_unlock(mutex);
	return (output);
}

int	ft_lock_get_and_decrease(pthread_mutex_t *mutex, int *value)
{
	int	output;

	pthread_mutex_lock(mutex);
	output = (*value)--;
	pthread_mutex_unlock(mutex);
	return (output);
}
