/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:50:38 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/14 22:09:49 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

void	ft_draw_map_as_vertical_projection(t_mlx *mlx)
{
	(void) mlx;
}

int	ft_init_image(t_mlx *mlx)
{
	t_image	*image;

	image = mlx_new_image(mlx->this, WIDTH, HEIGHT);
	if (!image)
	{
		mlx_destroy_window(mlx->this, mlx->win);
		return (ft_error("MLX_NEW_IMAGE", strerror(errno)));
	}
	mlx->image = image;
	mlx->ft_draw = ft_draw_map_as_vertical_projection;
	return (1);
}
