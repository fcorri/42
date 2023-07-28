/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:01:52 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/28 12:02:29 by fcorri           ###   ########.fr       */
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
		ft_set_render(vars, ft_render_orthogonal, "ORTHOGONAL PROJECTION");
	else if (keycode == XK_i || keycode == XK_I)
		ft_set_render(vars, ft_render_isometric, "ISOMETRIC PROJECTION");
	else if (keycode == XK_Escape)
		return (mlx_loop_end(vars->mlx->this));
	else
		return (1);
	vars->camera->render = 1;
	return (ft_render(vars));
}
