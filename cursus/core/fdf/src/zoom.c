/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:56:45 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/03 13:54:00 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static t_v3	ft_mul_scalar_xy(t_v3 a, float k)
{
	return (ft_new_vector(a.x * k, a.y * k, a.z));
}

void	ft_zoom_on_xy(t_vars *vars, float value)
{
	ft_to_origin(vars);
	ft_vvs_for_each_point_of(vars, ft_mul_scalar_xy, value);
	ft_to_center(vars);
}

void	ft_zoom_on(t_vars *vars, float value)
{
	static t_v2	*zoom;

	if (!zoom)
		zoom = &vars->camera->zoom;
	ft_to_origin(vars);
	ft_vvs_for_each_point_of(vars, ft_mul_scalar, value);
	ft_to_center(vars);
	zoom->x++;
	zoom->y--;
}

void	ft_zoom_off(t_vars *vars, float value)
{
	static t_v2	*zoom;

	if (!zoom)
		zoom = &vars->camera->zoom;
	ft_to_origin(vars);
	ft_vvs_for_each_point_of(vars, ft_div_scalar, value);
	ft_to_center(vars);
	zoom->x--;
	zoom->y++;
}
