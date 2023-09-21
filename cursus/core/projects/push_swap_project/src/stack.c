/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:50:53 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/21 14:36:37 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

STACK	*ft_new_stack(void)
{
	STACK	*output;

	output = malloc(sizeof(STACK));
	if (!output)
		return (NULL);
	output->head = NULL;
	output->n = 0;
	return (output);
}

int	ft_is_ordered(STACK *stack)
{
	NODE	*node;
	NODE	*next;
	int		n;

	n = stack->n;
	if (n == 1)
		return (1);
	node = stack->head;
	next = node->next;
	while (--n)
	{
		if (node->content > next->content)
			return (0);
		node = next;
		next = node->next;
	}
	return (1);
}

void	ft_push(STACK *stack, NODE *node)
{
	NODE	*head;

	if (!node)
		return ;
	head = stack->head;
	if (stack->n++ == 1 && head)
	{
		node->prev = head;
		node->next = head;
		head->prev = node;
		head->next = node;
		stack->head = node;
	}
	else
		ft_int_dlst_add_front(&stack->head, node);
}

NODE	*ft_pop(STACK *stack)
{
	NODE	*output;

	if (!stack->n)
		return (NULL);
	stack->n--;
	output = stack->head;
	if (output->next)
		output->next->prev = output->prev;
	if (output->prev)
		output->prev->next = output->next;
	stack->head = output->next;
	output->next = NULL;
	output->prev = NULL;
	return (output);
}

int	ft_find_index_min(STACK *stack)
{
	int		min;
	int		output;
	VECTOR	n_i;
	NODE	*node;
	int		content;

	min = INT_MAX;
	output = 0;
	n_i = (VECTOR){stack->n, 0};
	node = stack->head;
	while (n_i.y++ < n_i.x)
	{
		content = node->content;
		if (content < min)
		{
			min = content;
			output = n_i.y - 1;
		}
		node = node->next;
	}
	if (output > n_i.x - output)
		output = output - n_i.x;
	return (output);
}
