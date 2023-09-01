/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:54:43 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/01 18:03:10 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static int	ft_reverse(t_stack *stack, int *callables, int pos, int restore)
{
	if (stack->n < 2)
	{
		if (pos == 4)
			*callables &= ~(0b1 << 6);
		else
			*callables &= ~(0b1 << 7);
		return (0);
	}
	stack->head = stack->head->prev;
	*callables &= ~(0b1 << pos);
	*callables |= restore;
	return (1);
}

int	ft_rra(t_vars *vars, int inv)
{
	int output;

	output = ft_reverse(vars->a, &vars->callables, 4, 0b1101);
	if (inv)
		ft_remove(vars->output);
	else if (output)
		ft_enqueue(vars->output, ft_int_dlst_new(6));
	return (inv || output);
}

int	ft_rrb(t_vars *vars, int inv)
{
	int output;

	output = ft_reverse(vars->b, &vars->callables, 5, 0b1110);
	if (inv)
		ft_remove(vars->output);
	else if (output)
		ft_enqueue(vars->output, ft_int_dlst_new(7));
	return (inv || output);
}

int	ft_rrr(t_vars *vars, int inv)
{
	int	output;

	output = ft_rra(vars, inv);
	output = output || ft_rrb(vars, inv);
	return (inv || output);
}
