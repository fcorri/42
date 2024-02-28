/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simposio.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:58:41 by fcorri            #+#    #+#             */
/*   Updated: 2023/10/31 19:40:36 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_p.h"

static t_times	ft_init_vars(t_philo *philo, t_tf *tf, \
	t_dvector *i_n, t_cs *alive)
{
	t_table	*table;
	int		id;
	int		number_of_philos;

	table = philo->table;
	*tf = (t_tf){table, table->forks};
	id = philo->id;
	number_of_philos = table->number_of_philos;
	*alive = (t_cs){&table->mutex, &table->are_alive};
	if (!(id % 2))
		usleep(1000);
	*i_n = (t_dvector){id, number_of_philos};
	return ((t_times){table->start_dinner, 0, table->time_to_die, 0});
}

static int	ft_take_forks_and_eat(t_philo *philo, t_table *table, \
	t_dvector i_n, t_times times)
{
	time_t	tmp;

	if (i_n.x == 1)
	{
		if (!ft_take_sx_dx(philo, i_n, times))
			return (0);
	}
	else if (!ft_take_dx_sx(philo, i_n, times))
		return (0);
	pthread_mutex_lock(&philo->mutex);
	tmp = philo->last_meal;
	times.lm = ft_time() - times.sd;
	philo->last_meal = times.lm;
	pthread_mutex_unlock(&philo->mutex);
	if (!ft_enqueue(philo, (t_node){i_n.x, E, times.lm}, times.ttd))
	{
		ft_leave_forks(philo, i_n);
		ft_lock_and_set_time_t(&philo->mutex, &philo->last_meal, tmp);
		return (0);
	}
	usleep(table->time_to_eat);
	return (1);
}

static int	ft_leave_forks_and_sleep(t_philo *philo, t_dvector i_n, \
	t_times times)
{
	ft_leave_forks(philo, i_n);
	if (!ft_enqueue(philo, (t_node){i_n.x, S, ft_time() - times.sd}, times.ttd))
		return (0);
	usleep(philo->table->time_to_sleep);
	return (1);
}

void	*ft_simposio(void *philo)
{
	t_tf		tf;
	t_dvector	i_n;
	t_cs		alive;
	t_cs		counter;
	t_times		times;

	times = ft_init_vars(philo, &tf, &i_n, &alive);
	counter = (t_cs){\
		&((t_philo *)philo)->mutex, &((t_philo *)philo)->meals};
	if (i_n.y == 1)
		usleep((tf.table->time_to_die + 10) << 10);
	else
	{
		while (!(tf.table->finite_meals \
			&& ft_lock_get_and_decrease(counter.mutex, counter.value) == 0) \
			&& ft_lock_and_get(alive.mutex, alive.value))
			if (!(ft_enqueue(philo, (t_node){i_n.x, "is thinking", \
				ft_time() - times.sd}, times.ttd) \
			&& ft_take_forks_and_eat(philo, tf.table, i_n, times) \
			&& ft_leave_forks_and_sleep(philo, i_n, times)))
				break ;
	}
	return (NULL);
}
