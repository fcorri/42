/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:50:53 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/28 19:00:32 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

t_stack	*ft_new_stack(void)
{
	t_stack	*output;

	output = malloc(sizeof(t_stack));
	if (!output)
		return (NULL);
	output->head = NULL;
	output->n = 0;
	return (output);
}

int	ft_is_ordered(t_stack *stack)
{
	t_int_dlist	*node;
	t_int_dlist	*next;
	int			n;

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

void	ft_push(t_stack *stack, t_int_dlist *node)
{
	t_int_dlist	*head;

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

t_int_dlist	*ft_pop(t_stack *stack)
{
	t_int_dlist	*output;

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

int	ft_find_index_min(t_stack *stack)
{
	int			min;
	int			output;
	t_bvector	n_i;
	t_int_dlist	*node;
	int			content;

	min = INT_MAX;
	output = 0;
	n_i = (t_bvector){stack->n, 0};
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
