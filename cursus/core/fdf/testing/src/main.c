/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:48:17 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/26 18:15:22 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

typedef struct vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct quaternion
{
	double	a;
	double	b;
	double	c;
	double	d;
}	t_quaternion;

t_quaternion ft_mul_quat(t_quaternion q1, t_quaternion q2);

t_quaternion	ft_coniugate(t_quaternion q)
{
	return (
		(t_quaternion){q.a, q.b * -1, q.c * -1, q.d * -1}
	);
}

t_vector	ft_div_scalar(t_vector a, double s)
{
	return (
		(t_vector){a.x / s, a.y / s, a.z / s}
	);
}

double	ft_magnitude(t_vector a)
{
	return (
		sqrt(a.x * a.x + a.y * a.y + a.z * a.z)
	);
}

t_vector	ft_mul_quaternion(t_vector point, t_vector axis, double deg)
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

	return ((t_vector){output.b, output.c, output.d});
}

t_quaternion ft_mul_quat(t_quaternion q1, t_quaternion q2)
{
	return (
		(t_quaternion) {
			q1.a*q2.a - q1.b*q2.b - q1.c*q2.c - q1.d*q2.d,
			q1.a*q2.b + q1.b*q2.a + q1.c*q2.d - q1.d*q2.c,
			q1.a*q2.c - q1.b*q2.d + q1.c*q2.a + q1.d*q2.b,
			q1.a*q2.d + q1.b*q2.c - q1.c*q2.b + q1.d*q2.a
		});
}

int main(void)
{
	t_vector	result = ft_mul_quaternion(
		(t_vector){2, 3, 5},
		(t_vector){1, 0, 0},
		60
	);
	printf("{2,3,5} rotated by 60 degress around {1,0,0} axis:\t[%f, %f, %f]\n", result.x, result.y, result.z);
	printf("%f\n", 5.5 / 5);
	return (0);
}
