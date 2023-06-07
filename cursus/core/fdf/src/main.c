/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:47:40 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/06 09:18:08 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static t_map	*ft_check_args_and_init_map(int argc, char *filename)
{
	int errsv;

	errsv = 0;
	if (argc == 1)
		errsv = 22;
	else if (argc != 2)
		errsv = 7;
	if (errsv)
		return (ft_null_error(strerror(errsv)));
	return (ft_init_map(filename));
}


int main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	map;

	map = ft_check_args_and_init_map(argc, argv[1]);
	if (!map)
		exit(EXIT_FAILURE);
	mlx = ft_init_mlx();
	if (!mlx)
		exit(EXIT_FAILURE);
	ft_init_hooks(mlx.this);
	mlx_loop(mlx.this);
	mlx_destroy_display(mlx.this);
	free(mlx.this);
	return (0);
}
