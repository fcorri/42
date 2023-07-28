/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:48:17 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/28 15:55:21 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "mlx.h"
#include <stdint.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdlib.h>

#define WIDTH 1000
#define HEIGHT 750

typedef struct vector2
{
	int	x;
	int	y;
}	t_vector2;

typedef struct vector3
{
	float	x;
	float	y;
	float	z;
}	t_vector3;

typedef struct point
{
	t_vector3	v;
	int			color;
}	t_point;


typedef struct mlx
{
	void	*this;
	void	*win;
}	t_mlx;

typedef struct image
{
	void	*this;
	char	*addr;
	int		bpp;
	int		ll;
	int		end;
}	t_image;

typedef struct s_vars
{
	t_mlx		*mlx;
	t_image		*image;
}	t_vars;

static int	ft_key_down(int k, t_vars *vars)
{
	if (k == XK_Escape)
		mlx_loop_end(vars->mlx->this);
	return (0);
}

static int	max_abs_and_norm(int *p_a, int *p_b)
{
	int	a;
	int	b;

	a = *p_a;
	b = *p_b;
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a)
		*p_a /= a;
	if (b)
		*p_b /= b;
	if (a >= b)
		return (a);
	return (b);
}

static void	ft_put_pixel(t_image *img, t_vector3 p, int color)
{
	if ((0 <= p.x && p.x < WIDTH) && (0 <= p.y && p.y < HEIGHT))
		*(unsigned int *)(img->addr + (int) (p.y * img->ll + p.x * (img->bpp / 8))) = color;
}

static int	ft_interpolate_colors(int s, int e, float i, float n)
{
	uint8_t	tmps;
	uint8_t	tmpe;
	int		output;

	tmps = (s >> 16) & 0xFF;
	tmpe = (e >> 16) & 0xFF;
	output = (int) ((tmpe - tmps) * (i / n) + tmps) << 16;
	tmps = (s >> 8) & 0xFF;
	tmpe = (e >> 8) & 0xFF;
	output |= (int) ((tmpe - tmps) * (i / n) + tmps) << 8;
	tmps = s & 0xFF;
	tmpe = e & 0xFF;
	output |= (int) ((tmpe - tmps) * (i / n) + tmps);
	return (output);
}

static void    ft_put_line(t_image *image, t_point p0, t_point p1)
{
	t_vector2	delta;
	int			steps;
	int			i;

	delta.x = p1.v.x - p0.v.x;
	delta.y = p1.v.y - p0.v.y;
	steps = max_abs_and_norm(&delta.x, &delta.y);
	i = -1;
	while (i++ < steps)
	{
		ft_put_pixel(image, p0.v, ft_interpolate_colors(p0.color, p1.color, i, steps));
		p0.v.x += delta.x;
		p0.v.y += delta.y;
	}
}
//[240.000000, 239.000000, 7.000000] [260.000000, 238.000000, 17.000000]
int main(void)
{
	t_vars	vars;
	t_point	p0, p1;

	
	vars.mlx = malloc(sizeof(t_mlx));
	vars.image = malloc(sizeof(t_image));
	vars.mlx->this = mlx_init();
	vars.mlx->win = mlx_new_window(vars.mlx->this, WIDTH, HEIGHT, "HELLO, WORLD!");
	vars.image->this = mlx_new_image(vars.mlx->this, WIDTH, HEIGHT);
	vars.image->addr = mlx_get_data_addr(vars.image->this, &vars.image->bpp, &vars.image->ll, &vars.image->end);
	mlx_hook(vars.mlx->win, 2, 1L<<0, ft_key_down, &vars);
	p0 = (t_point){240, 239, 7, 0xff0000};
	p1 = (t_point){260, 238, 17, 0xff00};
	ft_put_line(vars.image, p0, p1);
	mlx_put_image_to_window(vars.mlx->this, vars.mlx->win, vars.image->this, 0, 0);
	mlx_loop(vars.mlx->this);
	return (0);
}
