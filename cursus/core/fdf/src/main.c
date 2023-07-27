/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:47:40 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/27 14:54:34 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static int	ft_key_down(int keycode, t_vars *vars)
{
	ft_printf("keycode: %d\n", keycode);
	if (keycode == XK_Left)
		ft_translate(vars, LEFT);
	else if (keycode == XK_Up)
		ft_translate(vars, UP);
	else if (keycode == XK_Right)
		ft_translate(vars, RIGHT);
	else if (keycode == XK_Down)
		ft_translate(vars, DOWN);
	else if (keycode == XK_KP_Add)
		ft_zoom_on(vars, DEF_ZOOM);
	else if (keycode == XK_KP_Subtract)
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
		ft_set_camera(vars, ft_render_orthogonal, "ORTHOGONAL PROJECTION");
	else if (keycode == XK_i || keycode == XK_I)
		ft_set_camera(vars, ft_render_isometric, "ISOMETRIC PROJECTION");
	else if (keycode == XK_Escape)
		return (mlx_loop_end(vars->mlx->this));
	else
		return (1);
	vars->camera->render = 1;
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
	if (!ft_init_fdf(&vars, argv[1]))
		return (ft_free_and_return(&vars, 1));
	mlx_hook(vars.mlx->win, 2, 1L<<0, ft_key_down, &vars);
	ft_render(&vars);
	mlx_loop(vars.mlx->this);
	return (ft_free_and_return(&vars, 0));
}
