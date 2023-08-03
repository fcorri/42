/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:29:59 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/03 11:05:39 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static t_v3	ft_cross_product(t_v3 a, t_v3 b)
{
	return (ft_new_vector(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
		));
}

t_v3	ft_mul_quaternion(t_v3 v, t_v3 axis, float deg)
{
	float	rad;
	float	sin_a;
	t_v3	q;
	t_v3	tmp;

	rad = (deg / 180 * M_PI) / 2;
	sin_a = sin(rad);
	q = (t_v3){sin_a * axis.x, sin_a * axis.y, sin_a * axis.z};
	tmp = ft_mul_scalar(ft_cross_product(q, v), 2);
	return (ft_add_vector(v, ft_add_vector(ft_mul_scalar(tmp, cos(rad)), \
		ft_cross_product(q, tmp))));
}
