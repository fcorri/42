/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:00:36 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/15 01:45:46 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"
#include <limits.h>

static int	ft_find_i_min(STACK *stack)
{
	int		i;
	NODE	*node;
	int		size;

	i = 0;	
	node = stack->head;
	size = stack->n;
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
	int 	size;
	NODE	*node;
	int		r_a;

	a = vars->a;
	r_a = ft_find_i_min(a);
	if (a->min < input && input < a->max)
	{
		size = a->n;
		node = a->head;
		while (size--)
		{
			if (node->content < input)
				r_a++;
			node = node->next;
		}
	}
	size = a->n;
	if (r_a > size - r_a)
		r_a = r_a - size;
	if (ft_abs(r_a) + r_b < ft_abs(r_a_b_best.x))
	{
		r_a_b_best = (VECTOR){r_a, r_b};
		if (input < a->min)
			a->min = input;
		else if (a->max < input)
			a->max = input;
	}
	return (r_a_b_best);
}

static int	ft_min(int first, int second)
{
	if (first < second)
		return (first);
	return (second);
}

static VECTOR	ft_calc_min_ops(VARS *vars, NODE *start, VECTOR r_a_b, VECTOR index_stop)
{
	VECTOR	count_tmp;
	NODE	*next;
	NODE	*prev;
	NODE	*node;

	next = start->next;
	prev = start->prev;
	while (index_stop.x++ < index_stop.y)
	{
		count_tmp.x = 2;	
		node = next;
		while (count_tmp.x--)
		{
			r_a_b = ft_calc_r_a_b_ops_to_insert(node->content, vars, index_stop.x, r_a_b);
			if (r_a_b.x < index_stop.y)
				index_stop.y = r_a_b.x;
			node = prev;
		}
		next = next->next;
		prev = prev->prev;
	}
	return (r_a_b);
}

void	ft_push_min_ops(VARS *vars)
{
	STACK	*b;
	VECTOR	r_a_b;

	b = vars->b;
	r_a_b = (VECTOR){INT_MAX, 0};
	r_a_b = ft_calc_r_a_b_ops_to_insert(b->head->content, vars, 0, r_a_b);
	if (b->n > 1)
		r_a_b = ft_calc_min_ops(vars, b->head, r_a_b, (VECTOR){ft_min(ft_abs(r_a_b.x), b->n / 2), 0});
	if (r_a_b.x < 0)
		while (r_a_b.x++)
			ft_rra(vars);
	else
		while (r_a_b.x--)
			ft_ra(vars);
	if (r_a_b.y < 0)
		while (r_a_b.y++)
			ft_rrb(vars);
	else
		while (r_a_b.y--)
			ft_rb(vars);
	ft_pa(vars);
}
