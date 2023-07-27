/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:50:01 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/27 15:07:12 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

int	ft_alloc_map_matrix(int ***p_matrix, t_vector2 dim)
{
	int	**matrix;
	int	i;

	matrix = ft_malloc_soul(sizeof(int *) * dim.x);
	if (!matrix)
		return (ft_error("MAP MATRIX MALLOC", strerror(errno)));
	i = 0;
	while (i < dim.x)
	{
		matrix[i] = ft_malloc_soul(sizeof(int) * dim.y);
		if (!matrix[i])
			return (ft_error("MAP MATRIX[i] MALLOC", strerror(errno)));
		i++;
	}
	*p_matrix = matrix;
	return (1);
}

int	ft_alloc_camera_matrix(int ***p_matrix, t_vector2 dim)
{
	t_point	**matrix;

	matrix = ft_malloc_soul(sizeof(t_point *) * dim.x);
	if (!matrix)
		return (ft_error("CAMERA MATRIX MALLOC", strerror(errno)));
	while (dim.x-- > 0)
	{
		matrix[dim.x] = ft_malloc_soul(sizeof(t_point) * dim.y);
		if (!matrix[dim.x])
			return (ft_error("CAMERA MATRIX[i] MALLOC", strerror(errno)));
	}
	*p_matrix = matrix;
	return (1);
}
