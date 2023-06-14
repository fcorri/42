/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:51:45 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/14 22:02:19 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

t_mlx	*ft_init_mlx(t_map *map)
{
	t_mlx	*mlx;
	void	*this;
	void	*win;
	int		errsv;

	this = mlx_init();
	if (!this)
		return (ft_null_error("MLX_INIT", strerror(errno)));
	win = mlx_new_window(this, WIDTH, HEIGHT, TITLE);
	if (!win)
	{
		errsv = errno;
		free(this);
		return (ft_null_error("MLX_NEW_WINDOW", strerror(errsv)));
	}
	mlx = malloc(sizeof(*mlx));
	mlx->this = this;
	mlx->win = win;
	mlx->map = map;
	return (mlx);
}
