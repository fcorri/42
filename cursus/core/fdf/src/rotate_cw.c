/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:49:29 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/26 19:57:48 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static	void	ft_rot(t_vars *vars, t_vector3 axis)
{
	t_vector3		v;

	v = vars->camera->matrix[0][0].v;
	ft_translate(vars, ft_opposite(v));
	ft_VVQ_for_each_point_of(vars, ft_mul_quaternion, axis, DEF_ANG);
	ft_translate(vars, v);
}

void	ft_rot_x_cw(t_vars *vars)
{
	ft_rot(vars, (t_vector3){1, 0, 0});
}

void	ft_rot_y_cw(t_vars *vars)
{
	ft_rot(vars, (t_vector3){0, 1, 0});
}

void	ft_rot_z_cw(t_vars *vars)
{
	ft_rot(vars, (t_vector3){0, 0, 1});
}
