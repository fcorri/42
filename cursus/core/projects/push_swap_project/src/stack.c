/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:50:53 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/11 17:52:41 by fcorri           ###   ########.fr       */
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

int	ft_is_empty(STACK *stack)
{
	return (stack->n == 0);
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
