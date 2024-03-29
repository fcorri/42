/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ccw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:49:29 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/03 11:00:36 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

void	ft_rot_x_ccw(t_vars *vars)
{
	ft_rot(vars, (t_v3){-1, 0, 0}, DEF_ANG);
}

void	ft_rot_y_ccw(t_vars *vars)
{
	ft_rot(vars, (t_v3){0, -1, 0}, DEF_ANG);
}

void	ft_rot_z_ccw(t_vars *vars)
{
	ft_rot(vars, (t_v3){0, 0, -1}, DEF_ANG);
}
