/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:50:38 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/15 11:27:29 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

void	ft_draw_map_as_isometric_projection(t_mlx *mlx)
{
	(void) mlx;
}

static int	ft_color(t_mlx *mlx, int z)
{
	(void) mlx;
	(void) z;
	return (mlx->map->start_color);
}

void	ft_draw_map_as_vertical_projection(t_mlx *mlx)
{
	int			row;
	int			col;
	int			**matrix;	
	void		*tmp;

	tmp = mlx->map;
	row = ((t_map *)tmp)->rows;
	col = ((t_map *)tmp)->columns;
	matrix = ((t_map *)tmp)->matrix;
	tmp = mlx->image;
	while (row--)
		while (col--)
			ft_put_pixel(*(t_image *)tmp, row, col, ft_color(mlx, matrix[row][col]));
}

int	ft_init_image(t_mlx *mlx)
{
	t_image	*image;

	image = mlx_new_image(mlx->this, WIDTH, HEIGHT);
	if (!image)
	{
		mlx_destroy_window(mlx->this, mlx->win);
		return (ft_error("MLX_NEW_IMAGE", strerror(errno)));
	}
	mlx->image = image;
	return (1);
}
