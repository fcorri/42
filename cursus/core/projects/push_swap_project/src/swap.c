/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:57:09 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/27 17:35:35 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static int	ft_swap(STACK *stack)
{
	NODE	*head;
	NODE	*next;
	int		tmp;

	if (stack->n < 2)
		return (0);
	head = stack->head;
	next = head->next;
	tmp = head->content;
	head->content = next->content;
	next->content = tmp;
	return (1);
}

void	ft_sa(VARS *vars, int print)
{
	if (ft_swap(vars->a) && print)
		ft_printf("sa\n");
}

void	ft_sb(VARS *vars, int print)
{
	if (ft_swap(vars->b) && print)
		ft_printf("sb\n");
}

void	ft_ss(VARS *vars)
{
	ft_sa(vars, 0);
	ft_sb(vars, 0);
	ft_printf("ss\n");
}
