/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:41:59 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/22 20:54:32 by fcorri           ###   ########.fr       */
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

static t_int_dlist	*ft_atoi_decorator(VARS *vars, STACK *a, char *input)
{
	int			output;
	NODE		*head;
	int			arg;
	static int	args = 0;

	output = ft_atoi(input);
	if (*input == '-' && !output)
		ft_free_and_return(vars, 1);
	else if (output == -1)
		ft_free_and_return(vars, 1);
	head = a->head;
	arg = 0;
	while (arg++ < args)
	{
		if (head->content == output)
			ft_free_and_return(vars, 1);
		head = head->next;
	}
	args++;
	return (ft_int_dlst_new(output));
}

void	ft_init(int argc, char **argv, t_vars *vars)
{
	char	*param;
	STACK	*a;
	STACK	*b;

	vars->a = ft_new_stack();
	a = vars->a;
	vars->b = ft_new_stack();
	b = vars->b;
	if (!a || !b)
		ft_free_and_return(vars, 1);
	while (--argc)
	{
		param = argv[argc];
		if (ft_check_for_non_digits(param))
			ft_free_and_return(vars, 1);
		ft_push(a, ft_atoi_decorator(vars, a, param));
	}
}
