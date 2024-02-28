/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:14:32 by fcorri            #+#    #+#             */
/*   Updated: 2023/10/30 18:53:35 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_p.h"

static void	ft_log(t_node *memory, t_queue *p_queue, t_cs alive, t_cs queue)
{
	t_node	n;

	pthread_mutex_lock(queue.mutex);
	n = memory[p_queue->read];
	pthread_mutex_lock(alive.mutex);
	if (*alive.value)
		printf("%ld %d %s\n", n.timestamp, n.id_philo, n.message);
	pthread_mutex_unlock(alive.mutex);
	p_queue->read = (p_queue->read + 1) & LEN_1;
	p_queue->counter--;
	pthread_mutex_unlock(queue.mutex);
}

void	*ft_logging(void *p_table)
{
	t_table	*table;
	t_queue	*queue;
	t_node	*memory;
	t_cs	alive;
	t_cs	counter;

	table = p_table;
	queue = table->queue;
	memory = queue->memory;
	alive = (t_cs){&table->mutex, &table->are_alive};
	counter = (t_cs){&queue->mutex, &queue->counter};
	while ((!pthread_mutex_lock(alive.mutex)) & *alive.value \
		& !pthread_mutex_unlock(alive.mutex))
	{
		if ((!pthread_mutex_lock(counter.mutex)) & (*counter.value != 0) \
			& !pthread_mutex_unlock(counter.mutex))
			ft_log(memory, queue, alive, counter);
		else
			usleep(1000);
	}
	return (NULL);
}
