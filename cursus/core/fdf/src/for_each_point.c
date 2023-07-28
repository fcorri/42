/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_each_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:15:13 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/28 11:32:09 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

void	ft_VVV_for_each_point_of(t_vars *vars, t_vector3 (*op)(t_vector3 a, t_vector3 b), t_vector3 v)
{
	int			row;
	int			col;
	t_point	**matrix;

	row = vars->map->dim.x;
	matrix = vars->camera->matrix;
	while (--row >= 0)
	{
		col = vars->map->dim.y;
		while (--col >= 0)
			matrix[row][col].v = op(matrix[row][col].v, v);
	}
}

void	ft_VVS_for_each_point_of(t_vars *vars, t_vector3 (*op)(t_vector3 a, int k), int k)
{
	int			row;
	int			col;
	t_point		**matrix;

	row = vars->map->dim.x;
	matrix = vars->camera->matrix;
	while (--row >= 0)
	{
		col = vars->map->dim.y;
		while (--col >= 0)
			matrix[row][col].v = op(matrix[row][col].v, k);
	}
}

void	ft_VVQ_for_each_point_of(t_vars *vars, t_vector3 (*op)(t_vector3 point, t_vector3 axis, float deg), t_vector3 axis, float deg)
{
	int			row;
	int			col;
	t_point		**matrix;

	row = vars->map->dim.x;
	matrix = vars->camera->matrix;
	while (--row >= 0)
	{
		col = vars->map->dim.y;
		while (--col >= 0)
			matrix[row][col].v = op(matrix[row][col].v, axis, deg);
	}
}
