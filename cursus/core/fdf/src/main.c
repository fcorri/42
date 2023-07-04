/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:47:40 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/04 18:22:23 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static void	ft_free_map_and_matrices(t_map *map)
{
	int	index;
	int	**matrix;

	index = map->dim.x;
	matrix = map->origin;
	if (matrix)
	{
		while (index)
			free(matrix[--index]);
		free(matrix);
	}
/*
	index = map->dim.x;
	matrix = map->print;
	if (matrix)
	{
		while (index)
			free(matrix[--index]);
		free(matrix);
	}
*/
	free(map);
}

static int	ft_free_and_return(t_vars *vars, int value)
{
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
	if (vars->map)
		ft_free_map_and_matrices(vars->map);
	return (value);
}

static int	ft_render(t_vars *vars)
{
	int	output;

	if (!vars->map->draw)
		return (1);
	ft_bzero(vars->image->addr, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(vars->mlx->this, vars->mlx->win, vars->image->this, 0, 0);
	output = vars->map->ft_draw(vars);
	ft_draw_legend(vars);
	vars->map->draw = 0;
	return (output);
}

static int	ft_key_down(int keycode, t_vars *vars)
{
	if (keycode == XK_Left)
		vars->map->tr.x -= 1;
	else if (keycode == XK_Up)
		vars->map->tr.y -= 1;
	else if (keycode == XK_Right)
		vars->map->tr.x += 1;
	else if (keycode == XK_Down)
		vars->map->tr.y += 1;
	else if (keycode == XK_KP_Add)
		ft_zoom_on(vars, 2);
	else if (keycode == XK_KP_Subtract)
		ft_zoom_off(vars, 2);
	else if (keycode == XK_o || keycode == XK_O)
		ft_set_map(vars, ft_draw_map_as_orthogonal_projection, "ORTHOGONAL PROJECTION");
	else if (keycode == XK_i || keycode == XK_I)
		ft_set_map(vars, ft_draw_map_as_isometric_projection, "ISOMETRIC PROJECTION");
	else if (keycode == XK_Escape)
		return (mlx_loop_end(vars->mlx->this));
	else
		return (1);
	vars->map->draw = 1;
	return (ft_render(vars));
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
	mlx_hook(vars.mlx->win, 2, 1L<<0, ft_key_down, &vars);
	ft_render(&vars);
	mlx_loop(vars.mlx->this);
	return (ft_free_and_return(&vars, 0));
}
