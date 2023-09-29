/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:41:59 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/29 15:54:00 by fcorri           ###   ########.fr       */
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
	if ((*input == '-' && output == 0) || (ft_isdigit(*input) && output < 0))
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

int	ft_init(int argc, char **argv, t_vars *vars)
{
	char	*param;
	int		old_argc;
	int		incr;
	t_stack	*a;

	a = ft_init_stacks(vars);
	incr = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = 1;
		while (argv[argc - 1])
			argc++;
		incr = -1;
	}
	old_argc = argc;
	while (--argc)
	{
		param = argv[argc + incr];
		if (ft_check_for_non_digits(param))
			ft_free_and_exit(vars, 1);
		ft_push(a, ft_atoi_decorator(vars, a, param));
	}
	return (old_argc);
}
