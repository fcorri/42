/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:57:09 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/28 19:00:13 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static int	ft_swap(t_stack *stack)
{
	t_int_dlist	*head;
	t_int_dlist	*next;
	int			tmp;

	if (stack->n < 2)
		return (0);
	head = stack->head;
	next = head->next;
	tmp = head->content;
	head->content = next->content;
	next->content = tmp;
	return (1);
}

void	ft_sa(t_vars *vars, int print)
{
	if (ft_swap(vars->a) && print)
		ft_printf("sa\n");
}

void	ft_sb(t_vars *vars, int print)
{
	if (ft_swap(vars->b) && print)
		ft_printf("sb\n");
}

void	ft_ss(t_vars *vars)
{
	ft_sa(vars, 0);
	ft_sb(vars, 0);
	ft_printf("ss\n");
}
