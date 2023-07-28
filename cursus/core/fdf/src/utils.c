/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:32:16 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/28 13:16:08 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"
#include <stdio.h>

int	ft_error(char *callee, char *with_message)
{
	ft_printf("ERROR %s: %s\n", callee, with_message);
	return (0);
}

void	ft_swap(int *first, int *second)
{
	int	tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

void	ft_print_matrix(t_vars *vars)
{
	t_point		**matrix;
	t_vector3	p;
	t_vector2	x_y;
	t_vector2	dim;
	
	matrix = vars->camera->matrix;
	x_y = (t_vector2){0, 0};
	dim = vars->map->dim;
	while (x_y.x != dim.x)
	{
		x_y.y = 0;
		while (x_y.y != dim.y)
		{
			p = matrix[x_y.x][x_y.y].v;
			printf("[%f, %f, %f] ", p.x, p.y, p.z);
			x_y.y++;
		}
		printf("\n");
		x_y.x++;
	}
	printf("\n");
}
