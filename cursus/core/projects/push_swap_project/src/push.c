/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:48:01 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/27 17:31:50 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static void	ft_push_op(STACK *src, STACK *dest)
{
	ft_push(dest, ft_pop(src));
}

void	ft_pa(VARS *vars)
{
	ft_push_op(vars->b, vars->a);
	ft_printf("pa\n");
}

void	ft_pb(VARS *vars)
{
	ft_push_op(vars->a, vars->b);
	ft_printf("pb\n");
}
