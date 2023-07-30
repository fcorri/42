/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:56:45 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/30 19:06:48 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static t_vector3	ft_mul_scalarXY(t_vector3 a, int k)
{
	return (ft_new_vector(a.x * k, a.y * k, a.z));
}

static t_vector3	ft_div_scalarXY(t_vector3 a, int k)
{
	return (ft_new_vector(a.x / k, a.y / k, a.z));
}

void ft_zoom_on(t_vars *vars, int value)
{
	ft_to_origin(vars);
	ft_VVS_for_each_point_of(vars, ft_mul_scalarXY, value);
	ft_to_center(vars);
}

void ft_zoom_off(t_vars *vars, int value)
{
	ft_to_origin(vars);
	ft_VVS_for_each_point_of(vars, ft_div_scalarXY, value);
	ft_to_center(vars);
}
