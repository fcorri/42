/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:30:44 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/27 17:34:57 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static int	ft_rotate(STACK *stack)
{
	if (stack->n > 1)
		stack->head = stack->head->next;
	return (1);
}

void	ft_ra(VARS *vars, int print)
{
	if (ft_rotate(vars->a) && print)
		ft_printf("ra\n");
}

void	ft_rb(VARS *vars, int print)
{
	if (ft_rotate(vars->b) && print)
		ft_printf("rb\n");
}

void	ft_rr(VARS *vars)
{
	ft_ra(vars, 0);
	ft_rb(vars, 0);
	ft_printf("rr\n");
}
