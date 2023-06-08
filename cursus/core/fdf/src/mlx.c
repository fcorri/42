/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:51:45 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/08 17:30:06 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

t_mlx	*ft_init_mlx(void)
{
	t_mlx	*mlx;
	void	*this;
	void	*win;
	int		errsv;

	this = mlx_init();
	if (!this)
	{
		ft_error(strerror(errno));
		return (NULL);
	}
	win = mlx_new_window(this, WIDTH, HEIGHT, TITLE);
	if (!win)
	{
		errsv = errno;
		free(this);
		ft_error(strerror(errsv));
		return (NULL);
	}
	mlx = malloc(sizeof(*mlx));
	mlx->this = this;
	mlx->win = win;
	return (mlx);
}

static int	ft_no_event(t_mlx *mlx)
{
	(void) mlx;
	return (0);
}

static int	ft_exit(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		mlx_destroy_window(mlx->this, mlx->win);
	return (0);
}

void	ft_init_hooks(t_mlx *mlx)
{
	mlx_loop_hook(mlx->this, ft_no_event, &mlx);
	mlx_hook(mlx->win, 2, 1L<<0, ft_exit, &mlx);
}
