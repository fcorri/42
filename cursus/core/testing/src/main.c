/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:48:17 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/03 17:08:14 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <mlx.h>

int main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	win = mlx_new_window(mlx, 1000, 500, "Testing!");
	if (!win)
	{
		free(mlx);
		return (1);
	}
	mlx_loop(mlx);
	return (0);
}

