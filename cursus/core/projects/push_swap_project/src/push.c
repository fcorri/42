/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:48:01 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/01 17:31:53 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static int	ft_push_op(STACK *src, STACK *dest, int *callables, int pos)
{
	if (!src->n)
	{
		if (pos == 3)
			*callables &= ~(0b1 << 2);
		else
			*callables &= ~(0b1 << 3);
		return (0);
	}
	ft_push(dest, ft_pop(src));
	*callables &= ~(0b1 << pos);
	*callables |= 0b11110011;
	return (1);
}

int	ft_pa(VARS *vars, int inv)
{
	int output;

	output = ft_push_op(vars->b, vars->a, &vars->callables, 3);
	if (inv)
		ft_remove(vars->output);
	else if (output)
		ft_enqueue(vars->output, ft_int_dlst_new(2));
	return (inv || output);
}

int	ft_pb(VARS *vars, int inv)
{
	int output;

	output = ft_push_op(vars->a, vars->b, &vars->callables, 2);
	if (inv)
		ft_remove(vars->output);
	else if (output)
		ft_enqueue(vars->output, ft_int_dlst_new(3));
	return (inv || output);
}
