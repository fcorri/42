/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:30:44 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/19 00:23:04 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static void	ft_rotate(STACK *stack)
{
	if (stack->n < 2)
		return ;
	stack->head = stack->head->next;
}

void	ft_ra(VARS *vars)
{
	ft_rotate(vars->a);
}

void	ft_rb(VARS *vars)
{
	ft_rotate(vars->b);
}

void	ft_rr(VARS *vars)
{
	ft_rotate(vars->a);
	ft_rotate(vars->b);
}
