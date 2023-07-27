/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:29:59 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/27 13:22:44 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static t_quaternion	ft_coniugate(t_quaternion q)
{
	return (
		(t_quaternion){q.a, q.b * -1, q.c * -1, q.d * -1}
	);
}

static double	ft_magnitude(t_vector3 a)
{
	return (
		sqrt(a.x * a.x + a.y * a.y + a.z * a.z)
	);
}

static t_quaternion ft_mul_quat(t_quaternion q1, t_quaternion q2)
{
	return (
		(t_quaternion) {
			q1.a*q2.a - q1.b*q2.b - q1.c*q2.c - q1.d*q2.d,
			q1.a*q2.b + q1.b*q2.a + q1.c*q2.d - q1.d*q2.c,
			q1.a*q2.c - q1.b*q2.d + q1.c*q2.a + q1.d*q2.b,
			q1.a*q2.d + q1.b*q2.c - q1.c*q2.b + q1.d*q2.a
		});
/*
	t_vector3	qv;
	t_vector3	tmp;
	t_vector3	output;

	qv = (t_vector3){q.b, q.c, q.d};
	tmp = ft_mul_scalar(ft_cross_product(qv, v), 2);
	output = ft_cross_product(qv, tmp);
	output = ft_add_vector(ft_mul_scalar(tmp, q.a), output);
	return (ft_add_vector(v, output));
*/
}

t_vector3	ft_mul_quaternion(t_vector3 point, t_vector3 axis, double deg)
{
	t_quaternion q, p, output;
	double	rad;

	rad = deg / 180 * M_PI;
	axis = ft_div_scalar(axis, ft_magnitude(axis));
	q = (t_quaternion){cos(rad / 2), sin(rad / 2) * axis.x, sin(rad/2) * axis.y, sin(rad / 2) * axis.z};
	p = (t_quaternion){0, point.x, point.y, point.z};

	output = ft_mul_quat(
		ft_mul_quat(
			q,
			p
		),
		ft_coniugate(q)
	);

	return ((t_vector3){output.b, output.c, output.d});
}
