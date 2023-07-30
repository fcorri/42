/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:56:24 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/29 01:52:59 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

t_vector3	ft_new_vector(double x, double y, double z)
{
	if (x<-FLT_MAX||x>FLT_MAX||y<-FLT_MAX||y>FLT_MAX||z<-FLT_MAX||z>FLT_MAX)
		ft_error("NEW_VECTOR", strerror(EDOM));
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
