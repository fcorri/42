/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:17:37 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/18 16:21:11 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

int	*ft_prev(t_stack *stack)
{
	int	n;
	int	*head;

	n = stack->n;
	head = stack->head;
	if (head == stack->this)
		return (head + n - 1);
	return (head - 1);
}

int	*ft_next(t_stack *stack)
{
	int	*head;
	int	*this;

	head = stack->head;
	this = stack->this;
	if (head == this + stack->max - 1)
		return (this);
	return (head + 1);
}
