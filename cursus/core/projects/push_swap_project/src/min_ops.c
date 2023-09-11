/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:00:36 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/11 18:58:57 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static int	ft_stop(int n)
{
	int	output;

	output = n >> 1;
	if (n & 0b1)
		return (output + 1);
	return (output);
}

static int	ft_calc_min_between_r_and_rr_to_insert(int input, NODE *head)
{
	int	r;
	int	rr;

	r = 0;
	while (input > head->content && input < head->next->content)
	{
		head = head->next;
		r++;
	}
	rr = 0;
	while (input < head->content && input > head->next->content)
	{
		head = head->next;
		rr++;
	}
	if (r <= rr)
		return (r);
	return (rr);
}

void	ft_push_min_ops(VARS *vars)
{
	int	stop;

	stop = ft_stop(vars->b->n);
	int min = ft_calc_min_between_r_and_rr_to_insert(vars->b->head->content, vars->a->head);
	(void) min;
}
