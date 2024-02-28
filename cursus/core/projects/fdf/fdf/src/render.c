/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:25:12 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/02 17:02:51 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static void	ft_render_legend(t_vars *vars)
{
	int		y;
	void	*this;
	void	*win;

	y = 20;
	this = vars->mlx->this;
	win = vars->mlx->win;
	mlx_string_put(this, win, (WIDTH >> 1) - 60, y, W, vars->camera->name);
	mlx_string_put(this, win, 10, y, W, "ARROW KEYS    -> MOVE");
	mlx_string_put(this, win, 10, y += 30, W, "+ / -         -> ZOOM IN / OUT");
	mlx_string_put(this, win, 10, y += 30, W, "c             -> CENTER");
	mlx_string_put(this, win, 10, y += 30, W, "r             -> RESTORE");
	mlx_string_put(this, win, 10, y += 30, W, \
		"x / X         -> ROTATE X-AXIS CLOCKWISE / ANTI-CLOCKWISE");
	mlx_string_put(this, win, 10, y += 15, W, \
		"y / Y         -> ROTATE Y-AXIS CLOCKWISE / ANTI-CLOCKWISE");
	mlx_string_put(this, win, 10, y += 15, W, \
		"z / Z         -> ROTATE Z-AXIS CLOCKWISE / ANTI-CLOCKWISE");
	mlx_string_put(this, win, 10, y += 30, W, \
		"i             -> ISOMETRIC PROJECTION");
	mlx_string_put(this, win, 10, y += 15, W, \
		"o             -> ORTHOGONAL PROJECTION");
}

static int	ft_render_camera(t_vars *vars)
{
	t_v2	rc;
	t_v2	dim;
	t_p		**matrix;
	t_p		p1;
	t_image	*image;

	rc = (t_v2){0, -1};
	dim = vars->map->dim;
	matrix = vars->camera->matrix;
	image = vars->image;
	while (rc.x != dim.x - 1)
	{
		while (++rc.y != dim.y - 1)
		{
			p1 = matrix[rc.x][rc.y];
			ft_put_line(image, p1, matrix[rc.x + 1][rc.y]);
			ft_put_line(image, p1, matrix[rc.x][rc.y + 1]);
		}
		ft_put_line(image, matrix[rc.x][rc.y], matrix[rc.x + 1][rc.y]);
		rc = (t_v2){rc.x + 1, -1};
	}
	while (++rc.y != dim.y - 1)
		ft_put_line(image, matrix[rc.x][rc.y], matrix[rc.x][rc.y + 1]);
	p1 = matrix[rc.x][rc.y];
	return (ft_put_pixel(image, p1.v, p1.color));
}

int	ft_render(t_vars *vars)
{
	t_mlx	*mlx;

	mlx = vars->mlx;
	ft_bzero(vars->image->addr, WIDTH * HEIGHT * 4);
	ft_render_camera(vars);
	mlx_put_image_to_window(mlx->this, mlx->win, vars->image->this, 0, 0);
	ft_render_legend(vars);
	return (1);
}
