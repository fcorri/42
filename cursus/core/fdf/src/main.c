/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:47:40 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/09 18:54:15 by fcorri           ###   ########.fr       */
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

static int	ft_render(t_mlx *mlx)
{
	(void) mlx;
	return (0);
}

static int	ft_key_down(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		mlx_destroy_window(mlx->this, mlx->win);
	return (0);
}

int main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_map	*map;
//	t_image	*img;

	map = ft_check_args_and_init_map(argc, argv[1]);
	if (!map)
		exit(EXIT_FAILURE);
	mlx = ft_init_mlx();
	if (!mlx)
		exit(EXIT_FAILURE);
//	if (!ft_init_img(mlx, &img))
	mlx_loop_hook(mlx->this, ft_render, mlx);
	mlx_hook(mlx->win, 2, 1L<<0, ft_key_down, mlx);
	mlx_loop(mlx->this);
	mlx_destroy_display(mlx->this);
	free(mlx->this);
	return (0);
}
