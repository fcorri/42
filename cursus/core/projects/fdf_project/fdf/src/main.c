/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:47:40 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/19 16:47:09 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

// manca la chiusura con click sulla croce

int	main(int argc, char **argv)
{
	t_vars	vars;

	ft_bzero(&vars, sizeof(vars));
	if (argc == 1)
		return (ft_error("ARGS", strerror(22)));
	if (argc != 2)
		return (ft_error("ARGS", strerror(7)));
	if (!ft_init_fdf(&vars, argv[1]))
		return (ft_free_and_return(&vars, 1));
	mlx_hook(vars.mlx->win, 2, 1L << 0, ft_key_down, &vars);
	vars.camera->ft_view(&vars);
	ft_render(&vars);
	mlx_loop(vars.mlx->this);
	return (ft_free_and_return(&vars, 0));
}
