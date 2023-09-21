/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:17:08 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/21 11:37:12 by fcorri           ###   ########.fr       */
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
	write(1, "", 1);
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
	ft_printf("\tPILA A\t\tPILA B\n");
	first = a->head;
	second = b->head;
	while (n--)
	{
		if (n_a && n_b)
		{
			ft_printf("%12d\t%12d\n", first->content, second->content);
			n_a--;
			first = first->next;
			n_b--;
			second = second->next;
		}
		else if (n_a)
		{
			ft_printf("%12d\n", first->content);
			n_a--;
			first = first->next;
		}
		else
		{
			ft_printf("\t\t%12d\n", second->content);
			second = second->next;
			n_b--;
		}
	}
}
