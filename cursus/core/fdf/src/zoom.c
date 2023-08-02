/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:56:45 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/02 17:06:07 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static t_v3	ft_mul_scalar_xy(t_v3 a, int k)
{
	return (ft_new_vector(a.x * k, a.y * k, a.z));
}

static t_v3	ft_div_scalar_xy(t_v3 a, int k)
{
	return (ft_new_vector(a.x / k, a.y / k, a.z));
}

void	ft_zoom_on(t_vars *vars, int value)
{
	if (vars->camera->zoom.y > 1)
	{
		ft_to_origin(vars);
		ft_vvs_for_each_point_of(vars, ft_mul_scalar_xy, value);
		ft_to_center(vars);
		vars->camera->zoom.x++;
		vars->camera->zoom.y--;
	}
}

void	ft_zoom_off(t_vars *vars, int value)
{
	if (vars->camera->zoom.x > 1)
	{
		ft_to_origin(vars);
		ft_vvs_for_each_point_of(vars, ft_div_scalar_xy, value);
		ft_to_center(vars);
		vars->camera->zoom.x--;
		vars->camera->zoom.y++;
	}
}
