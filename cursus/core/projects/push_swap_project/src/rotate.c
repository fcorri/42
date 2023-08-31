/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:30:44 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/31 14:06:57 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static int	ft_rotate(STACK *stack, int *callables, int pos, int restore)
{
	if (stack->n < 2)
	{
		if (pos == 6)
			*callables &= ~(0b1 << 4);
		else
			*callables &= ~(0b1 << 5);
		return (0);
	}
	stack->head = stack->head->next;
	*callables &= ~(0b1 << pos);
	*callables |= restore;
	return (1);
}

int	ft_ra(VARS *vars)
{
	if (ft_rotate(vars->a, &vars->callables, 6, 0b1101))
	{
		ft_push(vars->output, ft_int_dlst_new(4));
		return (1);
	}
	return (0);
}

int	ft_rb(VARS *vars)
{
	if (ft_rotate(vars->b, &vars->callables, 7, 0b1110))
	{
		ft_push(vars->output, ft_int_dlst_new(5));
		return (1);
	}
	return (0);
}

int	ft_rr(VARS *vars)
{
	ft_ra(vars);
	ft_rb(vars);
	return (1);
}
