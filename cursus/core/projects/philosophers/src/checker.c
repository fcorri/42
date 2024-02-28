/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:51:13 by fcorri            #+#    #+#             */
/*   Updated: 2023/10/31 20:33:56 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_p.h"

static int	ft_alive(t_philo *philo, t_cs alive, t_times times, int n)
{
	t_table	*table;
	int		fm;
	int		id;

	table = philo->table;
	fm = table->finite_meals;
	id = 0;
	while (id++ < n)
	{
		times.ct = ft_time() - times.sd;
		if (!pthread_mutex_lock(&philo->mutex) && ((fm && philo->meals > 0) \
			|| !fm) && (times.ttd + 9 < times.ct - philo->last_meal))
		{
			pthread_mutex_lock(alive.mutex);
			printf("%ld %d %s\n", times.ct, id, "died");
			*alive.value = 0;
			pthread_mutex_unlock(alive.mutex);
			return (!pthread_mutex_unlock(&philo->mutex));
		}
		pthread_mutex_unlock(&philo->mutex);
		philo++;
	}
	return (1);
}

void	*ft_checking(void *philos)
{
	t_table	*table;
	t_times	times;
	t_cs	alive;
	int		n;

	table = ((t_philo *)philos)->table;
	times = (t_times){table->start_dinner, 0, table->time_to_die, 0};
	alive = (t_cs){&table->mutex, &table->are_alive};
	n = table->number_of_philos;
	while (ft_lock_and_get(alive.mutex, alive.value) \
		&& ft_alive(philos, alive, times, n))
		(void) NULL;
	return (NULL);
}
