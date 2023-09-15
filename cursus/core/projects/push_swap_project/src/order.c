/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:55:36 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/15 10:32:20 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

#ifndef CHECK
# define CHECK 0
#endif

static void	ft_order_three(VARS *vars, NODE *head)
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
	{
		ft_sa(vars);
		first = second;
	}
	vars->a->min = first;
	vars->a->max = third;
}

static void	ft_rot_min(VARS *vars, int size)
{
	NODE	*head;
	int		n;

	head = vars->a->head;
	n = 0;
	while (head->content > head->prev->content)
	{
		head = head->next;
		n++;
	}
	if (n > size - n)
	{
		n = size - n;
		while (n--)
			ft_rra(vars);
	}
	else
		while (n--)
			ft_ra(vars);
}

static void	ft_order_more(VARS *vars, int size)
{
	int		n;

	n = size;
	while (n-- > 3)
		ft_pb(vars);
	ft_order_three(vars, vars->a->head);
	n = size - 3;
	while (n--)
		ft_push_min_ops(vars);
	ft_rot_min(vars, size);
}

void	ft_order(VARS *vars, int size)
{
	if (CHECK)
		ft_check(vars);
	else if (size == 2)
		ft_sa(vars);
	else if (size == 3)
		ft_order_three(vars, vars->a->head);
	else
		ft_order_more(vars, size);
}
