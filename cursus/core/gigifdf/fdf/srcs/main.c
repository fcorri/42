/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmogid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:38:02 by larmogid          #+#    #+#             */
/*   Updated: 2023/05/06 18:07:56 by larmogid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	expose_access(t_fdf *fdf);
/*mlx_hook-->manage closing*/

int	main(int argc, char **argv)
{
	char	*file_name;
	t_fdf	*fdf;

	if (argc != 2)
		error(1);
	file_name = argv[1];
	fdf = init_fdf(file_name);
	render(fdf);
	mlx_key_hook(fdf->win, &key_management, fdf);
	mlx_expose_hook(fdf->win, &expose_access, fdf);
	mlx_hook(fdf->win, 17, 0, &cl_all, (void *)fdf);
	mlx_loop(fdf->mlx);
}

static int	expose_access(t_fdf *fdf)
{
	render(fdf);
	return (0);
}
