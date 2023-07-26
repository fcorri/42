/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_each_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:15:13 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/25 18:36:28 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

void	ft_VVV_for_each_point_of(t_vars *vars, t_vector (*op)(t_vector a, t_vector b), t_vector v)
{
	int			row;
	int			col;
	t_vector	**matrix;

	row = vars->map->dim.x;
	matrix = vars->camera->matrix;
	while (--row >= 0)
	{
		col = vars->map->dim.y;
		while (--col >= 0)
			matrix[row][col] = op(matrix[row][col], v);
	}
}

void	ft_VVS_for_each_point_of(t_vars *vars, t_vector (*op)(t_vector a, int k), int k)
{
	int			row;
	int			col;
	t_vector	**matrix;

	row = vars->map->dim.x;
	matrix = vars->camera->matrix;
	while (--row >= 0)
	{
		col = vars->map->dim.y;
		while (--col >= 0)
			matrix[row][col] = op(matrix[row][col], k);
	}
}

void	ft_VVQ_for_each_point_of(t_vars *vars, t_vector (*op)(t_vector p, t_quaternion q), t_quaternion q)
{
	int			row;
	int			col;
	t_vector	**matrix;

	row = vars->map->dim.x;
	matrix = vars->camera->matrix;
	while (--row >= 0)
	{
		col = vars->map->dim.y;
		while (--col >= 0)
		{
			ft_printf("before:\t[%d, %d, %d]\n", row, col, matrix[row][col].z);
			matrix[row][col] = op(matrix[row][col], q);
			ft_printf("after:\t[%d, %d, %d]\n\n", row, col, matrix[row][col].z);
		}
	}
}
