/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:39:55 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/31 02:06:43 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static int	ft_init_map_matrix(char *filename, int old_fd, t_map *map, size_t line_len)
{
	int			new_fd;
	char		*line;
	t_vector2	min_max;

	if(!(ft_alloc_map_matrix(&map->matrix, map->dim)))
		return (0);
	new_fd = open(filename, O_RDONLY);
	if (new_fd < 0)
		return (ft_error("OPEN", strerror(errno)));
	close(old_fd);
	line = ft_malloc_soul(sizeof(char) * (line_len + 1));
	if (!line)
		return (ft_error("LINE MALLOC in INIT_POINTS", strerror(errno)));
	min_max = (t_vector2){INT_MAX, INT_MIN};
	while (read(new_fd, line, line_len))
		ft_vector2_swap_decorator(ft_split_decorator_to_init_map_matrix_with(line, map), &min_max);
	map->min_max = min_max;
	free(line);
	close(new_fd);
	return (1);
}

static int	ft_init_map(char *filename, t_map **p_map)
{
	t_vector2	fd_rows;
	t_map		*map;
	size_t		line_len;
	char		*line;

	fd_rows.x = open(filename, O_RDONLY);
	if (fd_rows.x < 0)
		return (ft_error("OPEN", strerror(errno)));
	map = ft_malloc_soul(sizeof(t_map));
	if (!map)
		return(ft_error("MAP CALLOC", strerror(errno)));
	line_len = ft_split_decorator_to_init_line_len(&fd_rows.x, map, filename);
	if (!line_len || fd_rows.x < 0)
		return (ft_error("SPLIT_DECORATOR_TO_INIT_LINE_LEN", strerror(errno)));
	fd_rows.y = 0;
	line = ft_malloc_soul(sizeof(char) * line_len);
	if (!line)
		return (ft_error("LINE MALLOC in INIT MAP", strerror(errno)));
	while (read(fd_rows.x, line, line_len))
		fd_rows.y++;
	free(line);
	map->dim.x = fd_rows.y;
	map->colors = (t_vector2){START_COLOR, END_COLOR};
	*p_map = map;
	return (ft_init_map_matrix(filename, fd_rows.x, map, line_len));
}

static int	ft_init_camera(t_vars *vars)
{
	t_vector2	z_n;
	t_camera	*camera;
	t_vector2	dim;

	z_n.y = vars->map->min_max.y - vars->map->min_max.x;
	camera = ft_malloc_soul(sizeof(t_camera));
	if (!camera)
		return (ft_error("CAMERA MALLOC", strerror(errno)));
	dim = vars->map->dim;
	if (!ft_alloc_camera_matrix(&camera->matrix, dim))
		return (0);
	while (dim.x--)
	{
		dim.y = vars->map->dim.y;
		while (dim.y--)
		{
			z_n.x = vars->map->matrix[dim.x][dim.y];
			camera->matrix[dim.x][dim.y] = (t_point){(t_vector3){dim.y, dim.x, z_n.x}, ft_interpolate_colors(START_COLOR, END_COLOR, z_n.x, z_n.y)};
		}
	}
	camera->name = "TEST";
	camera->ft_render = ft_render_test;
	vars->camera = camera;
	ft_zoom_on(vars, 20);
	return (1);
}

static int	ft_init_mlx(t_mlx **p_mlx)
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

static int	ft_init_image(t_mlx *mlx, t_image **p_image)
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

int	ft_init_fdf(t_vars *vars, char *filename)
{
	if (!(ft_init_map(filename, &vars->map)
		&& ft_init_camera(vars)
		&& ft_init_mlx(&vars->mlx)
		&& ft_init_image(vars->mlx, &vars->image)))
		return (0);
	return (1);
}
