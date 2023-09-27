/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:26:08 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/27 17:29:37 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static void	ft_free_stack(STACK *stack)
{
	NODE	*head;
	NODE	*tmp;
	int		n;

	head = stack->head;
	n = stack->n;
	while (n--)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int	ft_free_and_return(t_vars *vars, int output)
{
	STACK	*stack;

	stack = vars->a;
	if (stack)
		ft_free_stack(stack);
	free(stack);
	stack = vars->b;
	if (stack)
		ft_free_stack(stack);
	free(stack);
	if (output)
		ft_exit();
	return (output);
}
