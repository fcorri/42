/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:26:08 by fcorri            #+#    #+#             */
/*   Updated: 2023/10/06 19:20:08 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static void	ft_free_stack(t_stack *stack)
{
	t_int_dlist	*head;
	t_int_dlist	*tmp;
	int			n;

	head = stack->head;
	n = stack->n;
	while (n--)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int	ft_free_and_exit(t_vars *vars, int exit)
{
	t_stack	*stack;

	stack = vars->a;
	if (stack)
		ft_free_stack(stack);
	free(stack);
	stack = vars->b;
	if (stack)
		ft_free_stack(stack);
	free(stack);
	if (exit)
		ft_exit(1);
	return (0);
}
