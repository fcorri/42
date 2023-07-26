/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:47:40 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/26 11:41:16 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static void	ft_free_map_and_matrices(t_vars *vars)
{
	int		index;
	void	*matrix;

	index = vars->map->dim.x;
	matrix = vars->map->matrix;
	if (matrix)
	{
		while (index)
			free(((int **)matrix)[--index]);
		free(matrix);
	}
	if (vars->camera)
	{
		index = vars->map->dim.x;
		matrix = vars->camera->matrix;
		if (matrix)
		{
			while (index)
				free(((t_vector **)matrix)[--index]);
			free(matrix);
		}
		free(vars->camera);
	}
	free(vars->map);
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
		ft_free_map_and_matrices(vars);
	return (value);
}

static int	ft_render(t_vars *vars)
{
	int	output;

	if (!vars->camera->draw)
		return (1);
	ft_bzero(vars->image->addr, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(vars->mlx->this, vars->mlx->win, vars->image->this, 0, 0);
	output = vars->camera->ft_draw(vars);
	ft_draw_legend(vars);
	vars->camera->draw = 0;
	return (output);
}

static int	ft_key_down(int keycode, t_vars *vars)
{
	if (keycode == XK_Left)
		ft_translate(vars, LEFT);
	else if (keycode == XK_Up)
		ft_translate(vars, UP);
	else if (keycode == XK_Right)
		ft_translate(vars, RIGHT);
	else if (keycode == XK_Down)
		ft_translate(vars, DOWN);
	else if (keycode == XK_KP_Add || keycode == 43)
		ft_zoom_on(vars, DEF_ZOOM);
	else if (keycode == XK_KP_Subtract || keycode == 45)
		ft_zoom_off(vars, DEF_ZOOM);
	else if (keycode == XK_c)
		ft_to_center(vars);
	else if (keycode == XK_x)
		ft_rot_x_cw(vars);
	else if (keycode == XK_y)
		ft_rot_y_cw(vars);
	else if (keycode == XK_z)
		ft_rot_z_cw(vars);
	else if (keycode == XK_X)
		ft_rot_x_ccw(vars);
	else if (keycode == XK_Y)
		ft_rot_y_ccw(vars);
	else if (keycode == XK_Z)
		ft_rot_z_ccw(vars);
	else if (keycode == XK_o || keycode == XK_O)
		ft_set_camera(vars, ft_draw_map_as_orthogonal_projection, "ORTHOGONAL PROJECTION");
	else if (keycode == XK_i || keycode == XK_I)
		ft_set_camera(vars, ft_draw_map_as_isometric_projection, "ISOMETRIC PROJECTION");
	else if (keycode == XK_Escape)
		return (mlx_loop_end(vars->mlx->this));
	else
		return (1);
	vars->camera->draw = 1;
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
	if (!(ft_init_map(argv[1], &vars.map) && ft_init_camera(&vars) && ft_init_mlx(&vars.mlx) && ft_init_image(vars.mlx, &vars.image)))
		return (ft_free_and_return(&vars, 1));
	mlx_hook(vars.mlx->win, 2, 1L<<0, ft_key_down, &vars);
	ft_render(&vars);
	mlx_loop(vars.mlx->this);
	return (ft_free_and_return(&vars, 0));
}
