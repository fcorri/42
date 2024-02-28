/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:22:00 by fcorri            #+#    #+#             */
/*   Updated: 2023/10/31 20:27:18 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_p.h"

static t_queue	*ft_init_vars(t_philo *philo, t_cs *queue, \
	pthread_mutex_t **lm, int **write)
{
	t_queue					*p_queue;

	p_queue = philo->table->queue;
	*queue = (t_cs){&p_queue->mutex, &p_queue->counter};
	*lm = &philo->mutex;
	*write = &p_queue->write;
	return (p_queue);
}

int	ft_enqueue(t_philo *p, t_node node, time_t ttd)
{
	t_queue			*p_queue;
	t_cs			queue;
	pthread_mutex_t	*lm;
	int				*write;
	int				output;

	p_queue = ft_init_vars(p, &queue, &lm, &write);
	while ((!pthread_mutex_lock(queue.mutex)) & (*queue.value == LEN))
	{
		pthread_mutex_unlock(queue.mutex);
		usleep(1000);
	}
	if (!pthread_mutex_lock(lm) & (ttd + 1 >= node.timestamp - p->last_meal))
	{
		(p_queue->memory)[*write] = node;
		*write = (*write + 1) & LEN_1;
		*queue.value += 1;
		output = 1;
	}
	else
		output = 0;
	pthread_mutex_unlock(lm);
	pthread_mutex_unlock(queue.mutex);
	return (output);
}
