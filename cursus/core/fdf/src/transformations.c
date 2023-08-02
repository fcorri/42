/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:31:42 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/02 15:43:24 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

void	ft_translate(t_vars *vars, t_vector3 vector)
{
	ft_VVV_for_each_point_of(vars, ft_add_vector, vector);
}

void	ft_to_center(t_vars *vars)
{
	ft_to_origin(vars);
	ft_VVV_for_each_point_of(vars, ft_add_vector, (t_vector3){WIDTH >> 1, HEIGHT >> 1, 0});
}

void	ft_to_origin(t_vars *vars)
{
	static t_vector2	dim;

	if (dim.x == 0)
	{
		dim = vars->map->dim;
		dim.x >>= 1;
		dim.y >>= 1;
	}
	ft_translate(vars, ft_opposite(vars->camera->matrix[dim.x][dim.y].v));
}
