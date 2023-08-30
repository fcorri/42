/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:54:43 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/30 13:56:34 by fcorri           ###   ########.fr       */
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

char	*ft_rra(t_vars *vars)
{
	if (ft_reverse(vars->a, &vars->callables, 4, 0b1101))
		return ("rra");
	return (NULL);
}

char	*ft_rrb(t_vars *vars)
{
	if (ft_reverse(vars->b, &vars->callables, 5, 0b1110))
		return ("rrb");
	return (NULL);
}

char	*ft_rrr(t_vars *vars)
{
	ft_rra(vars);
	ft_rrb(vars);
	return ("rrr");
}
