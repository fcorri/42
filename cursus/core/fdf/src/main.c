/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:47:40 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/22 17:54:25 by fcorri           ###   ########.fr       */
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
		return (ft_null_error("ARGS", strerror(errsv)));
	return (ft_init_map(filename));
}

static int	ft_free_and_return(t_vars *vars, int value)
{
	int	errsv;

	errsv = mlx_destroy_display(vars->mlx->this);
	if (errsv)
		return (ft_error("MLX_DESTROY_DISPLAY", strerror(errsv)));
	free(vars->mlx->this);
	return (value);
}

static int	ft_render(t_vars *vars)
{
	t_map	*map;

	map = vars->map;
	map->ft_draw(vars);
	return (0);
}

static int	ft_key_down(int keycode, t_vars *vars)
{
	t_mlx	*mlx;

	mlx = vars->mlx;
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(mlx->this, mlx->win);
		mlx->win = NULL;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_vars	*vars;

	vars = ft_malloc_soul(sizeof(*vars));
	if (!vars)
	{
		ft_error("MALLOC", strerror(errno));
		exit(EXIT_FAILURE);
	}
	vars->map = ft_check_args_and_init_map(argc, argv[1]);
	if (!vars->map)
		exit(EXIT_FAILURE);
	vars->mlx = ft_init_mlx();
	if (!vars->mlx)
		exit(EXIT_FAILURE);
	vars->image = ft_init_image(vars->mlx);
	if (!vars->image)
		return (ft_free_and_return(vars->mlx->this, 1));
	mlx_loop_hook(vars->mlx->this, ft_render, vars);
	mlx_hook(vars->mlx->win, 2, 1L<<0, ft_key_down, vars);
	mlx_loop(vars->mlx->this);
	return (ft_free_and_return(vars, 0));
}
