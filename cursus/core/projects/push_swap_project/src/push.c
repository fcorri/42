/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:48:01 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/22 21:00:57 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static void	ft_push_op(STACK *src, STACK *dest)
{
	if (!src->n)
		return ;
	ft_push(dest, ft_pop(src));
}

void	ft_pa(t_vars *vars)
{
	ft_push_op(vars->b, vars->a);
}

void	ft_pb(t_vars *vars)
{
	ft_push_op(vars->a, vars->b);
}
