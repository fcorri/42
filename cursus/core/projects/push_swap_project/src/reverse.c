/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:54:43 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/15 01:41:13 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static int	ft_reverse(t_stack *stack)
{
	if (stack->n > 1)
		stack->head = stack->head->prev;
	return (1);
}

void	ft_rra(t_vars *vars)
{
	if (ft_reverse(vars->a))
		ft_enqueue(vars->output, ft_int_dlst_new(6));
}

void	ft_rrb(t_vars *vars)
{
	if (ft_reverse(vars->b))
		ft_enqueue(vars->output, ft_int_dlst_new(7));
}

void	ft_rrr(t_vars *vars)
{
	ft_rra(vars);
	ft_rrb(vars);
}
