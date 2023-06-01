/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:10:26 by fcorri            #+#    #+#             */
/*   Updated: 2023/05/23 19:40:54 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

t_map	*ft_init_map(char *filename)
{
	int		fd;
	t_map	*map;
	char	*line;
	int		y;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_null_error(strerror(errno)));
	map = malloc(sizeof(*map));
	if (!map)
		return(ft_null_error(strerror(errno)));
	map->x = ft_init_map_x(get_next_line(fd));
	y = 1;
	line = get_next_line(fd);
	while (line)
	{
		y++;
		ft_init_points(map, ft_split(line, ' '));
		line = get_next_line(fd);
	}
	map->y = y;
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
