/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:30:44 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/30 13:59:10 by fcorri           ###   ########.fr       */
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

char	*ft_ra(VARS *vars)
{
	if (ft_rotate(vars->a, &vars->callables, 6, 0b1101))
		return ("ra");
	return (NULL);
}

char	*ft_rb(VARS *vars)
{
	if (ft_rotate(vars->b, &vars->callables, 7, 0b1110))
		return ("rb");
	return (NULL);
}

char	*ft_rr(VARS *vars)
{
	if (ft_ra(vars) && ft_rb(vars))
		return ("rr");
	// potrebbe essere stata fatta solo una delle due
	return (NULL);
}
