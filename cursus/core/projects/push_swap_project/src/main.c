/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:24:13 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/31 14:13:38 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"
#include <stdio.h>
#include <string.h>



int main(int argc, char **argv)
{
	t_vars	vars;
	int		n;

	if (argc == 1)
		ft_exit();
	ft_init(argc, argv, &vars);
	if (!ft_is_ordered(vars.a))
	{
		ft_order(&vars, 0);
		n = vars.output->n;
		while (n--)
			ft_printf("%d\n", ft_pop(vars.output)->content);
	}
	return (ft_free_and_return(&vars, 0));
}
