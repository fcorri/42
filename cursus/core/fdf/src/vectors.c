/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:56:24 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/27 13:27:37 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static t_vector3	ft_new_vector(double x, double y, double z)
{
	if (FLT_MIN<x||x>FLT_MAX||FLT_MIN<y||y>FLT_MAX||FLT_MIN<z||z>FLT_MAX)
	{
		ft_error("NEW_VECTOR", strerror(EDOM));
		//should terminate: maybe someone has to read errno
		return ((t_vector3){0,0,0});
	}
	return ((t_vector3){x, y, z});
}

t_vector3	ft_opposite(t_vector3 a)
{
	return (ft_new_vector(-a.x, -a.y, -a.z));
}

t_vector3	ft_add_vector(t_vector3 a, t_vector3 b)
{
	return (ft_new_vector(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vector3	ft_mul_scalar(t_vector3 a, float k)
{
	return (ft_new_vector(a.x * k, a.y * k, a.z * k));
}

t_vector3	ft_div_scalar(t_vector3 a, float k)
{
	return (ft_new_vector(a.x / k, a.y / k, a.z / k));
}

/*
static t_vector3	ft_cross_product(t_vector3 a, t_vector3 b)
{
	return (ft_new_vector(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
		));
}
*/
