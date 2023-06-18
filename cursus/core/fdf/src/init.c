/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:39:55 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/18 15:25:49 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static void	ft_init_matrix_and_drawing_function(t_map *map)
{
	int	i;
	int	rows;
	int	columns;
	int	**matrix;

	i = -1;
	rows = map->rows;
	columns = map->columns;
	matrix = malloc(sizeof(int *) * rows);
	while (++i < rows)
		matrix[i] = malloc(sizeof(int) * columns);
	map->matrix = matrix;
	map->ft_draw = ft_draw_map_as_isometric_projection;
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
		tmp = ft_split_decorator_to_init_map_matrix_with(line, map);
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
	line_len = ft_split_decorator_to_init_line_len(fd, map);
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
	ft_init_matrix_and_drawing_function(map);
	return (ft_init_points(filename, fd, map, line_len));
}

t_mlx	*ft_init_mlx(void)
{
	t_mlx	*mlx;
	void	*this;
	void	*win;
	int		errsv;

	this = mlx_init();
	if (!this)
		return (ft_null_error("MLX_INIT", strerror(errno)));
	win = mlx_new_window(this, WIDTH, HEIGHT, TITLE);
	if (!win)
	{
		errsv = errno;
		free(this);
		return (ft_null_error("MLX_NEW_WINDOW", strerror(errsv)));
	}
	mlx = malloc(sizeof(*mlx));
	mlx->this = this;
	mlx->win = win;
	return (mlx);
}

t_image	*ft_init_image(t_mlx *mlx)
{
	int		errsv;
	t_image	*image;
	
	image = malloc(sizeof(*image));
	if (!image)
	{
		errsv = errno;
		mlx_destroy_window(mlx->this, mlx->win);
		return (ft_null_error("MALLOC", strerror(errsv)));
	}
	image->this = mlx_new_image(mlx->this, WIDTH, HEIGHT);
	if (!image->this)
	{
		errsv = errno;
		mlx_destroy_window(mlx->this, mlx->win);
		return (ft_null_error("MLX_NEW_IMAGE", strerror(errsv)));
	}
	image->addr = mlx_get_data_addr(image->this, &(image->bpp), &(image->ll), &(image->end));
	return (image);
}
