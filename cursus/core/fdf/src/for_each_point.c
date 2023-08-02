/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_each_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:15:13 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/02 17:01:46 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

void	ft_vvv_for_each_point_of(t_vars *vars, t_v3 (*op)(t_v3 a, t_v3 b), \
	t_v3 v)
{
	int	row;
	int	col;
	t_p	**matrix;

	row = vars->map->dim.x;
	matrix = vars->camera->matrix;
	while (--row >= 0)
	{
		col = vars->map->dim.y;
		while (--col >= 0)
			matrix[row][col].v = op(matrix[row][col].v, v);
	}
}

void	ft_vvs_for_each_point_of(t_vars *vars, t_v3 (*op)(t_v3 a, int k), int k)
{
	int	row;
	int	col;
	t_p	**matrix;

	row = vars->map->dim.x;
	matrix = vars->camera->matrix;
	while (--row >= 0)
	{
		col = vars->map->dim.y;
		while (--col >= 0)
			matrix[row][col].v = op(matrix[row][col].v, k);
	}
}

void	ft_vvq_for_each_point_of(t_vars *vars, t_v3 (*op)(t_v3 point, \
	t_v3 axis, float deg), t_v3 axis, float deg)
{
	int	row;
	int	col;
	t_p	**matrix;

	row = vars->map->dim.x;
	matrix = vars->camera->matrix;
	while (--row >= 0)
	{
		col = vars->map->dim.y;
		while (--col >= 0)
			matrix[row][col].v = op(matrix[row][col].v, axis, deg);
	}
}
