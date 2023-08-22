/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:57:09 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/22 20:55:46 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static void	ft_swap(STACK *stack)
{
	NODE	*head;
	NODE	*next;
	int		tmp;

	if (stack->n < 2)
		return ;
	head = stack->head;
	next = head->next;
	tmp = head->content;
	head->content = next->content;
	next->content = tmp;
}

void	ft_sa(VARS *vars)
{
	ft_swap(vars->a);
}

void	ft_sb(VARS *vars)
{
	ft_swap(vars->b);
}

void	ft_ss(VARS *vars)
{
	ft_sa(vars);
	ft_sb(vars);
}
