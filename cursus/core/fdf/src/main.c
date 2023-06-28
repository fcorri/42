/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:47:40 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/28 19:00:14 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static int	ft_free_and_return(t_vars *vars, int value)
{
	int	index;

	if (vars->image)
	{
		mlx_destroy_image(vars->mlx->this, vars->image->this);
		free(vars->image);
	}
	if (vars->mlx)
	{
		if (vars->mlx->win)
			mlx_destroy_window(vars->mlx->this, vars->mlx->win);
		mlx_destroy_display(vars->mlx->this);
		free(vars->mlx->this);
		free(vars->mlx);
	}
	if (vars->map && vars->map->matrix)
	{
		index = vars->map->rows;
		while (index)
			free((vars->map->matrix)[--index]);
		free(vars->map->matrix);
		free(vars->map);
	}
	return (value);
}

static int	ft_render(t_vars *vars)
{
	return (vars->map->ft_draw(vars));
}

static int	ft_key_down(int keycode, t_vars *vars)
{
	t_mlx	*mlx;

	mlx = vars->mlx;
	if (keycode == XK_v || keycode == XK_V)
		ft_clear_image_and_set_ft_draw(vars, ft_draw_null);
	else if (keycode == XK_Escape)
	{
		mlx_destroy_window(mlx->this, mlx->win);
		mlx->win = NULL;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_vars	vars;

	ft_bzero(&vars, sizeof(vars));
	if (argc == 1)
		return (ft_error("ARGS", strerror(22)));
	if (argc != 2)
		return (ft_error("ARGS", strerror(7)));
	if (!(ft_init_map(argv[1], &vars.map) && ft_init_mlx(&vars.mlx) && ft_init_image(vars.mlx, &vars.image)))
		return (ft_free_and_return(&vars, 1));
	mlx_loop_hook(vars.mlx->this, ft_render, &vars);
	mlx_hook(vars.mlx->win, 2, 1L<<0, ft_key_down, &vars);
	mlx_loop(vars.mlx->this);
	return (ft_free_and_return(&vars, 0));
}
