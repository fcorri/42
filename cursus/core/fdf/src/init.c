/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:10:26 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/01 20:49:45 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static void	ft_add_points(char **vector, t_map *map)
{
	char	*line;

	line = *vector++;
	while (line)
	{
		ft_lstadd_back(map->points, ft_lstnew(tmp));
		line = *vector++;
	}
}

static void	ft_init_points(int fd, t_map *map)
{
	int		x;
	int		y;
	char	*tmp;
	char	**vector;
	t_list	*last;

	x = 0;
	y = 0;
	tmp = get_next_line(fd);
	vector = ft_split(tmp, ' ');
	tmp = *vector++;
	last = map->points;
	while (tmp)
	{
		last->next = ft_lstnew(tmp)
		last = last->next;
		x++;
		tmp = *vector++;
	}
	map->x = x;
	tmp = get_next_line(fd);
	while (tmp)
	{
		ft_add_points(ft_split(tmp, ' '), map);
		y++;
		tmp = get_next_line(fd);
	}
	map->y = y;
}

t_map	*ft_init_map(char *filename)
{
	int		fd;
	t_map	*map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_null_error(strerror(errno)));
	map = malloc(sizeof(*map));
	if (!map)
		return(ft_null_error(strerror(errno)));
	map->points = NULL;
	ft_init_points(fd, map);
	return (map);
}

t_mlx	*ft_init_mlx(void)
{
	t_mlx	*mlx;
	void	*instance;
	void	*window;
	int		errsv;

	instance = mlx_init();
	if (!instance)
	{
		ft_error(strerror(errno));
		return (NULL);
	}
	window = mlx_new_window(instance, WIDTH, HEIGHT, TITLE);
	if (!window)
	{
		errsv = errno;
		free(instance);
		ft_error(strerror(errsv));
		return (NULL);
	}
	mlx = malloc(sizeof(*mlx));
	mlx->instance = instance;
	mlx->window = window;
	return (mlx);
}

void	ft_init_hooks(t_mlx *mlx)
{
	(void) mlx;
}
