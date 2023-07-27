/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traslations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:31:42 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/27 13:00:26 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

void	ft_translate(t_vars *vars, t_vector3 vector)
{
	ft_VVV_for_each_point_of(vars, ft_add_vector, vector);
}

void	ft_to_center(t_vars *vars)
{
	int	b;
	int	h;
	t_camera *camera;

	camera = vars->camera;
	b = camera->matrix[0][vars->map->dim.y - 1].v.x - camera->matrix[0][0].v.x;
	h = camera->matrix[vars->map->dim.x - 1][0].v.y - camera->matrix[0][0].v.y;
	ft_VVV_for_each_point_of(vars, ft_add_vector, ft_add_vector(ft_opposite(camera->matrix[0][0].v), (t_vector3){(WIDTH - b) / 2, (HEIGHT - h) / 2, 0}));
}

void	ft_to_origin(t_vars *vars)
{
	ft_translate(vars, ft_opposite(vars->camera->matrix[0][0].v));
}
