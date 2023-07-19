/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:49:29 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/19 12:43:47 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

void	ft_rot_x_cw(t_vars *vars)
{
	static double	sin_a;
	static double	cos_a;
	t_matrix		rot;
	int				tmp;

	if (sin_a == 0)
	{
		sin_a = sin(DEF_ROT);
		cos_a = cos(DEF_ROT);
	}
	rot = vars->map->rot;
	tmp = cos_a * rot.y - sin_a * rot.z;
	rot.z = sin_a * rot.y + cos_a * rot.z;
	rot.y = tmp;
	vars->map->rot = rot;
}

void	ft_rot_y_cw(t_vars *vars)
{
	static double	sin_a;
	static double	cos_a;
	t_matrix		rot;
	int				tmp;

	if (sin_a == 0)
	{
		sin_a = sin(DEF_ROT);
		cos_a = cos(DEF_ROT);
	}
	rot = vars->map->rot;
	tmp = cos_a * rot.x - sin_a * rot.z;
	rot.z = -1 * sin_a * rot.x + cos_a * rot.z;
	rot.x = tmp;
	vars->map->rot = rot;
}

void	ft_rot_z_cw(t_vars *vars)
{
	static double	sin_a;
	static double	cos_a;
	t_matrix		rot;
	int				tmp;

	if (sin_a == 0)
	{
		sin_a = sin(DEF_ROT);
		cos_a = cos(DEF_ROT);
	}
	rot = vars->map->rot;
	tmp = cos_a * rot.x - sin_a * rot.y;
	rot.y = sin_a * rot.x + cos_a * rot.y;
	rot.x = tmp;
	vars->map->rot = rot;
}
