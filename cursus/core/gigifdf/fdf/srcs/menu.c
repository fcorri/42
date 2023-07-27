/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmogid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:38:17 by larmogid          #+#    #+#             */
/*   Updated: 2023/05/01 22:27:01 by larmogid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static char	*get_view_name(t_fdf *fdf);

void	print_menu(t_fdf *fdf)
{
	int		y;
	char	*projection;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx;
	win = fdf->win;
	projection = get_view_name(fdf);
	mlx_string_put(mlx, win, 50, y += 50, C_TEXT, projection);
	mlx_string_put(mlx, win, 50, y += 50, C_TEXT, "Press:                    ");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "'ESC'/Close Button (Close)");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "'-' or '+'          (Zoom)");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Arrow Keys          (Move)");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "'S' or 'W'      (Rotate X)");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "'Q' or 'E'      (Rotate Y)");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "'A' or 'D'      (Rotate Z)");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "'Z' or 'X'       (Scale Z)");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "'I'       (Isometric View)");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "'P'     (Perspective View)");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "'O'             (Top View)");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "'SPACE'           (Colors)");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "'R'           (Reset View)");
}

static char	*get_view_name(t_fdf *fdf)
{	
	char	*projection;

	projection = "";
	if (fdf->cam->projection == ISOMETRIC)
		projection = "ISOMETRIC VIEW";
	else if (fdf->cam->projection == PERSPECTIVE)
		projection = "PERSPECTIVE VIEW";
	else if (fdf->cam->projection == TOP)
		projection = "TOP VIEW";
	return (projection);
}
