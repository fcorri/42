/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:16:06 by fcorri            #+#    #+#             */
/*   Updated: 2023/10/31 20:34:34 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_p.h"

int	ft_take_sx_dx(t_philo *philo, t_dvector i_n, t_times times)
{
	pthread_mutex_t	*forks;

	forks = philo->table->forks;
	pthread_mutex_lock(forks + i_n.y - 1);
	if (!ft_enqueue(philo, (t_node){i_n.x, F, ft_time() - times.sd}, times.ttd))
	{
		pthread_mutex_unlock(forks + i_n.y - 1);
		return (0);
	}
	pthread_mutex_lock(forks);
	if (!ft_enqueue(philo, (t_node){i_n.x, F, ft_time() - times.sd}, times.ttd))
	{
		pthread_mutex_unlock(forks + i_n.y - 1);
		pthread_mutex_unlock(forks);
		return (0);
	}
	return (1);
}

int	ft_take_dx_sx(t_philo *philo, t_dvector i_n, t_times times)
{
	pthread_mutex_t	*forks;

	forks = philo->table->forks;
	pthread_mutex_lock(forks + i_n.x - 1);
	if (!ft_enqueue(philo, (t_node){i_n.x, F, ft_time() - times.sd}, times.ttd))
	{
		pthread_mutex_unlock(forks + i_n.x - 1);
		return (0);
	}
	pthread_mutex_lock(forks + i_n.x - 2);
	if (!ft_enqueue(philo, (t_node){i_n.x, F, ft_time() - times.sd}, times.ttd))
	{
		pthread_mutex_unlock(forks + i_n.x - 1);
		pthread_mutex_unlock(forks + i_n.x - 2);
		return (0);
	}
	return (1);
}

void	ft_leave_forks(t_philo *philo, t_dvector i_n)
{
	pthread_mutex_t	*forks;

	forks = philo->table->forks;
	if (i_n.x == 1)
	{
		pthread_mutex_unlock(forks);
		pthread_mutex_unlock(forks + i_n.y - 1);
	}
	else
	{
		pthread_mutex_unlock(forks + (i_n.x - 1));
		pthread_mutex_unlock(forks + i_n.x - 2);
	}
}
