/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:56:24 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/20 12:02:13 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static t_vector	ft_new_vector(long x, long y, long z)
{
	if (x > INT_MAX || y > INT_MAX || z > INT_MAX)
	{
		ft_error("NEW_VECTOR", strerror(EDOM));
		return ((t_vector){0,0,0});
	}
	return ((t_vector){x, y, z});
}

t_vector	ft_opposite(t_vector a)
{
	return (ft_new_vector(a.x * - 1, a.y * - 1, a.z * -1));
}

t_vector	ft_add_vector(t_vector a, t_vector b)
{
	return (ft_new_vector(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vector	ft_sub_vector(t_vector a, t_vector b)
{
	return (ft_new_vector(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_vector	ft_mul_scalar(t_vector a, float k)
{
	return (ft_new_vector(a.x * k, a.y * k, a.z * k));
}

t_vector	ft_div_scalar(t_vector a, float k)
{
	return (ft_new_vector(a.x / k, a.y / k, a.z / k));
}

static int	ft_dot_product(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector	ft_mul_row_col(t_matrix matrix, t_vector vector)
{
	return (ft_new_vector(ft_dot_product(matrix.x, vector), ft_dot_product(matrix.y, vector), ft_dot_product(matrix.z, vector)));
}

/*
t_vector	*ft_cross_product(t_vector a, t_vector b)
{
	return (ft_new_vector(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
		));
}*/
