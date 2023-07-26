/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:31:42 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/25 17:29:43 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static void	ft_to_origin(t_vars *vars)
{
	ft_translate(vars, ft_opposite(vars->camera->matrix[0][0]));
}

void	ft_translate(t_vars *vars, t_vector vector)
{
	ft_VVV_for_each_point_of(vars, ft_add_vector, vector);
}

void ft_zoom_on(t_vars *vars, int value)
{
	t_vector	v;

	v = vars->camera->matrix[0][0];
	ft_to_origin(vars);
	ft_VVS_for_each_point_of(vars, ft_mul_scalarXY, value);
	ft_translate(vars, v);
}

void ft_zoom_off(t_vars *vars, int value)
{
	t_vector	v;

	v = vars->camera->matrix[0][0];
	ft_to_origin(vars);
	ft_VVS_for_each_point_of(vars, ft_div_scalarXY, value);
	ft_translate(vars, v);
}

void	ft_to_center(t_vars *vars)
{
	int	b;
	int	h;
	t_camera *camera;

	camera = vars->camera;
	b = camera->matrix[0][vars->map->dim.y - 1].x - camera->matrix[0][0].x;
	h = camera->matrix[vars->map->dim.x - 1][0].y - camera->matrix[0][0].y;
	ft_VVV_for_each_point_of(vars, ft_add_vector, ft_add_vector(ft_opposite(camera->matrix[0][0]), (t_vector){(WIDTH - b) / 2, (HEIGHT - h) / 2, 0}));
}
