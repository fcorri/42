/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:57:09 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/11 14:35:57 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static int	ft_swap(STACK *stack)
{
	NODE	*head;
	NODE	*next;
	int		tmp;

	if (stack->n < 2)
		return (0);
	head = stack->head;
	next = head->next;
	tmp = head->content;
	head->content = next->content;
	next->content = tmp;
	return (1);
}

void	ft_sa(VARS *vars)
{
	if (ft_swap(vars->a))
		ft_enqueue(vars->output, ft_int_dlst_new(0));
}

void	ft_sb(VARS *vars)
{
	if (ft_swap(vars->b))
		ft_enqueue(vars->output, ft_int_dlst_new(1));
}

void	ft_ss(VARS *vars)
{
	ft_sa(vars);
	ft_sb(vars);
}
