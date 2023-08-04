/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:48:18 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/04 18:56:23 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static t_camera	*ft_alloc_camera_matrix(t_p ***p_matrix, t_v2 dim)
{
	t_camera	*camera;
	t_p			**matrix;

	camera = ft_malloc_soul(sizeof(t_camera));
	if (!camera)
		return (ft_null_error("CAMERA MALLOC", strerror(errno)));
	matrix = ft_malloc_soul(sizeof(t_p *) * dim.x);
	if (!matrix)
		return (ft_null_error("CAMERA MATRIX MALLOC", strerror(errno)));
	while (dim.x--)
	{
		matrix[dim.x] = ft_malloc_soul(sizeof(t_p) * dim.y);
		if (!matrix[dim.x])
			return (ft_null_error("CAMERA MATRIX[i] MALLOC", strerror(errno)));
	}
	*p_matrix = matrix;
	camera->matrix = matrix;
	return (camera);
}

static int	ft_init_camera_continue(t_camera *camera)
{
	camera->zoom = (t_v2){5, 5};
	camera->name = "ISOMETRIC PROJECTION";
	camera->ft_view = ft_isometric;
	return (1);
}

int	ft_init_camera(t_vars *vars)
{
	t_map	*map;
	t_v2	dim;
	int		n;
	t_v2	**m_matrix;
	t_p		**c_matrix;

	map = vars->map;
	dim = map->dim;
	n = map->min_max.y - map->min_max.x;
	m_matrix = map->matrix;
	vars->camera = ft_alloc_camera_matrix(&c_matrix, dim);
	while (dim.x--)
	{
		dim.y = map->dim.y;
		while (dim.y--)
		{
			if (!m_matrix[dim.x][dim.y].y)
				c_matrix[dim.x][dim.y].color = \
					ft_interpolate_colors(S, E, m_matrix[dim.x][dim.y].x, n);
			else
				c_matrix[dim.x][dim.y].color = m_matrix[dim.x][dim.y].y;
		}
	}
	return (ft_init_camera_continue(vars->camera));
}

int	ft_restore_camera(t_vars *vars)
{
	int		z;
	t_map	*map;
	t_v2	dim;
	t_v2	**m_matrix;
	t_p		**c_matrix;

	map = vars->map;
	dim = map->dim;
	m_matrix = map->matrix;
	c_matrix = vars->camera->matrix;
	while (dim.x--)
	{
		dim.y = map->dim.y;
		while (dim.y--)
		{
			z = m_matrix[dim.x][dim.y].x;
			c_matrix[dim.x][dim.y].v = (t_v3){dim.y, dim.x, z};
		}
	}
	ft_zoom_on_xy(vars, 20);
	vars->camera->zoom = (t_v2){5, 5};
	return (1);
}

void	ft_set_camera(t_vars *vars, void (*ft_view)(t_vars *vars), char *name)
{
	if (vars->camera->ft_view == ft_view)
		return ;
	ft_view(vars);
	vars->camera->ft_view = ft_view;
	vars->camera->name = name;
}
