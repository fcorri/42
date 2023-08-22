/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:50:53 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/22 21:24:01 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

t_stack	*ft_new_stack_with_head(NODE *head, int n)
{
	t_stack	*output;

	output = malloc(sizeof(t_stack));
	if (!output)
		return (NULL);
	output->head = head;
	output->n = n;
	return (output);
}

t_stack	*ft_new_stack(void)
{
	return (ft_new_stack_with_head(NULL, 0));
}


int	ft_is_empty(t_stack *stack)
{
	return (stack->head == NULL);
}

NODE	*ft_pop(t_stack *stack)
{
	NODE	*output;

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

void	ft_push(t_stack *stack, NODE *node)
{
	t_int_dlist	*head;

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
