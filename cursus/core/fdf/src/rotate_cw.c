/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:49:29 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/25 18:44:17 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

void	ft_rot_x_cw(t_vars *vars)
{
	static double	cos_a = cos(DEF_ANG / 2);
	t_vector		v;

	v = vars->camera->matrix[0][0];
	ft_translate(vars, ft_opposite(v));
	ft_VVQ_for_each_point_of(vars, ft_mul_quaternion, (t_quaternion){cos_a, 1, 0, 0});
	ft_translate(vars, v);
}

void	ft_rot_y_cw(t_vars *vars)
{
	(void) vars;
}

void	ft_rot_z_cw(t_vars *vars)
{
	(void) vars;
}
