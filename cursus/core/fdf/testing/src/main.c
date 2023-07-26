/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:48:17 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/26 11:52:07 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

typedef struct quaternion
{
	int	a;
	int	b;
	int	c;
	int	d;
}	t_quaternion;

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
	t_quaternion	result = ft_mul_quat(
		(t_quaternion){2, -1, 3, 1},
		(t_quaternion){5, -4, 0, 1}
	);
	ft_printf("q1 x q2:\t[%d, %d, %d, %d]\n", result.a, result.b, result.c, result.d);
	return (0);
}
