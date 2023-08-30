/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:55:36 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/30 14:00:15 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

void	ft_order(VARS *vars)
{
	int	callables;
	int	index;
	static int calls = 0;
	static char	*(**ops)(VARS *vars);
	char	*output;

	if (calls++ >= 5)
	{
		calls--;
		return ;
	}
	callables = vars->callables;
	index = 0;
	if (!ops)
		ops = vars->ops;
	while (!ft_is_ordered(vars->a) || !ft_is_empty(vars->b))
	{
		while ((callables >> index & 0x1) == 0)
			index++;
		output = ops[index](vars);
		if (output)
			ft_printf("Call number: %d\tOperation: %s\n", calls, output);
		else
			calls--;
		ft_order(vars);
	}
}
