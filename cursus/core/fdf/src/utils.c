/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:32:16 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/04 16:50:46 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

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

void	ft_put_pixel(t_image *img, t_bvector p, t_vector vcolor)
{
	int	x;
	int	y;
	int	color;

	x = p.x;
	y = p.y;
	color = (vcolor.x & RED) | (vcolor.y & GREEN) | (vcolor.z & BLUE);
	if ((0 <= x && x < WIDTH) && (0 <= y && y < HEIGHT))
		*(unsigned int *)(img->addr + (y * img->ll + x * (img->bpp / 8))) = color;
}

int	ft_init_matrix(int ***p_matrix, int rows, int columns)
{
	int	**matrix;
	int	i;

	matrix = ft_malloc_soul(sizeof(int *) * rows);
	if (!matrix)
		return (ft_error("MATRIX MALLOC", strerror(errno)));
	i = 0;
	while (i < rows)
	{
		matrix[i] = ft_malloc_soul(sizeof(int) * columns);
		if (!matrix[i])
			return (ft_error("MATRIX[i] MALLOC", strerror(errno)));
		i++;
	}
	*p_matrix = matrix;
	return (1);
}

t_bvector	ft_calculate_colors(t_vars *vars, int z1, int z2)
{
	int			n;
	t_vector	start;
	t_vector	step;
	t_vector	color;
	t_bvector	output;

	n = vars->map->min_max.y - vars->map->min_max.x;
	if (!n)
		return ((t_bvector){vars->map->colors.x, vars->map->colors.x});
	start = ft_new_vector_color_decorator(vars->map->colors.x);
	step = ft_div_scalar(ft_sub_vector(ft_new_vector_color_decorator(vars->map->colors.y), start), n);
	color = ft_add_vector(start, ft_mul_scalar(step, z1));
	output.x = (color.x & RED) | (color.y & GREEN) | (color.z & BLUE);
	color = ft_add_vector(start, ft_mul_scalar(step, z2));
	output.y = (color.x & RED) | (color.y & GREEN) | (color.z & BLUE);
	return (output);
}
