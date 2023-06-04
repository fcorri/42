/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:48:17 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/04 16:23:44 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <mlx.h>

typedef struct s_data
{
	void	*this;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}	t_image;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

static void	ft_put_pixel(t_image *img, int x, int y, int color)
{
	*(unsigned int *)(img->addr + (y * img->ll + x * (img->bpp / 8))) = color;
}

static void	ft_put_line(t_image *img, t_point p0, t_point p1, int color)
{
	int	dx;
	int	dy;
	int	d;
	int	x;
	int	y;

	x = p0.x;
	y = p0.y;
	dx = p1.x - x;
	dy = p1.y - y;
	d = (2 * dy) - dx;
	while (x != p1.x)
	{
		ft_put_pixel(img, x, y, color);
		if (d > 0)
		{
			d -= 2 * dx;
			y += 1;
		}
		d += 2 * dy;
		x += 1;
	}
}

int	main(void)
{
	void	*mlx;
	void	*win;
	t_image	img;

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
	ft_put_line(&img, (t_point){500, 250}, (t_point){600, 300}, 0x00ff0000);
	mlx_put_image_to_window(mlx, win, img.this, 0, 0);
	mlx_loop(mlx);
	return (0);
}
