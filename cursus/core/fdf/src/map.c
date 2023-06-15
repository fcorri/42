/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:10:26 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/15 11:25:16 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static void	ft_allocate(t_map *map, int rows)
{
	int	i;
	int	columns;
	int	**matrix;

	i = -1;
	columns = map->columns;
	matrix = malloc(sizeof(int *) * rows);
	while (++i < rows)
		matrix[i] = malloc(sizeof(int) * columns);
	map->matrix = matrix;
}

static t_map	*ft_init_points(char *filename, int old_fd, t_map *map, size_t line_len)
{
	int		new_fd;
	char	*line;
	int		max_z;
	int		tmp;

	new_fd = open(filename, O_RDONLY);
	if (new_fd < 0)
		return (ft_null_error("OPEN", strerror(errno)));
	close(old_fd);
	line = malloc(sizeof(char) * (line_len + 1));
	line[line_len] = '\0';
	max_z = 0;
	while (read(new_fd, line, line_len))
	{
		tmp = ft_split_decorator_init_map_matrix(line, map);
		if (tmp > max_z)
			max_z = tmp;
	}
	map->max_z = max_z;
	free(line);
	close(new_fd);
	return (map);
}

t_map	*ft_init_map(char *filename)
{
	int		fd;
	size_t	line_len;
	int		rows;
	char	*line;
	t_map	*map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_null_error("OPEN", strerror(errno)));
	map = malloc(sizeof(*map));
	if (!map)
		return(ft_null_error("MALLOC", strerror(errno)));
	line_len = ft_split_decorator_init_line_len(fd, map);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_null_error("OPEN", strerror(errno)));
	rows = 0;
	line = malloc(sizeof(char) * line_len);
	while (read(fd, line, line_len))
		rows++;
	free(line);
	map->rows = rows;
	ft_allocate(map, rows);
	return (ft_init_points(filename, fd, map, line_len));
}
