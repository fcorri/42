/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:49:29 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/31 10:23:24 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

void	ft_rot(t_vars *vars, t_vector3 axis)
{
	static t_vector3	v;
	static t_vector3	opposite_v;
	static int			first;
	
	if (!first)
	{
		v = vars->camera->matrix[vars->map->dim.x / 2][vars->map->dim.y / 2].v;
		opposite_v = ft_opposite(v);
		first = 1;
	}
	ft_translate(vars, opposite_v);
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
