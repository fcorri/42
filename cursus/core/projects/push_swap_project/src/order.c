/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:55:36 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/11 18:02:25 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

#ifndef CHECK
# define CHECK 0
#endif

static void	ft_order_three(NODE *head, VARS *vars)
{
	int	first;
	int	second;
	int	third;
	int	tmp;

	first = head->content;
	second = head->next->content;
	third = head->prev->content;
	tmp = first;
	if (first > second && first > third)
	{
		ft_ra(vars);
		first = second;
		second = third;
		third = tmp;
	}
	else if (first < second && second > third)
	{
		ft_rra(vars);
		first = third;
		third = second;
		second = tmp;
	}
	if (first > second)
		ft_sa(vars);
}

static void	ft_order_to_five(NODE *head, VARS *vars, int n)
{
	ft_pb(vars);
	if (n == 5)
		ft_pb(vars);
	ft_order_three(head, vars);
	while (vars->b->n)
		ft_push_min_ops(vars);
}

static void	ft_quicksort(VARS *vars, int n)
{
	(void) vars;
	(void) n;
}

void	ft_order(VARS *vars, int n)
{
	NODE	*head;

	head = vars->a->head;
	if (CHECK)
		ft_check(vars);
	else if (n == 2)
		ft_sa(vars);
	else if (n == 3)
		ft_order_three(head, vars);
	else if (n <= 5)
		ft_order_to_five(head, vars, n);
	else
		ft_quicksort(vars, n);
}
