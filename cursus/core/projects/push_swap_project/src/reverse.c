/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:54:43 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/31 14:06:17 by fcorri           ###   ########.fr       */
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

int	ft_rra(t_vars *vars)
{
	if (ft_reverse(vars->a, &vars->callables, 4, 0b1101))
	{
		ft_push(vars->output, ft_int_dlst_new(6));
		return (1);
	}
	return (0);
}

int	ft_rrb(t_vars *vars)
{
	if (ft_reverse(vars->b, &vars->callables, 5, 0b1110))
	{
		ft_push(vars->output, ft_int_dlst_new(7));
		return (1);
	}
	return (0);
}

int	ft_rrr(t_vars *vars)
{
	ft_rra(vars);
	ft_rrb(vars);
	return (1);
}
