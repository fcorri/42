/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decorators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:55:31 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/08 20:09:01 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

size_t	ft_split_decorator_init_line_len(int fd, t_map *map)
{
	int		width;
	char	*line;
	char	**tmp;
	char	*number;
	size_t	output;

	width = 0;
	line = get_next_line(fd);
	tmp = ft_split(line, ' ');
	number = *tmp;
	while (number)
	{
		free(number);
		width++;
		number = *++tmp;
	}
	map->width = width;
	output = ft_strlen(line);
	free(line);
	return (output);
}

void	ft_split_decorator_init_points_with(char *line, t_map *map)
{
	char		**tmp;
	int			x;
	static int	y;
	char		*number;

	x = 0;
	y++;
	tmp = ft_split(line, ' ');
	number = *tmp++;
	while (number)
	{
		map->points[y-1][x++] = ft_atoi(number);
		number = *tmp++;
	}
}
