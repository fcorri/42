/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:28:21 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/26 20:13:42 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"
/*
struct s_line_vars
{
	int	dmain;
	int	dcross;
	int	d;
	int	imain;
	int	icross;
};

static int	ft_init_di(int *d, int *i)
{
	if (*d < 0)
	{
		*i = -1;
		*d *= -1;
		return (1);
	}
	*i = 1;
	return (0);
}

static t_vector ft_cv(t_color color)
{
	return (
		(t_vector){color.x, color.y, color.z}
	);
}

static t_color ft_vc(t_vector v)
{
	return (
		(t_color){v.x, v.y, v.z}
	);
}

static int	ft_init(struct s_line_vars *vars, int *stop, int y1)
{
	int	change_start;

	change_start = 0;
	ft_init_di(&vars->dmain, &vars->imain);
	ft_init_di(&vars->dcross, &vars->icross);
	if (vars->dcross > vars->dmain)
	{
		change_start = 1;
		*stop = y1;
		ft_swap(&vars->dmain, &vars->dcross);
		ft_swap(&vars->imain, &vars->icross);
	}
	return (change_start);
}

static void	ft_put_basic_line(t_image *img, t_vector start, t_dvector d, t_bvector colors)
{
	int	incremento;
	t_color	color;
	t_color	dcolor;

	color = ft_new_vector_color_decorator(colors.x);
	if (!d.mod)
		ft_put_pixel(img, (t_bvector){start.x, start.y}, color);
	else
	{
		dcolor = ft_vc(ft_mul_scalar(ft_add_vector(ft_cv(ft_new_vector_color_decorator(colors.y)),ft_mul_scalar(ft_cv(color),-1)),1.0/(d.mod)));
		d.dir %= 180;
		ft_init_di(&d.mod, &incremento);
		while (d.mod--)
		{
			ft_put_pixel(img, (t_bvector){start.x, start.y}, color);
			if (d.dir)
				start.y += incremento;
			else
				start.x += incremento;
			color = ft_vc(ft_add_vector(ft_cv(color), ft_cv(dcolor)));
		}
	}
}

static void	ft_set_start_end_colors(t_bvector d, t_bvector z, t_bvector *colors)
{
	if (d.x < 0 || (d.x == 0 && (d.y < 0 || (d.y == 0 && z.y > z.x))))
		ft_swap(&colors->x, &colors->y);
}

void	ft_put_line(t_image *img, t_vector v0, t_vector v1, t_bvector colors)
{
	struct s_line_vars	vars;
	int	start;
	int	stop;
	int	tmp;
	t_color	color;
	t_color	dcolor;

	start = v0.x;
	stop = v1.x;
	vars.dmain = stop - start;
	vars.dcross = v1.y - v0.y;	
	ft_set_start_end_colors((t_bvector){vars.dmain, vars.dcross}, (t_bvector){v0.z, v1.z}, &colors);
	if (vars.dmain == 0)
		return (ft_put_basic_line(img, v0, (t_dvector){vars.dcross, 90}, colors));
	if (vars.dcross == 0)
		return (ft_put_basic_line(img, v0, (t_dvector){vars.dmain, 0}, colors));
	tmp = v0.y;
	if (ft_init(&vars, &stop, v1.y))
	{
		start = v0.y;
		tmp = v0.x;
	}
	vars.d = (2 * vars.dcross) - vars.dmain;
	color = ft_new_vector_color_decorator(colors.x);
	dcolor = ft_vc(ft_mul_scalar(ft_add_vector(ft_cv(ft_new_vector_color_decorator(colors.y)),ft_mul_scalar(ft_cv(color),-1)),1.0/(stop - start)));
	while (start != stop)
	{
		if (vars.d > 0)
		{
			vars.d -= 2 * vars.dmain;
			tmp += vars.icross;
		}
		vars.d += 2 * vars.dcross;
		ft_put_pixel(img, (t_bvector){start, tmp}, color);
		start += vars.imain;
		color = ft_vc(ft_add_vector(ft_cv(color), ft_cv(dcolor)));
	}
}
*/

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
	*p_a /= a;
	*p_b /= b;
	if (a >= b)
		return (a);
	return (b);
}

static void	ft_put_pixel(t_image *img, int x, int y, int color)
{
	if ((0 <= x && x < WIDTH) && (0 <= y && y < HEIGHT))
		*(unsigned int *)(img->addr + (y * img->ll + x * (img->bpp / 8))) = color;
}

static int	ft_get_step_color(int start, int end, int steps)
{
	return (
		(((end & RED) - (start & RED)) / steps) |
		(((end & GREEN) - (start & GREEN)) / steps) |
		(((end & BLUE) - (start & BLUE)) / steps)
	);
}

void    ft_put_line(t_image *image, t_point p0, t_point p1)
{
	t_vector2	delta;
	int			steps;
	t_color		start;
	t_color		step;

	delta.x = p1.v.x - p0.v.x;
	delta.y = p1.v.y - p0.v.y;
	steps = max_abs_and_norm(&delta.x, &delta.y);
	start = p0.color;
	step = ft_get_step_color(p0.color, p1.color, steps);
	while (steps--)
	{
		ft_put_pixel(image, p0.v.x, p0.v.y, colors.x);
		p0.v.x += delta.x;
		p0.v.y += delta.y;
		start = ft_add_color(start, step);
	}
}
