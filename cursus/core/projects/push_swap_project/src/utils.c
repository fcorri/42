/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:38:12 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/18 16:18:07 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_free_and_return(t_vars *vars, int output)
{
	if (vars->a)
		free(vars->a->this);
	free(vars->a);
	if (vars->b)
		free(vars->b->this);
	free(vars->b);
	if (output)
		ft_error();
	return (output);
}
