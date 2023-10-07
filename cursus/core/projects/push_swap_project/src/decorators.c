/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decorators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:41:59 by fcorri            #+#    #+#             */
/*   Updated: 2023/10/07 17:38:59 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

int	ft_isdigit_decorator_ps(char *param)
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

static void	ft_free_and_exit_decorator(char **argv, t_vars *vars)
{
	int	index;

	index = 0;
	while (argv[index])
		free(argv[index++]);
	free(argv);
	ft_free_and_exit(vars, 1);
}

static t_int_dlist	*ft_atol_decorator_ps_argv(t_vars *vars, t_stack *a,
	char *input, char **argv)
{
	long			output;
	t_int_dlist		*head;
	int				arg;
	static int		args = 0;
	char			sign;

	output = ft_atol(input);
	sign = *input;
	if (output < INT_MIN || output > INT_MAX || (sign == '-' && output >= 0)
		|| ((ft_isdigit(sign) || sign == '+') && output < 0))
		ft_free_and_exit_decorator(argv, vars);
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

t_int_dlist	*ft_atol_decorator_ps(t_vars *vars, t_stack *a, char *input)
{
	int				output;
	t_int_dlist		*head;
	int				arg;
	static int		args = 0;
	char			sign;

	output = ft_atol(input);
	sign = *input;
	if (output < INT_MIN || output > INT_MAX || (sign == '-' && output >= 0)
		|| ((ft_isdigit(sign) || sign == '+') && output < 0))
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

void	ft_split_decorator_ps(char **argv, t_vars *vars, t_stack *a)
{
	int		args;
	char	*param;

	argv = ft_split(argv[1], ' ');
	args = 0;
	while (argv[args])
		args++;
	while (args--)
	{
		param = argv[args];
		if (ft_isdigit_decorator_ps(param))
			ft_free_and_exit_decorator(argv, vars);
		ft_push(a, ft_atol_decorator_ps_argv(vars, a, param, argv));
	}
	while (argv[++args])
		free(argv[args]);
	free(argv);
}
