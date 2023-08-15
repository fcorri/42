/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:24:13 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/15 16:26:55 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

int main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 1)
		ft_error();
	ft_init(argc, argv, &vars);

	ft_test_stack(&vars, ft_sa);

	return (ft_free_and_return(&vars, 0));
}

