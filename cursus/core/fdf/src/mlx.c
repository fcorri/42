/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:51:45 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/09 17:59:31 by fcorri           ###   ########.fr       */
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
		return (ft_null_error(strerror(errno)));
	win = mlx_new_window(this, WIDTH, HEIGHT, TITLE);
	if (!win)
	{
		errsv = errno;
		free(this);
		return (ft_null_error(strerror(errsv)));
	}
	mlx = malloc(sizeof(*mlx));
	mlx->this = this;
	mlx->win = win;
	return (mlx);
}
