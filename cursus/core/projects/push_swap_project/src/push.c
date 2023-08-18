/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:48:01 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/15 19:18:19 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static void	ft_push(t_stack *src, t_stack *dest)
{
	if (!src->n)
		return ;
	dest->head = ft_next(dest);
	*dest->head = *src->head;
	src->head = ft_prev(src);
	src->n--;
	dest->n++;
}

void	ft_pa(t_vars *vars)
{
	ft_push(vars->b, vars->a);
}

void	ft_pb(t_vars *vars)
{
	ft_push(vars->a, vars->b);
}
