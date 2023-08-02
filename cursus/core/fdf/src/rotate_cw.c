/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:49:29 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/31 20:14:09 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

void	ft_rot(t_vars *vars, t_vector3 axis, float rad)
{
	static t_vector2	dim;
	t_vector3			v;
	t_vector3			opposite_v;
	
	if (dim.x == 0)
		dim = (t_vector2){vars->map->dim.x >> 1, vars->map->dim.y >> 1};
	v = vars->camera->matrix[dim.x][dim.y].v;
	opposite_v = ft_opposite(v);
	ft_translate(vars, opposite_v);
	ft_VVQ_for_each_point_of(vars, ft_mul_quaternion, axis, rad);
	ft_translate(vars, v);
}

void	ft_rot_x_cw(t_vars *vars)
{
	ft_rot(vars, (t_vector3){1, 0, 0}, DEF_ANG);
}

void	ft_rot_y_cw(t_vars *vars)
{
	ft_rot(vars, (t_vector3){0, 1, 0}, DEF_ANG);
}

void	ft_rot_z_cw(t_vars *vars)
{
	ft_rot(vars, (t_vector3){0, 0, 1}, DEF_ANG);
}
