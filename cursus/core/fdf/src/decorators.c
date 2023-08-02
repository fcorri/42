/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decorators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:55:31 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/02 17:07:30 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

struct s_map_vars
{
	int		y;
	int		z;
	t_v2	min_max;
};

static void	ft_int_swap_decorator(int value, t_v2 *to_be_checked)
{
	if (value < to_be_checked->x)
		ft_swap(&value, &to_be_checked->x);
	else if (value > to_be_checked->y)
		ft_swap(&value, &to_be_checked->y);
}

void	ft_v2_swap_decorator(t_v2 value, t_v2 *to_be_checked)
{
	if (value.x < to_be_checked->x)
		ft_swap(&value.x, &to_be_checked->x);
	else if (value.y > to_be_checked->y)
		ft_swap(&value.y, &to_be_checked->y);
}

int	ft_split_decorator_to_init_map_cols(int fd, t_map *map, char *filename)
{
	int		cols;
	char	*line;
	char	**splitted;

	line = get_next_line(fd);
	if (!line)
		return (-1);
	get_next_line(-1);
	close(fd);
	splitted = ft_split(line, ' ');
	free(line);
	if (!splitted)
		return (-1);
	cols = 0;
	while (splitted[cols])
		free(splitted[cols++]);
	free(splitted);
	map->dim.y = cols;
	return (open(filename, O_RDONLY));
}

t_v2	ft_split_decorator_to_init_map_matrix_with(char *line, t_map *map)
{
	char				**tmp;
	int					**matrix;
	struct s_map_vars	vars;
	static int			x;
	char				*number;

	vars.y = 0;
	tmp = ft_split(line, ' ');
	number = tmp[vars.y];
	matrix = map->matrix;
	vars.min_max = (t_v2){INT_MAX, INT_MIN};
	while (number)
	{
		if (*number == '0')
			vars.z = 0;
		else
			vars.z = ft_atoi(number);
		ft_int_swap_decorator(vars.z, &vars.min_max);
		matrix[x][vars.y] = vars.z;
		free(number);
		number = tmp[++vars.y];
	}
	free(tmp);
	x++;
	return (vars.min_max);
}
