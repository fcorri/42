/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:11:07 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/26 19:35:43 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

int	ft_set_camera(t_vars *vars, int (*ft_draw)(t_vars *vars), char *name)
{
	vars->camera->ft_draw = ft_draw;
	vars->camera->name = name;
	vars->camera->draw = 1;
	return (1);
}

int	ft_draw_map_as_isometric_projection(t_vars *vars)
{
	(void) vars;
	return (1);
}

int	ft_draw_map_as_orthogonal_projection(t_vars *vars)
{
	(void) vars;
	return (1);
}

int	ft_test_draw(t_vars *vars)
{
	t_vector2	row_col;
	t_vector2	dim;
	t_point		**matrix;
	t_point		p1;
	t_point		p2;

	row_col = (t_vector2){0, 0};
	dim = vars->map->dim;
	matrix = vars->camera->matrix;
	while (row_col.x != dim.x - 1)
	{
		p1 = matrix[row_col.x][row_col.y];
		while (row_col.y != dim.y - 1)
		{
			p2 = matrix[row_col.x + 1][row_col.y];
			ft_put_line(vars->image, p1, p2);
			p2 = matrix[row_col.x][row_col.y + 1];
			ft_put_line(vars->image, p1, p2);
			p1 = p2;
			row_col.y += 1;
		}
		p2 = matrix[row_col.x + 1][row_col.y];
		ft_put_line(vars->image, p1, p2);
		row_col = (t_vector2){row_col.x + 1, 0};
	}
	p1 = matrix[row_col.x][row_col.y];
	while (row_col.y != dim.y - 1)
	{
		p2 = matrix[row_col.x][row_col.y + 1];
		ft_put_line(vars->image, p1, p2);
		p1 = p2;
		row_col.y += 1;
	}
	p1 = matrix[row_col.x][row_col.y];
		ft_put_line(vars->image, p1, p1);
	mlx_put_image_to_window(vars->mlx->this, vars->mlx->win, vars->image->this, 0, 0);
	return (1);
}

void	ft_draw_legend(t_vars *vars)
{
	int	y;

	y = 20;
	mlx_string_put(vars->mlx->this, vars->mlx->win, WIDTH/2 - 60, y, WHITE, vars->camera->name);
	mlx_string_put(vars->mlx->this, vars->mlx->win, 10, y, WHITE,       "ARROW KEYS    -> MOVE");
	mlx_string_put(vars->mlx->this, vars->mlx->win, 10, y += 30, WHITE, "+ / -         -> ZOOM IN / OUT");
	mlx_string_put(vars->mlx->this, vars->mlx->win, 10, y += 30, WHITE, "c             -> CENTER");
	mlx_string_put(vars->mlx->this, vars->mlx->win, 10, y += 30, WHITE, "x / X         -> ROTATE X-AXIS CLOCKWISE / ANTI-CLOCKWISE");
	mlx_string_put(vars->mlx->this, vars->mlx->win, 10, y += 15, WHITE, "y / Y         -> ROTATE Y-AXIS CLOCKWISE / ANTI-CLOCKWISE");
	mlx_string_put(vars->mlx->this, vars->mlx->win, 10, y += 15, WHITE, "z / Z         -> ROTATE Z-AXIS CLOCKWISE / ANTI-CLOCKWISE");
	mlx_string_put(vars->mlx->this, vars->mlx->win, 10, y += 30, WHITE, "i / I         -> ISOMETRIC PROJECTION");
	mlx_string_put(vars->mlx->this, vars->mlx->win, 10, y += 15, WHITE, "o / O         -> ORTHOGONAL PROJECTION");
	mlx_string_put(vars->mlx->this, vars->mlx->win, 10, y += 30, WHITE, "ENTER         -> ANIMATE");
}
