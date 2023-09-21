/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:00:36 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/21 16:47:31 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static VECTOR	ft_calc_op(int r_a, int r_b, VECTOR best)
{
	VECTOR	output;

	if ((r_a ^ r_b) >= 0)
	{
		if (r_a > 0)
			output.x = ft_max(r_a, r_b);
		else
			output.x = -ft_min(r_a, r_b);
	}
	else
		output.x = ft_abs(r_a) + ft_abs(r_b);
	if ((best.x ^ best.y) >= 0)
	{
		if (best.x > 0)
			output.y = ft_max(best.x, best.y);
		else
			output.y = -ft_min(best.x, best.y);
	}
	else
		output.y = ft_abs(best.x) + ft_abs(best.y);
	return (output);
}

static VECTOR	ft_calc_r_a_b_ops_to_insert(int input, VARS *vars, int r_b, VECTOR r_a_b_best)
{
	STACK	*a;
	int		index;
	int 	size;
	NODE	*node;
	// posso scriverlo insieme a r_b
	int		r_a;
	VECTOR	op_this_best;

	a = vars->a;
	size = a->n;
	r_a = ft_find_index_min(a);
	if (a->min < input && input < a->max)
	{
		index = 0;
		node = a->head;
		while (index++ < size)
		{
			if (node->content < input)
				r_a++;
			node = node->next;
		}
		if (r_a > size - r_a)
			r_a = r_a - size;
	}
	op_this_best = ft_calc_op(r_a, r_b, r_a_b_best);
	if (op_this_best.x < op_this_best.y || (op_this_best.x == op_this_best.y && ft_abs(r_b) > ft_abs(r_a_b_best.y)))
	{
		r_a_b_best = (VECTOR){r_a, r_b};
		if (input < a->min)
			a->min = input;
		else if (a->max < input)
			a->max = input;
	}
	return (r_a_b_best);
}

static VECTOR	ft_calc_min_ops(VARS *vars, NODE *start, VECTOR r_a_b, int stop)
{
	int		count;
	NODE	*node;
	int		index;

	count = 2;
	node = start->next;
	while (count--)
	{
		index = 0;
		while (index++ < stop)
		{
			if (count)
			{
				r_a_b = ft_calc_r_a_b_ops_to_insert(node->content, vars, index, r_a_b);
				node = node->next;
			}
			else
			{
				r_a_b = ft_calc_r_a_b_ops_to_insert(node->content, vars, -index, r_a_b);
				node = node->prev;
			}
			if (ft_abs(r_a_b.x) + ft_abs(r_a_b.y) < stop)
				stop = ft_abs(r_a_b.x) + ft_abs(r_a_b.y);
		}
		node = start->prev;
	}
	return (r_a_b);
}

static void	ft_rot_a_b(VECTOR r_a_b, VARS *vars)
{
	int	same;

	if ((r_a_b.x ^ r_a_b.y) >= 0)
	{
		if (r_a_b.x < 0)
			same = ft_max(r_a_b.x, r_a_b.y);
		else
			same = ft_min(r_a_b.x, r_a_b.y);
		r_a_b = (VECTOR){r_a_b.x - same, r_a_b.y - same};
		if (same <= 0)
			while (same++)
				ft_rrr(vars);
		else
			while (same--)
				ft_rr(vars);
	}
	if (r_a_b.x <= 0)
		while (r_a_b.x++)
			ft_rra(vars);
	else
		while (r_a_b.x--)
			ft_ra(vars);
	if (r_a_b.y <= 0)
		while (r_a_b.y++)
			ft_rrb(vars);
	else
		while (r_a_b.y--)
			ft_rb(vars);
}

void	ft_push_min_ops(VARS *vars)
{
	STACK	*b;
	VECTOR	r_a_b;

	b = vars->b;
	r_a_b = ft_calc_r_a_b_ops_to_insert(b->head->content, vars, 0, (VECTOR){INT_MAX, 0});
	if (r_a_b.x && b->n > 1)
		r_a_b = ft_calc_min_ops(vars, b->head, r_a_b, b->n / 2);
	ft_rot_a_b(r_a_b, vars);
	ft_pa(vars);
}
