/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:03:47 by filippo           #+#    #+#             */
/*   Updated: 2023/10/29 20:16:15 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_p.h"

static void	ft_free_forks(t_table *table)
{
	pthread_mutex_t	*forks;
	int				number_of_philos;

	forks = table->forks;
	if (!forks)
		return ;
	number_of_philos = table->number_of_philos;
	while (number_of_philos--)
		pthread_mutex_destroy(forks + number_of_philos);
	free(forks);
}

static void	ft_free_queue(t_table *table)
{
	t_queue	*queue;

	queue = table->queue;
	if (!queue)
		return ;
	pthread_mutex_destroy(&queue->mutex);
	free(queue->memory);
	free(queue);
}

static void	ft_free_philos(t_philo *philos)
{
	int	number_of_philos;

	if (!philos)
		return ;
	number_of_philos = philos->table->number_of_philos;
	while (number_of_philos--)
		pthread_mutex_destroy(&(philos + number_of_philos)->mutex);
	free(philos);
}

int	ft_free_and_return(t_table *table, t_philo *philos, int output)
{
	ft_free_forks(table);
	pthread_mutex_destroy(&table->mutex);
	ft_free_queue(table);
	ft_free_philos(philos);
	return (output);
}
