/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:30:44 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/17 12:28:14 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static void	ft_rotate(t_stack *stack)
{
	if (stack->n < 2)
		return ;
	stack->head = ft_prev(stack);
}

void	ft_ra(t_vars *vars)
{
	ft_rotate(vars->a);
}

void	ft_rb(t_vars *vars)
{
	ft_rotate(vars->b);
}

void	ft_rr(t_vars *vars)
{
	ft_rotate(vars->a);
	ft_rotate(vars->b);
}
