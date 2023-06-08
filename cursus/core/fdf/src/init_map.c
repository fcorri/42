/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:10:26 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/08 20:07:38 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static t_map	*ft_init_points(char *filename, int fd, t_map *map)
{
	char	*line;

	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_null_error(strerror(errno)));
	line = get_next_line(fd);
	while (line)
	{
		ft_split_decorator_init_points_with(line, map);
		line = get_next_line(fd);
	}
	return (map);
}

t_map	*ft_init_map(char *filename)
{
	int		fd;
	size_t	line_len;
	int		height;
	char	*line;
	t_map	*map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_null_error(strerror(errno)));
	map = malloc(sizeof(*map));
	if (!map)
		return(ft_null_error(strerror(errno)));
	line_len = ft_split_decorator_init_line_len(fd, map);
	height = 1;
	line = malloc(sizeof(char) * line_len);
	while (read(fd, line, line_len))
		height++;
	free(line);
	map->height = height;
	map->points = malloc(sizeof(int) * (map->width * height));
	return (ft_init_points(filename, fd, map));
}
