/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:54:43 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/27 17:33:17 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static int	ft_reverse(t_stack *stack)
{
	if (stack->n > 1)
		stack->head = stack->head->prev;
	return (1);
}

void	ft_rra(t_vars *vars, int print)
{
	if (ft_reverse(vars->a) && print)
		ft_printf("rra\n");
}

void	ft_rrb(t_vars *vars, int print)
{
	if (ft_reverse(vars->b) && print)
		ft_printf("rrb\n");
}

void	ft_rrr(t_vars *vars)
{
	ft_rra(vars, 0);
	ft_rrb(vars, 0);
	ft_printf("rrr\n");
}
