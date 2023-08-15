/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:38:12 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/15 16:23:33 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_free_and_return(t_vars *vars, int output)
{
	if (vars->a)
		free(vars->a->this);
	free(vars->a);
	if (vars->b)
		free(vars->b->this);
	free(vars->b);
	if (output)
		ft_error();
	return (output);
}

void	ft_print(t_vars *vars)
{
	t_stack	*a;
	t_stack	*b;
	int	*first;
	int	*second;
	int	n, n_a, n_b;

	a = vars->a;
	b = vars->b;
	n_a = a->n;
	n_b = b->n;
	n = n_a;
	if (n_b > n_a)
		n = n_b;
	ft_printf("PILA A\tPILA B\n");
	first = a->this;
	second = b->this;
	while (n--)
	{
		if (n_a)
		{
			ft_printf("%6d", *first++);
			n_a--;
		}
		ft_printf("\t");
		if (n_b)
		{
			ft_printf("%6d", *second++);
			n_b--;
		}
		ft_printf("\n");
	}
}
