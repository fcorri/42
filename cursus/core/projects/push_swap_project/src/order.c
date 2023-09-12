/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:55:36 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/12 20:11:41 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

#ifndef CHECK
# define CHECK 0
#endif

struct s_vars
{
	int	first;
	int	second;
	int	third;
	int	tmp;
};

static void	ft_order_three(NODE *head, VARS *vars)
{
	struct s_vars	triple;

	triple.first = head->content;
	triple.second = head->next->content;
	triple.third = head->prev->content;
	triple.tmp = triple.first;
	if (triple.first > triple.second && triple.first > triple.third)
	{
		ft_ra(vars);
		triple.first = triple.second;
		triple.second = triple.third;
		triple.third = triple.tmp;
	}
	else if (triple.first < triple.second && triple.second > triple.third)
	{
		ft_rra(vars);
		triple.first = triple.third;
		triple.third = triple.second;
		triple.second = triple.tmp;
	}
	if (triple.first > triple.second)
	{
		ft_sa(vars);
		triple.tmp = triple.first;
		triple.first = triple.second;
		triple.second = triple.tmp;
	}
	vars->a->min_max = (VECTOR){triple.first, triple.third};
	vars->a->i_min = 0;
}

static void	ft_order_more(VARS *vars, int size)
{
	int	n;

	n = size;
	while (n-- > 3)
		ft_pb(vars);
	ft_order_three(vars->a->head, vars);
	n = size - 3;
	while (n--)
		ft_push_min_ops(vars);
	n = vars->a->i_min;
	if (ft_abs(n) > size + n)
		n = size + n;
	if (n > 0)
		while (n--)
			ft_ra(vars);
	else
		while (n++)
			ft_rra(vars);
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
	else
		ft_order_more(vars, n);
}
