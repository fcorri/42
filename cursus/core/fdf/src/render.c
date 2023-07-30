/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:25:12 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/30 13:15:47 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static void	ft_render_legend(t_vars *vars)
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
	mlx_string_put(vars->mlx->this, vars->mlx->win, 10, y += 30, WHITE, "i             -> ISOMETRIC PROJECTION");
	mlx_string_put(vars->mlx->this, vars->mlx->win, 10, y += 15, WHITE, "o             -> ORTHOGONAL PROJECTION");
	mlx_string_put(vars->mlx->this, vars->mlx->win, 10, y += 30, WHITE, "ENTER         -> ANIMATE");
}

int	ft_set_render(t_vars *vars, int (*ft_render)(t_vars *vars), char *name)
{
	vars->camera->ft_render = ft_render;
	vars->camera->name = name;
	return (1);
}

int	ft_render_isometric(t_vars *vars)
{
	(void) vars;
	return (1);
}

int	ft_render_orthogonal(t_vars *vars)
{
	(void) vars;
	return (1);
}

int	ft_render_test(t_vars *vars)
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
	return (1);
}

int	ft_render(t_vars *vars)
{
	int	output;

	ft_bzero(vars->image->addr, WIDTH * HEIGHT * 4);
	output = vars->camera->ft_render(vars);
	mlx_put_image_to_window(vars->mlx->this, vars->mlx->win, vars->image->this, 0, 0);
	ft_render_legend(vars);
	return (output);
}
