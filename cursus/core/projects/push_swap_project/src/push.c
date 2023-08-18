/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:48:01 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/18 20:02:26 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static void	ft_push(t_stack *src, t_stack *dest)
{
	if (!src->n)
		return ;
	dest->n++;
	dest->head = ft_next(dest);
	*dest->head = *src->head;
	src->head = ft_prev(src);
	src->n--;
}

void	ft_pa(t_vars *vars)
{
	ft_push(vars->b, vars->a);
}

void	ft_pb(t_vars *vars)
{
	ft_push(vars->a, vars->b);
}
