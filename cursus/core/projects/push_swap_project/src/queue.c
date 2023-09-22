/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:17:53 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/22 17:34:06 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

QUEUE	*ft_new_queue(void)
{
	QUEUE	*output;

	output = malloc(sizeof(QUEUE));
	if (!output)
		return (NULL);
	output->head = NULL;
	output->tail = NULL;
	output->n = 0;
	return (output);
}

void	ft_enqueue(QUEUE *queue, NODE *node)
{
	if (queue->n++ == 0)
	{
		queue->head = node;
		queue->tail = node;
	}
	else
		ft_int_dlst_add_back(&queue->tail, node);
}

NODE	*ft_dequeue(QUEUE *queue)
{
	NODE	*node;
	NODE	*head;

	if (queue->n == 0)
		return (NULL);
	head = queue->head;
	node = head;
	if (queue->n-- == 1)
	{
		queue->head = NULL;
		queue->tail = NULL;
	}
	else
	{
		queue->head = node->next;
		node->next->prev = NULL;
	}
	return (node);
}

void	ft_remove(QUEUE *queue)
{
	NODE	*prev;
	NODE	*next;

	if (queue->n == 1)
	{
		ft_int_dlst_del_one(&queue->head);
		queue->tail = NULL;
	}
	else if (queue->n-- > 1)
	{
		prev = queue->tail->prev;
		next = queue->tail->next;
		if (prev)
			prev->next = next;
		if (next)
			next->prev = prev;
		ft_int_dlst_del_one(&queue->tail);
		queue->tail = prev;
	}
}
