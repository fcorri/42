/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:47:40 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/01 19:03:27 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

int main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_map	*map;

	map = ft_check_args_and_init_map(argc, argv[1]);
	if (!map)
		exit(EXIT_FAILURE);
	mlx = ft_init_mlx();
	if (!mlx)
		exit(EXIT_FAILURE);
	ft_init_hooks(mlx->instance);
	// loop
	return (0);
}
