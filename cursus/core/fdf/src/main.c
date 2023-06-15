/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:47:40 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/15 18:04:22 by fcorri           ###   ########.fr       */
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

static int	ft_free_and_return(void *mlx, int value)
{
	mlx_destroy_display(mlx);
	free(mlx);
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
	if (keycode == XK_Escape)
		mlx_destroy_window((vars->mlx)->this, vars->mlx->win);
	return (0);
}

int main(int argc, char **argv)
{
	t_vars	vars;

	vars.map = ft_check_args_and_init_map(argc, argv[1]);
	if (!vars.map)
		exit(EXIT_FAILURE);
	vars.mlx = ft_init_mlx();
	if (!vars.mlx)
		exit(EXIT_FAILURE);
	vars.image = ft_init_image(vars.mlx);
	if (!vars.image)
		return (ft_free_and_return(vars.mlx->this, 1));
	mlx_loop_hook(vars.mlx->this, ft_render, vars.mlx);
	mlx_hook(vars.mlx->win, 2, 1L<<0, ft_key_down, vars.mlx);
	mlx_loop(vars.mlx->this);
	return (ft_free_and_return(vars.mlx->this, 0));
}
