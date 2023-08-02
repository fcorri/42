/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:39:55 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/31 12:36:38 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static int	ft_init_map_matrix(char *filename, t_map **p_map, t_map *map)
{
	int			fd;
	char		*line;
	t_vector2	min_max;

	if(!(ft_alloc_map_matrix(&map->matrix, map->dim)))
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_error("OPEN", strerror(errno)));
	min_max = (t_vector2){INT_MAX, INT_MIN};
	line = get_next_line(fd);
	while (line)
	{
		ft_vector2_swap_decorator(ft_split_decorator_to_init_map_matrix_with(line, map), &min_max);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map->min_max = min_max;
	*p_map = map;
	return (1);
}

static int	ft_init_map(char *filename, t_map **p_map)
{
	t_vector2	fd_rows;
	char		*line;
	t_map		*map;

	fd_rows.x = open(filename, O_RDONLY);
	if (fd_rows.x < 0)
		return (ft_error("OPEN", strerror(errno)));
	map = ft_malloc_soul(sizeof(t_map));
	if (!map)
		return(ft_error("MAP CALLOC", strerror(errno)));
	fd_rows.x = ft_split_decorator_to_init_map_cols(fd_rows.x, map, filename);
	if (fd_rows.x < 0)
		return (ft_error("SPLIT_DECORATOR_TO_INIT_LINE_LEN", strerror(errno)));
	fd_rows.y = 0;
	line = get_next_line(fd_rows.x);
	while (line)
	{
		fd_rows.y++;
		free(line);
		line = get_next_line(fd_rows.x);
	}
	close(fd_rows.x);
	map->dim.x = fd_rows.y;
	map->colors = (t_vector2){START_COLOR, END_COLOR};
	return (ft_init_map_matrix(filename, p_map, map));
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
