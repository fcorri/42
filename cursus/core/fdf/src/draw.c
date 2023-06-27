/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:11:07 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/28 00:35:57 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

int	ft_clear_image_and_set_ft_draw(t_vars *vars, int (*ft_draw)(t_vars *vars))
{
/*
	mlx_destroy_image(vars->mlx->this, vars->image->this);
	vars->image->this = ft_init_image(vars->mlx);
	if (!vars->image->this)
		return (0);
*/
	vars->map->ft_draw = ft_draw;
	return (1);
}
/*
int	ft_draw_map_as_vertical_projection(t_vars *vars)
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
	t_mlx	*mlx;
	int	x, y;

	x = WIDTH / 2;
	y = HEIGHT / 2;
	mlx = vars->mlx;
	if (!mlx->win)
		return (1);
	ft_put_line(vars->image, (t_vector){x, y}, (t_bvector){x + 100, y}, RED);
	mlx_put_image_to_window(mlx->this, mlx->win, vars->image->this, 0, 0);
	return (0);
}
*/

int ft_draw_test(t_vars *vars)
{
	int x, y;
	int X, Y;
	t_vector	v0, v1;
	t_bvector	color = {RED, BLUE};

	X = 100;
	Y = 50;
	if (!vars->mlx->win)
		return (1);
	x = (WIDTH - X)/2;
	y = (HEIGHT - Y)/2;
	v0 = (t_vector){x,y,0};
	v1 = (t_vector){x+X,y,10};
	ft_put_line(vars->image, v0, v1, color);
	v1 = (t_vector){x-X,y,10};
	ft_put_line(vars->image, v0, v1, color);
	v1 = (t_vector){x,y+Y,10};
	ft_put_line(vars->image, v0, v1, color);
	v1 = (t_vector){x,y-Y,10};
	ft_put_line(vars->image, v0, v1, color);
	v1 = (t_vector){x+X,y+Y,10};
	ft_put_line(vars->image, v0, v1, color);
	v1 = (t_vector){x+X,y-Y,10};
	ft_put_line(vars->image, v0, v1, color);
	v1 = (t_vector){x-X,y+Y,10};
	ft_put_line(vars->image, v0, v1, color);
	v1 = (t_vector){x-X,y-Y,10};
	ft_put_line(vars->image, v0, v1, color);
	mlx_put_image_to_window(vars->mlx->this, vars->mlx->win, vars->image->this, 0, 0);
	return 0;
}
