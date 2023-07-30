/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:32:16 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/30 18:55:51 by fcorri           ###   ########.fr       */
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

int	ft_abs(int number)
{
	if (number < 0)
		return (-number);
	return (number);
}

int	ft_max(int first, int second)
{
	if (first > second)
		return (first);
	return (second);
}

void	ft_print_map_matrix(t_vars *vars)
{
	int	row = 0;
	int	col = 0;

	while (col < vars->map->dim.y)
		ft_printf("\t%d", col++);
	ft_printf("\n");
	while (row < vars->map->dim.x)
	{
		col = 0;
		ft_printf("%d", row);
		while (col++ < vars->map->dim.y)
			ft_printf("\t%d", (int)vars->map->matrix[row][col]);
		ft_printf("\n");
		row++;
	}
	ft_printf("\n\n");
}

void	ft_print_camera_matrix(t_vars *vars)
{
	int	row = 0;
	int	col = 0;

	while (col < vars->map->dim.y)
		ft_printf("\t%d", col++);
	ft_printf("\n");
	while (row < vars->map->dim.x)
	{
		col = 0;
		ft_printf("%d", row);
		while (col++ < vars->map->dim.y)
			ft_printf("\t%d", (int)vars->camera->matrix[row][col].v.z);
		ft_printf("\n");
		row++;
	}
	ft_printf("\n\n");
}
