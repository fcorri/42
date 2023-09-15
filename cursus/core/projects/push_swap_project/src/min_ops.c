/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:00:36 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/15 18:25:13 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"
#include <limits.h>

static int	ft_find_i_min(STACK *stack, int size)
{
	int		i;
	NODE	*node;

	i = 0;	
	node = stack->head;
	while (node->content > node->prev->content)
	{
		i++;
		node = node->next;
	}
	if (i > size - i)
		i = i - size;
	return (i);
}

static VECTOR	ft_calc_r_a_b_ops_to_insert(int input, VARS *vars, int r_b, VECTOR r_a_b_best)
{
	STACK	*a;
	int		index;
	int 	size;
	NODE	*node;
	int		r_a;

	a = vars->a;
	size = a->n;
	r_a = ft_find_i_min(a, size);
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
	if (ft_abs(r_a) + ft_abs(r_b) <= ft_abs(r_a_b_best.x) + ft_abs(r_a_b_best.y))
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
		r_a_b = ft_calc_min_ops(vars, b->head, r_a_b, ft_min(ft_abs(r_a_b.x), b->n / 2));
	ft_rot_a_b(r_a_b, vars);
	ft_pa(vars);
}
