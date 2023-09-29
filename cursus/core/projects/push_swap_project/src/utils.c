/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:38:12 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/29 14:03:23 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

void	ft_exit(int error)
{
	if (error)
		write(2, "Error\n", 6);
	exit(1);
}

int	ft_min(int first, int second)
{
	if (first < second)
		return (first);
	return (second);
}

int	ft_max(int first, int second)
{
	if (first < second)
		return (second);
	return (first);
}

t_bvector	ft_update_r_a_b_best_min_max(t_stack *a, int input, t_bvector r_a_b,
	t_bvector r_a_b_best)
{
	t_bvector	min_max;

	min_max = a->min_max;
	r_a_b_best = r_a_b;
	if (input < min_max.x)
		a->min_max.x = input;
	else if (min_max.y < input)
		a->min_max.y = input;
	return (r_a_b_best);
}
