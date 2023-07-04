/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decorators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:55:31 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/03 23:28:21 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

struct s_map_vars
{
	int			y;
	t_bvector	min_max;
	int			tmp;
};

void	ft_bvector_swap_decorator(t_bvector value, t_bvector *to_be_checked)
{
	if (value.x < to_be_checked->x)
		ft_swap(&value.x, &to_be_checked->x);
	else if (value.y > to_be_checked->y)
		ft_swap(&value.y, &to_be_checked->y);
}

static void	ft_int_swap_decorator(int value, t_bvector *to_be_checked)
{
	if (value < to_be_checked->x)
		ft_swap(&value, &to_be_checked->x);
	else if (value > to_be_checked->y)
		ft_swap(&value, &to_be_checked->y);
}

size_t	ft_split_decorator_to_init_line_len(int *fd, t_map *map, char *filename)
{
	size_t	tmp;
	char	*line;
	char	**splitted;

	tmp = 0;
	line = get_next_line(*fd);
	if (!line)
		return (0);
	get_next_line(-1);
	splitted = ft_split(line, ' ');
	if (!splitted)
		return (0);
	while (splitted[tmp])
		free(splitted[tmp++]);
	free(splitted);
	map->dim.y = tmp;
	tmp = ft_strlen(line);
	free(line);
	close(*fd);
	*fd = open(filename, O_RDONLY);
	return (tmp);
}

t_bvector	ft_split_decorator_to_init_map_matrix_with(char *line, t_map *map)
{
	char				**tmp;
	int					**matrix;
	struct s_map_vars	vars;
	static int			x;
	char				*number;

	vars.y  = 0;
	x++;
	tmp = ft_split(line, ' ');
	number = tmp[vars.y];
	matrix = map->origin;
	vars.min_max = (t_bvector){INT_MAX, INT_MIN};
	while (number)
	{
		if (*number == '0')
			vars.tmp = 0;
		else
			vars.tmp = ft_atoi(number);
		ft_int_swap_decorator(vars.tmp, &vars.min_max);
		matrix[x-1][vars.y] = vars.tmp;
		free(number);
		number = tmp[++vars.y];
	}
	free(tmp);
	return (vars.min_max);
}

t_vector	ft_new_vector_color_decorator(int color)
{
	return ((t_vector)
		{
			color & RED,
			color & GREEN,
			color & BLUE
		});
}
