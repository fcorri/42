/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:11:07 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/03 18:11:09 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

int	ft_set_map(t_vars *vars, int (*ft_draw)(t_vars *vars))
{
	vars->map->ft_draw = ft_draw;
	vars->map->draw = 1;
	return (1);
}
/*
int	ft_draw_map_as_ortoghonal_projection(t_vars *vars)
{
	t_mlx		*mlx;
	void		*tmp;
	//int			**matrix;	
	t_bvector	indice;
	t_bvector	point;

	mlx = vars->mlx;
	if (!mlx->win)
		return (1);
	tmp = vars->map;
	//matrix = ((t_map *)tmp)->matrix;
	indice.x = ((t_map *)tmp)->rows;
	indice.y = ((t_map *)tmp)->columns;
	point.x = (WIDTH + indice.x) / 2;
	point.y = (HEIGHT + indice.y) / 2;
	tmp = vars->image;
	while (indice.x-- >= 0)
	{
		while (indice.y-- >= 0)
		{
			ft_put_pixel(tmp, (t_bvector){point.x, point.y}, RED);
			point.y -= 5;
		}
		point.x -= 5;
	}
	mlx_put_image_to_window(mlx->this, mlx->win, ((t_image *)tmp)->this, 0, 0);
	return (0);
}

int	ft_draw_map_as_isometric_projection(t_vars *vars)
{
	if (!vars->mlx->win)
		return (1);
	mlx_put_image_to_window(vars->mlx->this, vars->mlx->win, vars->image->this, 0, 0);
	return 0;
}
*/

int ft_draw_null(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx->this, vars->mlx->win, vars->image->this, 0, 0);
	return 0;
}

static void	ft_draw_legend(t_vars *vars)
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

int ft_draw_test(t_vars *vars)
{
	ft_draw_legend(vars);
	return (0);
}
