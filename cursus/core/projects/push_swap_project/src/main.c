/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:24:13 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/27 17:35:45 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 1)
		ft_exit();
	ft_init(argc, argv, &vars);
	if (!ft_is_ordered(vars.a))
		ft_order(&vars, argc - 1);
	return (ft_free_and_return(&vars, 0));
}
