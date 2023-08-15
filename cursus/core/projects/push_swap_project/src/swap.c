/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:57:09 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/15 16:26:31 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static void	ft_swap(t_stack *stack)
{
	int	*first;
	int	tmp;
	int	*next;

	if (stack->n < 2)
		return ;
	first = stack->this;
	tmp = *first;
	next = first + 1;
	*first = *next;
	*next = tmp;
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
