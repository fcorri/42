/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:41:59 by fcorri            #+#    #+#             */
/*   Updated: 2023/10/07 11:34:09 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static t_stack	*ft_init_stacks(t_vars *vars)
{
	t_stack	*a;

	vars->a = ft_new_stack();
	a = vars->a;
	vars->b = ft_new_stack();
	if (!a || !vars->b)
		ft_free_and_exit(vars, 1);
	return (a);
}

int	ft_init(int argc, char **argv, t_vars *vars)
{
	char		*param;
	t_stack		*a;

	a = ft_init_stacks(vars);
	if (argc == 2)
		ft_split_decorator_ps(argv, vars, a);
	else
	{
		while (argc-- != 1)
		{
			param = argv[argc];
			if (ft_isdigit_decorator_ps(param))
				ft_free_and_exit(vars, 1);
			ft_push(a, ft_atoi_decorator_ps(vars, a, param));
		}
	}
	return (a->n);
}
