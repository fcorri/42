/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:17:08 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/15 18:45:58 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

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
	first = a->head;
	second = b->head;
	while (n--)
	{
		if (n_a)
		{
			ft_printf("%6d", *first--);
			if (first == a->this - 1)
				first += a->n;
			n_a--;
		}
		ft_printf("\t");
		if (n_b)
		{
			ft_printf("%6d", *second--);
			if (second == b->this - 1)
				second += b->n;
			n_b--;
		}
		ft_printf("\n");
	}
}
