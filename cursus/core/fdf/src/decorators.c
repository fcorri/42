/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decorators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:55:31 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/15 17:59:50 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

struct s_pixel_vars
{
	int	y;
	int	max_z;
	int	tmp;
};

size_t	ft_split_decorator_to_init_line_len(int fd, t_map *map)
{
	int		columns;
	char	*line;
	char	**tmp;
	char	*number;
	size_t	output;

	columns = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	tmp = ft_split(line, ' ');
	number = *tmp++;
	while (number)
	{
		free(number);
		columns++;
		number = *tmp++;
	}
	map->columns = columns;
	output = ft_strlen(line);
	free(line);
	return (output);
}

int	ft_split_decorator_to_init_map_matrix_with(char *line, t_map *map)
{
	char			**tmp;
	int				**matrix;
	struct s_pixel_vars	vars;
	static int		x;
	char			*number;

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
		number = tmp[++vars.y];
	}
	free(tmp);
	return (vars.max_z);
}

int	ft_put_pixel_decorator(t_image *img, t_point p, int color, int main)
{
	if (main)
		ft_put_pixel(*img, p.x, p.y, color);
	else
		ft_put_pixel(*img, p.y, p.x, color);
	return (p.x);
}
