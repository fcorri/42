/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:10:26 by fcorri            #+#    #+#             */
/*   Updated: 2023/05/22 23:47:35 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

t_map	*ft_init_map(int with_fd)
{
	
}

t_mlx	*ft_init_mlx(void)
{
	t_mlx	*mlx;
	void	*instance;
	void	*window;

	instance = mlx_init();
	if (!instance)
	{
		ft_error("mlx_init() failed.");
		return (NULL);
	}
	window = mlx_new_window(instance, WIDTH, HEIGHT, TITLE);
	if (!window)
	{
		free(instance);
		ft_error("mlx_new_window() failed.");
		return (NULL);
	}
	mlx = ft_malloc(sizeof(*mlx));
	mlx->instance = instance;
	mlx->window = window;
	return (mlx);
}

void	ft_init_hooks(t_mlx *mlx)
{
	
}
