/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:10:26 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/09 01:05:48 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static t_map	*ft_init_points(char *filename, int old_fd, t_map *map)
{
	int		new_fd;
	char	*line;

	new_fd = open(filename, O_RDONLY);
	if (new_fd < 0)
		return (ft_null_error(strerror(errno)));
	close(old_fd);
	line = get_next_line(new_fd);
	while (line)
	{
		ft_split_decorator_to_init_map_matrix_with(line, map);
		line = get_next_line(new_fd);
	}
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
		return (ft_null_error(strerror(errno)));
	map = malloc(sizeof(*map));
	if (!map)
		return(ft_null_error(strerror(errno)));
	line_len = ft_split_decorator_to_init_line_len(fd, map);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_null_error(strerror(errno)));
	rows = 0;
	line = malloc(sizeof(char) * line_len);
	while (read(fd, line, line_len))
		rows++;
	free(line);
	map->rows = rows;
	ft_malloc_decorator(map, rows);
	return (ft_init_points(filename, fd, map));
}
