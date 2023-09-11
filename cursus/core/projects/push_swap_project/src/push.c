/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:48:01 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/11 14:35:23 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static int	ft_push_op(STACK *src, STACK *dest)
{
	if (src->n)
		ft_push(dest, ft_pop(src));
	return (1);
}

void	ft_pa(VARS *vars)
{
	if (ft_push_op(vars->b, vars->a))
		ft_enqueue(vars->output, ft_int_dlst_new(2));
}

void	ft_pb(VARS *vars)
{
	if (ft_push_op(vars->a, vars->b))
		ft_enqueue(vars->output, ft_int_dlst_new(3));
}
