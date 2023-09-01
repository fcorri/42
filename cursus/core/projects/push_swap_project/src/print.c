/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:17:08 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/01 18:06:51 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

void	ft_print_queue(VARS *vars)
{
	NODE	*node;

	node = vars->output->head;
	while (node)
	{
		ft_printf("%s\n", vars->names[node->content]);
		node = node->next;
	}
}

void	ft_print(t_vars *vars)
{
	STACK	*a;
	STACK	*b;
	NODE	*first;
	NODE	*second;
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
			ft_printf("%6d", first->content);
			n_a--;
			first = first->next;
		}
		ft_printf("\t");
		if (n_b)
		{
			ft_printf("%6d", second->content);
			n_b--;
			second = second->next;
		}
		ft_printf("\n");
	}
}
