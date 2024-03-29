/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:55:36 by fcorri            #+#    #+#             */
/*   Updated: 2023/10/06 19:06:10 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

#ifndef CHECK
# define CHECK 0
#endif

static void	ft_order_three(t_vars *vars, t_int_dlist *head)
{
	t_bvector	first_second;
	t_bvector	third_tmp;

	first_second = (t_bvector){head->content, head->next->content};
	third_tmp = (t_bvector){head->prev->content, first_second.x};
	if (first_second.x > first_second.y && first_second.x > third_tmp.x)
	{
		ft_ra(vars, 1);
		first_second.x = first_second.y;
		first_second.y = third_tmp.x;
		third_tmp.x = third_tmp.y;
	}
	else if (first_second.x < first_second.y && first_second.y > third_tmp.x)
	{
		ft_rra(vars, 1);
		first_second.x = third_tmp.x;
		third_tmp.x = first_second.y;
		first_second.y = third_tmp.y;
	}
	if (first_second.x > first_second.y)
	{
		ft_sa(vars, 1);
		first_second.x = first_second.y;
	}
	vars->a->min_max = (t_bvector){first_second.x, third_tmp.x};
}

static void	ft_rot_min(t_vars *vars)
{
	int	n;

	n = ft_find_index_min(vars->a);
	if (!n)
		return ;
	if (n < 0)
		while (n++)
			ft_rra(vars, 1);
	else
		while (n--)
			ft_ra(vars, 1);
}

static void	ft_order_more(t_vars *vars, int size)
{
	int	n;

	n = size;
	while (n-- > 3)
		ft_pb(vars);
	ft_order_three(vars, vars->a->head);
	n = size - 3;
	while (n--)
		ft_push_min_ops(vars);
	ft_rot_min(vars);
}

void	ft_order(t_vars *vars, int size)
{
	if (size == 2)
		ft_sa(vars, 1);
	else if (size == 3)
		ft_order_three(vars, vars->a->head);
	else
		ft_order_more(vars, size);
}
