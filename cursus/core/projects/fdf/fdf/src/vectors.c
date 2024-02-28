/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:56:24 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/04 12:30:57 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

t_v3	ft_new_vector(float x, float y, float z)
{
	return ((t_v3){x, y, z});
}

t_v3	ft_opposite(t_v3 a)
{
	return (ft_new_vector(-a.x, -a.y, -a.z));
}

t_v3	ft_add_vector(t_v3 a, t_v3 b)
{
	return (ft_new_vector(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_v3	ft_mul_scalar(t_v3 a, float k)
{
	return (ft_new_vector(a.x * k, a.y * k, a.z * k));
}

t_v3	ft_div_scalar(t_v3 a, float k)
{
	return (ft_new_vector(a.x / k, a.y / k, a.z / k));
}
