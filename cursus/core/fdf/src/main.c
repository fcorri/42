/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:47:40 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/01 12:31:40 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

int	ft_key_down(int keycode, t_vars *vars)
{
	static int	caps_lock;

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
	else if (keycode == XK_r)
		vars->camera->ft_view(vars);
	else if (keycode == XK_c)
		ft_to_center(vars);
	else if (keycode == XK_o)
		ft_set_camera(vars, ft_orthogonal, "ORTHOGONAL PROJECTION");
	else if (keycode == XK_i)
		ft_set_camera(vars, ft_isometric, "ISOMETRIC PROJECTION");
	else if (keycode == XK_Escape)
		return (mlx_loop_end(vars->mlx->this));
	else if (!caps_lock && keycode == XK_Caps_Lock)
		caps_lock = 1;
	else if (caps_lock && keycode == XK_Caps_Lock)
		caps_lock = 0;
	else if (!caps_lock)
	{
		if (keycode == XK_x)
			ft_rot_x_cw(vars);
		else if (keycode == XK_y)
			ft_rot_y_cw(vars);
		else if (keycode == XK_z)
			ft_rot_z_cw(vars);
	}
	else if (caps_lock)
	{
		if (keycode == XK_x)
			ft_rot_x_ccw(vars);
		else if (keycode == XK_y)
			ft_rot_y_ccw(vars);
		else if (keycode == XK_z)
			ft_rot_z_ccw(vars);
	}
	else
		return (1);
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
	vars.camera->ft_view(&vars);
	ft_render(&vars);
	mlx_loop(vars.mlx->this);
	return (ft_free_and_return(&vars, 0));
}
