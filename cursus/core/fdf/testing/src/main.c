/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:48:17 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/06 08:52:44 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <mlx.h>
#include <math.h>
#include <X11/keysym.h>

#define X	1000
#define Y	500

typedef struct image
{
	void	*this;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}	t_image;

typedef struct point
{
	int	x;
	int	y;
}	t_point;

typedef struct mlx
{
	void	*this;
	void	*win;
}	t_mlx;

struct s_line_vars
{
	int	dmain;
	int	dcross;
	int	d;
	int	imain;
	int	icross;
};

typedef struct vector
{
	int	mod;
	int	dir;
}	t_vector;

static void	ft_put_pixel(t_image img, int x, int y, int color)
{
	if ((0 <= x && x < X) && (0 <= y && y < Y))
		*(unsigned int *)(img.addr + (y * img.ll + x * (img.bpp / 8))) = color;
}

static void	ft_swap(int *first, int *second)
{
	int	tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

static int	ft_init(struct s_line_vars *vars, int *stop, int y1)
{
	int	change_start;

	change_start = 0;
	if (vars->dmain < 0)
	{
		vars->imain = -1;
		vars->dmain *= -1;
	}
	else
		vars->imain = 1;
	if (vars->dcross < 0)
	{
		vars->icross = -1;
		vars->dcross *= -1;
	}
	else
		vars->icross = 1;
	if (vars->dcross > vars->dmain)
	{
		change_start = 1;
		*stop = y1;
		ft_swap(&vars->dmain, &vars->dcross);
		ft_swap(&vars->imain, &vars->icross);
	}
	return (change_start);
}

static void	ft_put_basic_line(t_image img, t_point start, t_vector d, int color)
{
	int	main_axis;

	main_axis = 1;
	if (!d.mod)
	{
		ft_put_pixel(img, start.x, start.y, color);
		return ;
	}
	if (d.dir)
		main_axis = 0;
	if (main_axis)
		while (d.mod--)
			ft_put_pixel(img, start.x, start.y++, color);
	else
		while (d.mod--)
			ft_put_pixel(img, start.x++, start.y, color);
}

static int	ft_put_pixel_decorator(t_image img, int x, int y, int color, int main)
{
	if (main)
		ft_put_pixel(img, x, y, color);
	else
		ft_put_pixel(img, y, x, color);
	return (x);
}

static void	ft_put_line(t_image img, t_point p0, t_point p1, int color)
{
	struct s_line_vars	vars;
	int					start;
	int					stop;
	int					tmp;
	int	main;

	start = p0.x;
	stop = p1.x;
	vars.dmain = p1.x - p0.x;
	vars.dcross = p1.y - p0.y;
	if (vars.dmain == 0)
		return (ft_put_basic_line(img, p0, (t_vector){vars.dcross, 90}, color));
	if (vars.dcross == 0)
		return (ft_put_basic_line(img, p0, (t_vector){vars.dmain, 0}, color));
	tmp = p0.y;
	main = 1;
	if (ft_init(&vars, &stop, p1.y))
	{
		main = 0;
		start = p0.y;
		tmp = p0.x;
	}
	vars.d = (2 * vars.dcross) - vars.dmain;
	while (start != stop)
	{
		if (vars.d > 0)
		{
			vars.d -= 2 * vars.dmain;
			tmp += vars.icross;
		}
		vars.d += 2 * vars.dcross;
		start = ft_put_pixel_decorator(img, start, tmp, color, main) + vars.imain;
	}
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

static void	ft_put_lines(t_image img, int x, int y, int dx, int dy, int color)
{
	ft_put_line(img, (t_point){x, y}, (t_point){x - dx, y - dy}, color);
	ft_put_line(img, (t_point){x, y}, (t_point){x - dx, y + dy}, color);
	ft_put_line(img, (t_point){x, y}, (t_point){x + dx, y - dy}, color);
	ft_put_line(img, (t_point){x, y}, (t_point){x + dx, y + dy}, color);
}


int	main(void)
{
	t_mlx	mlx;
	int		x;
	int		dx;
	int		y;
	int		dy;
	int		red;
	t_image	img;

	mlx.this = mlx_init();
	if (!mlx.this)
		return (1);
	mlx.win = mlx_new_window(mlx.this, X, Y, "Testing!");
	if (!mlx.win)
	{
		free(mlx.this);
		return (1);
	}
	img.this = mlx_new_image(mlx.this, X, Y);
	if (!img.this)
	{
		mlx_destroy_window(mlx.this, mlx.win);
		free(mlx.this);
		return (1);
	}
	mlx_loop_hook(mlx.this, ft_no_event, &mlx);
	mlx_hook(mlx.win, 2, 1L<<0, ft_exit, &mlx);
	img.addr = mlx_get_data_addr(img.this, &img.bpp, &img.ll, &img.endian);
	x = X / 2;
	y = Y / 2;
	dx = 50;
	dy = 35;
	red = 0x00ff0000;
	mlx_put_image_to_window(mlx.this, mlx.win, img.this, 0, 0);
	int tmp = 100;
	while (tmp--)
	{
		ft_put_lines(img, x, y, dx, dy, red);
		dx += 10;
		dy += 15;
	}
	mlx_loop(mlx.this);
	mlx_destroy_display(mlx.this);
	free(mlx.this);
	return (0);
}
