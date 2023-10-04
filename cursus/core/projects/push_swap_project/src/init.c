/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:41:59 by fcorri            #+#    #+#             */
/*   Updated: 2023/10/04 20:36:37 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static int	ft_check_for_non_digits(char *param)
{
	char	sign;

	sign = *param;
	if (sign == '-' || sign == '+')
		param++;
	while (ft_isdigit(*param))
		param++;
	if (*param != '\0')
		return (1);
	return (0);
}

static t_int_dlist	*ft_atoi_decorator(t_vars *vars, t_stack *a, char *input)
{
	int				output;
	t_int_dlist		*head;
	int				arg;
	static int		args = 0;

	output = ft_atoi(input);
	if ((*input == '-' && output >= 0) || (ft_isdigit(*input) && output < 0))
		ft_free_and_exit(vars, 1);
	head = a->head;
	arg = 0;
	while (arg++ < args)
	{
		if (head->content == output)
			ft_free_and_exit(vars, 1);
		head = head->next;
	}
	args++;
	return (ft_int_dlst_new(output));
}

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

static int	ft_free_argv(char **argv, t_bvector argc, int ret, t_vars *vars)
{
	int	index;

	if (argc.x != argc.y)
	{
		index = 0;
		while (argv[index])
			free(argv[index++]);
		free(argv);
	}
	if (ret)
		ft_free_and_exit(vars, 1);
	return (argc.y);
}

int	ft_init(t_bvector argc, char **argv, t_vars *vars)
{
	char		*param;
	t_bvector	index_incr;
	t_stack		*a;

	a = ft_init_stacks(vars);
	index_incr = (t_bvector){0, 0};
	if (argc.x == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc.y = 1;
		while (argv[argc.y - 1])
			argc.y++;
		index_incr.y = -1;
	}
	while (index_incr.x++ != argc.y)
	{
		param = argv[argc.y + index_incr.y];
		if (ft_check_for_non_digits(param))
			ft_free_argv(argv, argc, 1, vars);
		ft_push(a, ft_atoi_decorator(vars, a, param));
	}
	return (ft_free_argv(argv, argc, 0, vars));
}
