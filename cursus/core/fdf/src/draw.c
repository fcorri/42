/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:11:07 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/17 19:00:52 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

void	ft_draw_map_as_isometric_projection(t_vars *vars)
{
	t_mlx	*mlx;
	t_image	*image;

	mlx = vars->mlx;
	image = vars->image;
	ft_put_line(image, (t_point){WIDTH / 2, HEIGHT / 2}, (t_point){WIDTH / 2, HEIGHT /2}, 0x00FF0000);
	mlx_put_image_to_window(mlx->this, mlx->win, image->this, 0, 0);
}
