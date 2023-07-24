/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:31:42 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/20 16:54:09 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static void	ft_to_origin(t_map *map)
{
	ft_translate(map, ft_opposite(map->matrix[0][0]));
}

static void	ft_VV_for_each_point_of(t_map *map, t_vector (*op)(t_vector a, t_vector b), t_vector v)
{
	int			row;
	int			col;
	t_vector	**matrix;

	row = map->dim.x;
	matrix = map->matrix;
	while (--row >= 0)
	{
		col = map->dim.y;
		while (--col >= 0)
			matrix[row][col] = op(matrix[row][col], v);
	}
}

static void	ft_MV_for_each_point_of(t_map *map, t_vector (*op)(t_vector a, float k), float k)
{
	int			row;
	int			col;
	t_vector	**matrix;

	row = map->dim.x;
	matrix = map->matrix;
	while (--row >= 0)
	{
		col = map->dim.y;
		while (--col >= 0)
		{
			matrix[row][col] = op(matrix[row][col], k);
			ft_printf("matrix[%d][%d]\t{%d,%d,%d}\n", row, col, matrix[row][col].x, matrix[row][col].y, matrix[row][col].z);
		}
	}
}

void	ft_translate(t_map *map, t_vector vector)
{
	ft_VV_for_each_point_of(map, ft_add_vector, vector);
}

void	ft_zoom(t_map *map, int on)
{
	ft_to_origin(map);
	if (on)
		ft_MV_for_each_point_of(map, ft_mul_scalar, DEF_ZOOM);
	else
		ft_MV_for_each_point_of(map, ft_div_scalar, DEF_ZOOM);
	ft_to_center(map);
}

void	ft_to_center(t_map *map)
{
	int	b;
	int	h;

	b = map->matrix[0][map->dim.y - 1].x - map->matrix[0][0].x;
	h = map->matrix[map->dim.x - 1][0].y - map->matrix[0][0].y;
	ft_VV_for_each_point_of(map, ft_add_vector, ft_add_vector(ft_opposite(map->matrix[0][0]), (t_vector){(WIDTH - b) / 2, (HEIGHT - h) / 2, 0}));
}
