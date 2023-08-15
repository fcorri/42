/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decorators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:28:00 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/15 16:12:45 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

int	ft_atoi_decorator_stack(t_vars *vars, char *input)
{
	int			output;
	int			*first;
	int			arg;
	static int	args = 0;

	output = ft_atoi(input);
	if (*input == '-' && !output)
		ft_free_and_return(vars, 1);
	else if (output == -1)
		ft_free_and_return(vars, 1);
	first = vars->a->this;
	arg = 0;
	while (arg < args)
		if (first[arg++] == output)
			ft_free_and_return(vars, 1);
	args++;
	return (output);
}
