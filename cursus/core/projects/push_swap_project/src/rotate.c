/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:30:44 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/11 13:54:29 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static int	ft_rotate(STACK *stack)
{
	if (stack->n > 1)
		stack->head = stack->head->next;
	return (1);
}

void	ft_ra(VARS *vars)
{
	if (ft_rotate(vars->a))
		ft_enqueue(vars->output, ft_int_dlst_new(4));
}

void	ft_rb(VARS *vars)
{
	if (ft_rotate(vars->b))
		ft_enqueue(vars->output, ft_int_dlst_new(5));
}

void	ft_rr(VARS *vars)
{
	ft_ra(vars);
	ft_rb(vars);
}
