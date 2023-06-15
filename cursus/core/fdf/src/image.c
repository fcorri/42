/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:50:38 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/15 15:22:44 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

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
	return (1);
}
