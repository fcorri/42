/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:13:21 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/31 16:49:29 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static int	ft_check_rot(int keycode, t_vars *vars, int caps_lock)
{
	if (keycode == XK_x && !caps_lock)
		ft_rot_x_cw(vars);
	else if (keycode == XK_y && !caps_lock)
		ft_rot_y_cw(vars);
	else if (keycode == XK_z && !caps_lock)
		ft_rot_z_cw(vars);
	else if (keycode == XK_x)
		ft_rot_x_ccw(vars);
	else if (keycode == XK_y)
		ft_rot_y_ccw(vars);
	else if (keycode == XK_z)
		ft_rot_z_ccw(vars);
	else
		return (1);
	return (ft_render(vars));
}

static int	ft_key_down_continue(int keycode, t_vars *vars)
{
	static int	caps_lock;

	if (keycode == XK_o)
		ft_set_camera(vars, ft_orthogonal, "ORTHOGONAL PROJECTION");
	else if (keycode == XK_i)
		ft_set_camera(vars, ft_isometric, "ISOMETRIC PROJECTION");
	else if (!caps_lock && keycode == XK_Caps_Lock)
		caps_lock = 1;
	else if (caps_lock && keycode == XK_Caps_Lock)
		caps_lock = 0;
	else
		return (ft_check_rot(keycode, vars, caps_lock));
	return (ft_render(vars));
}

int	ft_key_down(int keycode, t_vars *vars)
{
	static t_v2	*zoom;

	if (!zoom)
		zoom = &vars->camera->zoom;
	if (keycode == XK_Left)
		ft_translate(vars, (t_v3){-DEF_TR, 0, 0});
	else if (keycode == XK_Up)
		ft_translate(vars, (t_v3){0, -DEF_TR, 0});
	else if (keycode == XK_Right)
		ft_translate(vars, (t_v3){DEF_TR, 0, 0});
	else if (keycode == XK_Down)
		ft_translate(vars, (t_v3){0, DEF_TR, 0});
	else if ((keycode == XK_KP_Add || keycode == 43) && zoom->y > 1)
		ft_zoom_on(vars, DEF_ZOOM);
	else if ((keycode == XK_KP_Subtract || keycode == 45) && zoom->x > 1)
		ft_zoom_off(vars, DEF_ZOOM);
	else if (keycode == XK_r)
		vars->camera->ft_view(vars);
	else if (keycode == XK_c)
		ft_to_center(vars);
	else if (keycode == XK_Escape)
		return (mlx_loop_end(vars->mlx->this));
	else
		return (ft_key_down_continue(keycode, vars));
	return (ft_render(vars));
}

int	ft_close_window(t_vars *vars)
{
	mlx_loop_end(vars->mlx->this);
	return (1);
}
