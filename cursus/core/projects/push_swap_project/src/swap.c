/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:57:09 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/18 16:19:28 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static void	ft_swap(t_stack *stack)
{
	int	*head;
	int	tmp;
	int	*prev;

	if (stack->n < 2)
		return ;
	head = stack->head;
	tmp = *head;
	prev = ft_prev(stack);
	*head = *prev;
	*prev = tmp;
}

void	ft_sa(t_vars *vars)
{
	ft_swap(vars->a);
}

void	ft_sb(t_vars *vars)
{
	ft_swap(vars->b);
}

void	ft_ss(t_vars *vars)
{
	ft_sa(vars);
	ft_sb(vars);
}
