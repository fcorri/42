/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:51:45 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/06 10:51:59 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

t_mlx	*ft_init_mlx(void)
{
	t_mlx	*mlx;
	void	*instance;
	void	*window;
	int		errsv;

	instance = mlx_init();
	if (!instance)
	{
		ft_error(strerror(errno));
		return (NULL);
	}
	window = mlx_new_window(instance, WIDTH, HEIGHT, TITLE);
	if (!window)
	{
		errsv = errno;
		free(instance);
		ft_error(strerror(errsv));
		return (NULL);
	}
	mlx = malloc(sizeof(*mlx));
	mlx->instance = instance;
	mlx->window = window;
	return (mlx);
}

void	ft_init_hooks(t_mlx *mlx)
{
	(void) mlx;
}
