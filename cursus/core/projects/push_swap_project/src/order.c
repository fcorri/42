/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:55:36 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/31 13:53:33 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

int	ft_order(VARS *vars, int prev_index)
{
	static int	calls = 0;
	int			start;
	int			index;
	int			callables;
	static int	(**ops)(VARS *vars);

	if (ft_is_ordered(vars->a) && ft_is_empty(vars->b))
		return (1);
	if (calls++ == 2)
	{
		calls--;
		vars->callables &= ~(0b1 << prev_index);
		vars->inv[prev_index](vars);
		return (0);
	}
	start = -1;
	callables = vars->callables;
	if (!ops)
		ops = vars->ops;
	while (!(ft_is_ordered(vars->a) && ft_is_empty(vars->b)))
	{
		index = start;
		while (++index < 8)
			if (((callables >> index) & 0b1) && ops[index](vars) && ft_order(vars, index))
				return (1);
		start++;
		start %= 8;
	}
	return (0);
}
