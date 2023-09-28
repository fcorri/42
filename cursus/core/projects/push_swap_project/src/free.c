/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:26:08 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/28 18:59:02 by fcorri           ###   ########.fr       */
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

int	ft_free_and_return(t_vars *vars, int output)
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
	if (output)
		ft_exit();
	return (output);
}
