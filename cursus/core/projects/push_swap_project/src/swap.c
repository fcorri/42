/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:57:09 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/01 17:45:33 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static int	ft_swap(STACK *stack, int *callables, int pos, int restore)
{
	NODE	*head;
	NODE	*next;
	int		tmp;

	*callables &= ~(0b1 << pos);
	if (stack->n < 2)
		return (0);
	head = stack->head;
	next = head->next;
	tmp = head->content;
	head->content = next->content;
	next->content = tmp;
	*callables |= restore;
	return (1);
}

int	ft_sa(VARS *vars, int inv)
{
	int output;

	output = ft_swap(vars->a, &vars->callables, 0, 0b1011100);
	if (inv)
		ft_remove(vars->output);
	else if (output)
		ft_enqueue(vars->output, ft_int_dlst_new(0));
	return (inv || output);
}

int	ft_sb(VARS *vars, int inv)
{
	int output;

	output = ft_swap(vars->b, &vars->callables, 1, 0b10101100);
	if (inv)
		ft_remove(vars->output);
	else if (output)
		ft_enqueue(vars->output, ft_int_dlst_new(1));
	return (inv || output);
}

int	ft_ss(VARS *vars, int inv)
{
	int output;

	output = ft_sa(vars, inv);
	output = output || ft_sb(vars, inv);
	return (inv || output);
}
