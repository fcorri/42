/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:56:24 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/26 11:42:30 by fcorri           ###   ########.fr       */
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

t_vector	ft_mul_scalarXY(t_vector a, int k)
{
	return (ft_new_vector(a.x * k, a.y * k, a.z));
}

t_vector	ft_div_scalarXY(t_vector a, int k)
{
	int	x;
	int	y;

	if (a.x % k == 0 && a.y % k == 0)
	{
		x = a.x / k;
		y = a.y / k;
	}
	else
	{
		x = a.x;
		y = a.y;
	}
	return (ft_new_vector(x, y, a.z));
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
static t_vector	ft_cross_product(t_vector a, t_vector b)
{
	return (ft_new_vector(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
		));
}
*/
t_vector	ft_mul_quaternion(t_vector v, t_quaternion q)
{
	t_quaternion	tmp;

	tmp = ft_mul_quat(ft_mul_quat((t_quaternion){0, v.x, v.y, v.z}, q), (t_quaternion){q.a, q.b * -1, q.c * -1, q.d * -1});
	return ((t_vector){tmp.b, tmp.c, tmp.d});
}

t_quaternion	ft_mul_quat(t_quaternion q1, t_quaternion q2)
{
	return (
		(t_quaternion) {
			q1.a*q2.a - q1.b*q2.b - q1.c*q2.c - q1.d*q2.d,
			q1.a*q2.b + q1.b*q2.a - q1.c*q2.d - q1.d*q2.c,
			q1.a*q2.c - q1.b*q2.d + q1.c*q2.a + q1.d*q2.b,
			q1.a*q2.d + q1.b*q2.c - q1.c*q2.b + q1.d*q2.a
		});
/*
	t_vector	qv;
	t_vector	tmp;
	t_vector	output;

	qv = (t_vector){q.b, q.c, q.d};
	tmp = ft_mul_scalar(ft_cross_product(qv, v), 2);
	output = ft_cross_product(qv, tmp);
	output = ft_add_vector(ft_mul_scalar(tmp, q.a), output);
	return (ft_add_vector(v, output));
*/
}
