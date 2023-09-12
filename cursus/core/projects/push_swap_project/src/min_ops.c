/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:00:36 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/12 20:15:10 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static int	ft_calc_min_between_r_and_rr_to_insert(int input, STACK *stack)
{
	NODE	*head;
	NODE	*tmp;
	VECTOR	r_rr;

	head = stack->head;
	tmp = head;
	r_rr = (VECTOR){0, 0};
	if (input < stack->min_max.x)
		stack->min_max.x = input;
	else if (input > stack->min_max.y)
	{
		stack->min_max.y = input;
		stack->i_min++;
	}
	else
	{
		while (input > head->content)
		{
			head = head->next;
			r_rr.x++;
		}
		head = tmp;
		while (input > head->content)
		{
			head = head->prev;
			r_rr.y++;
		}
	}
	if (r_rr.x <= r_rr.y)
		return (r_rr.x);
	return (r_rr.y);
}

void	ft_push_min_ops(VARS *vars)
{
	int		min;
	int		ops;
	int		index;
	int		r;
	int		rr;
	NODE	*head;
	NODE	*tmp;

	head = vars->b->head;
	tmp = head;
	min = ft_calc_min_between_r_and_rr_to_insert(head->content, vars->a);
	r = 0;
	index = 0;
	while (index++ < min)
	{
		head = head->next;
		if (!head)
			break ;
		ops = ft_calc_min_between_r_and_rr_to_insert(head->content, vars->a);
		if (ft_abs(ops) + index < ft_abs(min))
		{
			min = ops;
			r = index;
		}
	}
	head = tmp;
	rr = 0;
	index = 0;
	while (index++ < min)
	{
		head = head->prev;
		if (!head)
			break ;
		ops = ft_calc_min_between_r_and_rr_to_insert(head->content, vars->a);
		if (ft_abs(ops) + index < ft_abs(min))
		{
			min = ops;
			rr = index;
		}
	}
	if (r <= rr)
		while (r--)
			ft_rb(vars);
	else
		while (rr--)
			ft_rrb(vars);
	if (min < 0)
		while (min++ != 0)
			ft_rra(vars);
	else
		while (min-- != 0)
			ft_ra(vars);
	ft_pa(vars);
}
