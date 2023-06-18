/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:11:07 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/18 19:49:41 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

struct	s_draw_vars
{
	int		row;
	int		rows;
	int		col;
	int		cols;
};

int	ft_draw_map_as_vertical_projection(t_vars *vars)
{
	t_mlx				*mlx;
	void				*tmp;
	int					**matrix;
	struct s_draw_vars	draw_vars;

	mlx = vars->mlx;
	if (!mlx->win)
		return (1);
	tmp = vars->map;
	matrix = ((t_map *)tmp)->matrix;
	draw_vars.rows = ((t_map *)tmp)->rows;
	draw_vars.cols = ((t_map *)tmp)->columns;
	draw_vars.row = -1;
	draw_vars.col = -1;
	tmp = vars->image;
	while (draw_vars.row++ != draw_vars.rows)
		while (draw_vars.col++ != draw_vars.cols)
			ft_put_line(tmp, (t_point){});
	mlx_put_image_to_window(mlx->this, mlx->win, ((t_image *)tmp)->this, 0, 0);
	return (0);
}

int	ft_draw_map_as_isometric_projection(t_vars *vars)
{
	t_mlx	*mlx;

	mlx = vars->mlx;
	if (!mlx->win)
		return (1);
	ft_put_rectangle(vars, (t_point){10, 5}, (t_bvector){100, 200}, START_COLOR);
	mlx_put_image_to_window(mlx->this, mlx->win, vars->image->this, 0, 0);
	return (0);
}
