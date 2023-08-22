/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:54:43 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/19 00:23:27 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static void	ft_reverse(t_stack *stack)
{
	if (stack->n < 2)
		return ;
	stack->head = stack->head->prev;
}

void	ft_rra(t_vars *vars)
{
	ft_reverse(vars->a);
}

void	ft_rrb(t_vars *vars)
{
	ft_reverse(vars->b);
}

void	ft_rrr(t_vars *vars)
{
	ft_reverse(vars->a);
	ft_reverse(vars->b);
}
