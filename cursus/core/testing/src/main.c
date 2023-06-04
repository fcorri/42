/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:48:17 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/03 17:31:33 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <mlx.h>

typedef struct	s_data
{
	void	*this;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}	image;

static void	ft_pixel_put(image *img, int x, int y, int color)
{
	*(unsigned int *)(img->addr + (y * img->ll + x * (img->bpp / 8))) = color;
}

int main(void)
{
	void	*mlx;
	void	*win;
	image	img;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	win = mlx_new_window(mlx, 1000, 500, "Testing!");
	if (!win)
	{
		free(mlx);
		return (1);
	}
	img.this = mlx_new_image(mlx, 1000, 500);
	if (!img.this)
	{
		mlx_destroy_window(mlx, win);
		free(mlx);
		return (1);
	}
	img.addr = mlx_get_data_addr(img.this, &img.bpp, &img.ll, &img.endian);
	ft_pixel_put(img, 50, 50, 0x00FF0000);
	mlx_put_image_to_window(mlx, win, img.this, 0, 0);
	mlx_loop(mlx);
	return (0);
}

