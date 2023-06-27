/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decorators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:55:31 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/28 01:16:54 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

struct s_map_vars
{
	int	y;
	int	max_z;
	int	tmp;
};

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
	map->columns = tmp;
	tmp = ft_strlen(line);
	free(line);
	close(*fd);
	*fd = open(filename, O_RDONLY);
	return (tmp);
}

int	ft_split_decorator_to_init_map_matrix_with(char *line, t_map *map)
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
	matrix = map->matrix;
	vars.max_z = 0;
	while (number)
	{
		if (*number == '0')
			matrix[x-1][vars.y] = 0;
		else
		{
			vars.tmp = ft_atoi(number);
			if (vars.tmp > vars.max_z)
				vars.max_z = vars.tmp;
			matrix[x-1][vars.y] = vars.tmp;
		}
		free(number);
		number = tmp[++vars.y];
	}
	free(tmp);
	return (vars.max_z);
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
