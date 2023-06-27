/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:47:40 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/27 23:06:32 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

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
	return (vars->map->ft_draw(vars));
}

static int	ft_key_down(int keycode, t_vars *vars)
{
	t_mlx	*mlx;

	mlx = vars->mlx;
	if (keycode == XK_v || keycode == XK_V)
	{
//		if (!ft_clear_image_and_set_ft_draw(vars, ft_draw_map_as_vertical_projection))
			mlx->win = NULL;
	}
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
