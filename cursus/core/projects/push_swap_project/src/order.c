/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:55:36 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/01 19:46:29 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

#define LIMIT	2

int	ft_order(VARS *vars, int prev_index)
{
	static int	calls = 0;
	int			start;
	int			index;
	int			callables;
	static int	(**ops)(VARS *vars, int inv);

	if (ft_is_ordered(vars->a) && ft_is_empty(vars->b))
		return (1);
	if (calls++ == LIMIT)
	{
		calls--;
		vars->callables &= ~(0b1 << prev_index);
		vars->inv[prev_index](vars, 1);
		return (0);
	}
	start = -1;
	callables = vars->callables;
	if (!ops)
		ops = vars->ops;
	while (1)
	{
		index = start;
		while (++index < 8)
			if (((callables >> index) & 0b1) && ops[index](vars, 0) && ft_order(vars, index))
				return (1);
		start++;
		start %= 7;
	}
}
