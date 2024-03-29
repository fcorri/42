/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:32:16 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/04 18:12:29 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"
#include <stdio.h>

int	ft_error(char *callee, char *with_message)
{
	ft_printf("ERROR %s: %s\n", callee, with_message);
	return (0);
}

void	*ft_null_error(char *callee, char *with_message)
{
	ft_printf("ERROR %s: %s\n", callee, with_message);
	return (NULL);
}

void	ft_swap(int *first, int *second)
{
	int	tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

int	ft_alloc_map_matrix(t_v2 ***p_matrix, t_v2 dim)
{
	t_v2	**matrix;

	matrix = ft_malloc_soul(sizeof(*matrix) * dim.x);
	if (!matrix)
		return (ft_error("MAP MATRIX MALLOC", strerror(errno)));
	while (dim.x--)
	{
		matrix[dim.x] = ft_malloc_soul(sizeof(**matrix) * dim.y);
		if (!matrix[dim.x])
			return (ft_error("MAP MATRIX[i] MALLOC", strerror(errno)));
	}
	*p_matrix = matrix;
	return (1);
}
