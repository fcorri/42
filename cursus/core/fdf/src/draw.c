/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:11:07 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/19 12:31:28 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

int	ft_set_map(t_vars *vars, int (*ft_draw)(t_vars *vars), char *name)
{
	vars->map->ft_draw = ft_draw;
	vars->map->name = name;
	vars->map->draw = 1;
	return (1);
}

int	ft_draw_map_as_isometric_projection(t_vars *vars)
{
	(void) vars;
	return (1);
}

int	ft_draw_map_as_orthogonal_projection(t_vars *vars)
{
	t_bvector	row_col;
	t_bvector	dim;
	int			**matrix;
	t_vector	tr;
	t_vector	zoom;
	t_matrix	rot;
	t_vector	p1;
	t_vector	p2;

	row_col = (t_bvector){0, 0};
	dim = vars->map->dim;
	matrix = vars->map->matrix;
	tr = vars->map->tr;
	zoom = vars->map->zoom;
	rot = vars->map->rot;
	while (row_col.x != dim.x - 1)
	{
		p1 = ft_rot(rot, (t_vector){tr.x, tr.y + zoom.y * row_col.x, matrix[row_col.x][row_col.y]});
		while (row_col.y != dim.y - 1)
		{
			p2 = ft_rot(rot, (t_vector){p1.x, p1.y + zoom.y, matrix[row_col.x + 1][row_col.y]});
			ft_put_line(vars->image, p1, p2, ft_calculate_colors(vars, p1.z, p2.z));
			p2 = ft_rot(rot, (t_vector){p1.x + zoom.x, p1.y, matrix[row_col.x][row_col.y + 1]});
			ft_put_line(vars->image, p1, p2, ft_calculate_colors(vars, p1.z, p2.z));
			p1 = p2;
			row_col.y += 1;
		}
		p2 = ft_rot(rot, (t_vector){p1.x, p1.y + zoom.y, matrix[row_col.x + 1][row_col.y]});
		ft_put_line(vars->image, p1, p2, ft_calculate_colors(vars, p1.z, p2.z));
		row_col = (t_bvector){row_col.x + 1, 0};
	}
	p1 = ft_rot(rot, (t_vector){tr.x, tr.y + zoom.y * row_col.x, matrix[row_col.x][row_col.y]});
	while (row_col.y != dim.y - 1)
	{
		p2 = ft_rot(rot, (t_vector){p1.x + zoom.x, p1.y, matrix[row_col.x][row_col.y + 1]});
		ft_put_line(vars->image, p1, p2, ft_calculate_colors(vars, p1.z, p2.z));
		p1 = p2;
		row_col.y += 1;
	}
	p1 = ft_rot(rot, (t_vector){tr.x + zoom.x * row_col.y, tr.y + zoom.y * row_col.x, matrix[row_col.x][row_col.y]});
	ft_put_pixel(vars->image, (t_bvector){p1.x, p1.y}, (t_vector){0xff0000, 0, 0});
	mlx_put_image_to_window(vars->mlx->this, vars->mlx->win, vars->image->this, 0, 0);
	return (1);
}

void	ft_draw_legend(t_vars *vars)
{
	int	y;

	y = 20;
	mlx_string_put(vars->mlx->this, vars->mlx->win, WIDTH/2 - 60, y, WHITE, vars->map->name);
	mlx_string_put(vars->mlx->this, vars->mlx->win, 10, y, WHITE,       "ARROW KEYS    -> MOVE");
	mlx_string_put(vars->mlx->this, vars->mlx->win, 10, y + 30, WHITE,  "+ / -         -> ZOOM IN / OUT");
	mlx_string_put(vars->mlx->this, vars->mlx->win, 10, y + 60, WHITE,  "x / X         -> ROTATE X-AXIS CLOCKWISE / ANTI-CLOCKWISE");
	mlx_string_put(vars->mlx->this, vars->mlx->win, 10, y + 75, WHITE,  "y / Y         -> ROTATE Y-AXIS CLOCKWISE / ANTI-CLOCKWISE");
	mlx_string_put(vars->mlx->this, vars->mlx->win, 10, y + 90, WHITE,  "z / Z         -> ROTATE Z-AXIS CLOCKWISE / ANTI-CLOCKWISE");
	mlx_string_put(vars->mlx->this, vars->mlx->win, 10, y + 120, WHITE, "i / I         -> ISOMETRIC PROJECTION");
	mlx_string_put(vars->mlx->this, vars->mlx->win, 10, y + 135, WHITE, "o / O         -> ORTHOGONAL PROJECTION");
	mlx_string_put(vars->mlx->this, vars->mlx->win, 10, y + 165, WHITE, "ENTER         -> ANIMATE");
}
