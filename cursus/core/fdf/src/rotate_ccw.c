/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ccw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:49:29 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/26 16:11:41 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static	void	ft_rot(t_vars *vars, t_vector3 axis)
{
	ft_VVQ_for_each_point_of(vars, ft_mul_quaternion, axis, -1 * DEF_ANG);
}

void	ft_rot_x_ccw(t_vars *vars)
{
	ft_rot(vars, (t_vector3){1, 0, 0});
}

void	ft_rot_y_ccw(t_vars *vars)
{
	ft_rot(vars, (t_vector3){0, 1, 0});
}

void	ft_rot_z_ccw(t_vars *vars)
{
	ft_rot(vars, (t_vector3){0, 0, 1});
}
