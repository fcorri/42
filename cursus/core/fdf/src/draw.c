/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:11:07 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/04 19:18:47 by fcorri           ###   ########.fr       */
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
	t_bvector	p;
	t_bvector	dim;
	int			**matrix;
	t_vector	v;

	p.x = -1;
	dim = vars->map->dim;
	matrix = vars->map->origin;
	v = ft_add_vector(vars->map->tr, vars->map->zoom);
	while (++p.x != dim.x - 1)
	{
		p.y = -1;
		while (++p.y != dim.y - 1)
			ft_put_line(vars->image, ft_add_vector(v, (t_vector){p.x, p.y, matrix[p.x][p.y]}), ft_add_vector(v, (t_vector){p.x, p.y + 1, matrix[p.x][p.y + 1]}), ft_calculate_colors(vars, matrix[p.x][p.y], matrix[p.x][p.y+1]));
	}
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
	mlx_string_put(vars->mlx->this, vars->mlx->win, 10, y + 135, WHITE, "p / P         -> PERSPECTIVE PROJECTION");
	mlx_string_put(vars->mlx->this, vars->mlx->win, 10, y + 165, WHITE, "ENTER         -> ANIMATE");
}
