/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:30:38 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/15 15:46:38 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

void	ft_test_stack(t_vars *vars, void (*ft_to_test)(t_vars *vars))
{
	ft_print(vars);
	ft_to_test(vars);
	ft_print(vars);
}
