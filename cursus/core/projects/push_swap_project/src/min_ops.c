/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:00:36 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/25 18:32:37 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static VECTOR	ft_calc_total_ops(VECTOR r_a_b, VECTOR best)
{
	VECTOR	output;

	if ((r_a_b.x ^ r_a_b.y) >= 0)
	{
		if (r_a_b.x > 0)
			output.x = ft_max(r_a_b.x, r_a_b.y);
		else
			output.x = -ft_min(r_a_b.x, r_a_b.y);
	}
	else
		output.x = ft_abs(r_a_b.x) + ft_abs(r_a_b.y);
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

static VECTOR	ft_calc_r_a_b_ops_to_insert(int input, STACK *a, VECTOR r_a_b,
	VECTOR r_a_b_best)
{
	int		size;
	NODE	*node;
	VECTOR	min_max;
	VECTOR	tmp;

	size = a->n;
	min_max = a->min_max;
	if (min_max.x < input && input < min_max.y)
	{
		node = a->head;
		while (size--)
		{
			if (node->content < input)
				r_a_b.x++;
			node = node->next;
		}
		size = a->n;
		if (r_a_b.x > size - r_a_b.x)
			r_a_b.x = r_a_b.x - size;
	}
	tmp = ft_calc_total_ops(r_a_b, r_a_b_best);
	if (tmp.x < tmp.y
		|| (tmp.x == tmp.y && ft_abs(r_a_b.y) > ft_abs(r_a_b_best.y)))
		r_a_b_best = ft_update_r_a_b_best_min_max(a, input, r_a_b, r_a_b_best);
	return (r_a_b_best);
}

static VECTOR	ft_calc_min_ops(STACK *a, NODE *start, VECTOR r_a_b, int stop)
{
	NODE	*node;
	int		index;

	node = start->next;
	index = 0;
	while (index++ < stop)
	{
		r_a_b = ft_calc_r_a_b_ops_to_insert(node->content, a,
				(VECTOR){ft_find_index_min(a), index}, r_a_b);
		node = node->next;
		if (ft_abs(r_a_b.x) + ft_abs(r_a_b.y) < stop)
			stop = ft_abs(r_a_b.x) + ft_abs(r_a_b.y);
	}
	node = start->prev;
	index = 0;
	while (index++ < stop)
	{
		r_a_b = ft_calc_r_a_b_ops_to_insert(node->content, a,
				(VECTOR){ft_find_index_min(a), -index}, r_a_b);
		node = node->prev;
		if (ft_abs(r_a_b.x) + ft_abs(r_a_b.y) < stop)
			stop = ft_abs(r_a_b.x) + ft_abs(r_a_b.y);
	}
	return (r_a_b);
}

static VECTOR	ft_rrot_a_b(VECTOR r_a_b, VARS *vars)
{
	int	same;

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
	return (r_a_b);
}

void	ft_push_min_ops(VARS *vars)
{
	STACK	*a;
	STACK	*b;
	VECTOR	r_a_b;

	a = vars->a;
	b = vars->b;
	r_a_b = ft_calc_r_a_b_ops_to_insert(b->head->content, a,
			(VECTOR){ft_find_index_min(a), 0}, (VECTOR){INT_MAX, 0});
	if (r_a_b.x && b->n > 1)
		r_a_b = ft_calc_min_ops(a, b->head, r_a_b, b->n / 2);
	if ((r_a_b.x ^ r_a_b.y) >= 0)
		r_a_b = ft_rrot_a_b(r_a_b, vars);
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
	ft_pa(vars);
}
