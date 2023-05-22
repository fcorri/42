/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:47:40 by fcorri            #+#    #+#             */
/*   Updated: 2023/05/22 23:47:39 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

int main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_map	*map;

	if (ft_check_args(argc, argv))
		exit(EXIT_FAILURE);
	map = ft_init_map();
	mlx = ft_init_mlx();
	if (!mlx)
		exit(EXIT_FAILURE);
	ft_init_hooks(&mlx);
	// loop
	return (0);
}
