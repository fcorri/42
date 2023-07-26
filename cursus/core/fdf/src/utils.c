/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:32:16 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/26 15:56:43 by fcorri           ###   ########.fr       */
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

void	ft_put_pixel(t_image *img, t_bvector p, t_color vcolor)
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

int	ft_init_int_matrix(int ***p_matrix, int rows, int columns)
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

int	ft_init_vector_matrix(t_vector ***p_matrix, int rows, int columns)
{
	t_vector	**matrix;
	int			i;

	matrix = ft_malloc_soul(sizeof(t_vector *) * rows);
	if (!matrix)
		return (ft_error("MATRIX MALLOC", strerror(errno)));
	i = 0;
	while (i < rows)
	{
		matrix[i] = ft_malloc_soul(sizeof(t_vector) * columns);
		if (!matrix[i])
			return (ft_error("MATRIX[i] MALLOC", strerror(errno)));
		i++;
	}
	*p_matrix = matrix;
	return (1);
}

static t_vector ft_cv(t_color color)
{
	return (
		(t_vector){color.x, color.y, color.z}
	);
}

static t_color ft_vc(t_vector v)
{
	return (
		(t_color){v.x, v.y, v.z}
	);
}

t_bvector	ft_calculate_colors(t_vars *vars, int z1, int z2)
{
	int			n;
	t_color	start;
	t_color	step;
	t_color	color;
	t_bvector	output;

	n = vars->map->min_max.y - vars->map->min_max.x;
	if (!n)
		return ((t_bvector){vars->map->colors.x, vars->map->colors.x});
	start = ft_new_vector_color_decorator(vars->map->colors.x);
	step = ft_vc(ft_div_scalar(ft_sub_vector(ft_cv(ft_new_vector_color_decorator(vars->map->colors.y)), ft_cv(start)), n));
	color = ft_vc(ft_add_vector(ft_cv(start), ft_mul_scalar(ft_cv(step), z1)));
	output.x = (color.x & RED) | (color.y & GREEN) | (color.z & BLUE);
	color = ft_vc(ft_add_vector(ft_cv(start), ft_mul_scalar(ft_cv(step), z2)));
	output.y = (color.x & RED) | (color.y & GREEN) | (color.z & BLUE);
	return (output);
}
