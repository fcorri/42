/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:57:09 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/31 14:06:41 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static int	ft_swap(STACK *stack, int *callables, int pos, int restore)
{
	NODE	*head;
	NODE	*next;
	int		tmp;

	*callables &= ~(0b1 << pos);
	if (stack->n < 2)
		return (0);
	head = stack->head;
	next = head->next;
	tmp = head->content;
	head->content = next->content;
	next->content = tmp;
	*callables |= restore;
	return (1);
}

int	ft_sa(VARS *vars)
{
	if (ft_swap(vars->a, &vars->callables, 0, 0b1011100))
	{
		ft_push(vars->output, ft_int_dlst_new(1));
		return (1);
	}
	return (0);
}

int	ft_sb(VARS *vars)
{
	if (ft_swap(vars->b, &vars->callables, 1, 0b10101100))
	{
		ft_push(vars->output, ft_int_dlst_new(2));
		return (1);
	}
	return (0);
}

int	ft_ss(VARS *vars)
{
	ft_sa(vars);
	ft_sb(vars);
	return (1);
}
