/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:17:53 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/31 17:47:33 by fcorri           ###   ########.fr       */
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
	int	n;

	n = ++queue->n;
	if (n == 0)
	{
		queue->head = node;
		queue->tail = node;
	}
	else
		ft_int_dlst_add_back(&stack->tail, node);
}

NODE	*ft_dequeue(QUEUE *queue)
{
	int		n;
	NODE	*node;
	NODE	*head;

	n = --queue->n;
	if (n == 0)
		return (NULL);
	head = queue->head
	node = head;
	if (n == 1)
	{
		queue->head = NULL;
		queue->tail = NULL;
		return (node);
	}
	node->prev->next = node->next;
	node->next->prev = node->prev;	
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_remove(QUEUE *queue)
{
	int		n;
	NODE	*head;

	n = --stack->n;
	head = queue->head;
	if (n == 0)
		return ;
	else if (n == 1)
	{
		queue->head = NULL;
		queue->tail = NULL;
		ft_
		return ;
	}
}
