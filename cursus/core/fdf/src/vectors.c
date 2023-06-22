/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:56:24 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/22 17:55:45 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

t_vector	*ft_new_vector(long x, long y, long z)
{
	t_vector	*output;

	if (x > INT_MAX || y > INT_MAX || z > INT_MAX)
		return (NULL);
	output = ft_malloc_soul(sizeof(t_vector));
	output->x = x;
	output->y = y;
	output->z = z;
	return (output);
}

t_vector	*ft_add_vector(t_vector a, t_vector b)
{
	return (ft_new_vector(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vector	*ft_mul_scalar(t_vector a, int k)
{
	return (ft_new_vector(a.x * k, a.y * k, a.z * k));
}

/*int	ft_dot_product(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector	*ft_cross_product(t_vector a, t_vector b)
{
	return (ft_new_vector(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
		));
}*/
