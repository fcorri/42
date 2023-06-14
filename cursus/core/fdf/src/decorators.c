/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decorators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:55:31 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/14 22:48:22 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

size_t	ft_split_decorator_init_line_len(int fd, t_map *map)
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

void	ft_split_decorator_init_map_matrix(char *line, t_map *map)
{
	char		**tmp;
	int			**matrix;
	int			x;
	static int	y;
	char		*number;

	x = 0;
	y++;
	tmp = ft_split(line, ' ');
	number = *tmp++;
	matrix = map->matrix;
	while (number)
	{
		matrix[y-1][x++] = ft_atoi(number);
		number = *tmp++;
	}
}

int	ft_put_pixel_decorator(t_image img, t_vector p, int color, int main)
{
	if (main)
		ft_put_pixel(img, p.x, p.y, color);
	else
		ft_put_pixel(img, p.y, p.x, color);
	return (x);
}
