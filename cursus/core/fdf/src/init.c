/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:39:55 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/03 18:22:17 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static int	ft_continue_initing_map(t_map **p_map, t_map *map)
{
	int	i;
	int	rows;
	int	columns;
	int	**matrix;

	i = -1;
	rows = map->dim.x;
	columns = map->dim.y;
	matrix = ft_malloc_soul(sizeof(int *) * rows);
	if (!matrix)
		return (ft_error("MATRIX MALLOC", strerror(errno)));
	while (++i < rows)
	{
		matrix[i] = ft_malloc_soul(sizeof(int) * columns);
		if (!matrix[i])
			return (ft_error("MATRIX[I] MALLOC", strerror(errno)));
	}
	map->matrix = matrix;
	map->draw = 1;
	map->ft_draw = ft_draw_test;
	*p_map = map;
	return (1);
}

static int	ft_init_points(char *filename, int old_fd, t_map *map, size_t line_len)
{
	int			new_fd;
	char		*line;
	t_bvector	min_max;
	t_bvector	tmp;

	new_fd = open(filename, O_RDONLY);
	if (new_fd < 0)
		return (ft_error("OPEN", strerror(errno)));
	close(old_fd);
	line = ft_malloc_soul(sizeof(char) * (line_len + 1));
	if (!line)
		return (ft_error("LINE MALLOC in INIT_POINTS", strerror(errno)));
	line[line_len] = '\0';
	min_max = (t_bvector){INT_MAX, INT_MIN};
	while (read(new_fd, line, line_len))
	{
		tmp = ft_split_decorator_to_init_map_matrix_with(line, map);
		ft_bvector_swap_decorator(tmp, &min_max);
	}
	map->min_max_value = min_max;
	free(line);
	close(new_fd);
	return (1);
}

int	ft_init_map(char *filename, t_map **p_map)
{
	int		fd;
	t_map	*map;
	size_t	line_len;
	int		rows;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_error("OPEN", strerror(errno)));
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return(ft_error("MAP CALLOC", strerror(errno)));
	line_len = ft_split_decorator_to_init_line_len(&fd, map, filename);
	if (!line_len || fd < 0)
		return (ft_error("SPLIT_DECORATOR_TO_INIT_LINE_LEN", strerror(errno)));
	rows = 0;
	line = ft_malloc_soul(sizeof(char) * line_len);
	if (!line)
		return (ft_error("LINE MALLOC in INIT MAP", strerror(errno)));
	while (read(fd, line, line_len))
		rows++;
	free(line);
	map->dim.x = rows;
	map->name = "ISOMETRIC PROJECTION";
	return (ft_continue_initing_map(p_map, map) && ft_init_points(filename, fd, map, line_len));
}

int	ft_init_mlx(t_mlx **p_mlx)
{
	t_mlx	*mlx;
	void	*this;
	void	*win;

	this = mlx_init();
	if (!this)
		return (ft_error("MLX_INIT", strerror(errno)));
	win = mlx_new_window(this, WIDTH, HEIGHT, TITLE);
	if (!win)
		return (ft_error("MLX_NEW_WINDOW", strerror(errno)));
	mlx = ft_malloc_soul(sizeof(t_mlx));
	if (!mlx)
		return (ft_error("MLX MALLOX", strerror(errno)));
	mlx->this = this;
	mlx->win = win;
	*p_mlx = mlx;
	return (1);
}

int	ft_init_image(t_mlx *mlx, t_image **p_image)
{
	t_image	*image;
	
	image = ft_malloc_soul(sizeof(t_image));
	if (!image)
		return (ft_error("IMAGE MALLOC", strerror(errno)));
	image->this = mlx_new_image(mlx->this, WIDTH, HEIGHT);
	if (!image->this)
		return (ft_error("MLX_NEW_IMAGE", strerror(errno)));
	image->addr = mlx_get_data_addr(image->this, &(image->bpp), &(image->ll), &(image->end));
	if (!image->addr)
		return (ft_error("MLX_GET_DATA_ADDR", strerror(errno)));
	*p_image = image;
	return (1);
}
