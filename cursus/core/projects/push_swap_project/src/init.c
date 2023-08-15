/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:41:59 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/15 15:58:47 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static t_stack	*ft_alloc_stack(int argc, t_stack **p_stack, int n)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->this = malloc(sizeof(int) * --argc);
	if (!stack->this)
		return (NULL);
	stack->head = stack->this;
	stack->n = n;
	stack->max = argc;
	*p_stack = stack;
	return (stack);
}

void	ft_init(int argc, char **argv, t_vars *vars)
{
	char	*param;
	int		index;
	t_stack	*a;
	t_stack	*b;

	a = ft_alloc_stack(argc, &vars->a, argc - 1);
	b = ft_alloc_stack(argc, &vars->b, 0);
	if (!a || !b)
		ft_free_and_return(vars, 1);
	while (--argc > 0)
	{
		param = *++argv;
		index = 0;
		if (param[index] == '-' || param[index] == '+')
			index++;
		while (ft_isdigit(param[index]))
			index++;
		if (param[index] != '\0')
			ft_free_and_return(vars, 1);
		*a->head++ = ft_atoi_decorator_stack(vars, param);
	}
}
