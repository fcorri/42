/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:28:21 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/22 18:04:59 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

struct s_line_vars
{
	int	dstart;
	int	dstop;
	int	d;
	int	imain;
	int	icross;
};

static int	ft_init(struct s_line_vars *vars, int *stop, int y1)
{
	int	change_start;

	change_start = 0;
	if (vars->dstart < 0)
	{
		vars->imain = -1;
		vars->dstart *= -1;
	}
	else
		vars->imain = 1;
	if (vars->dstop < 0)
	{
		vars->icross = -1;
		vars->dstop *= -1;
	}
	else
		vars->icross = 1;
	if (vars->dstop > vars->dstart)
	{
		change_start = 1;
		*stop = y1;
		ft_swap(&vars->dstart, &vars->dstop);
		ft_swap(&vars->imain, &vars->icross);
	}
	return (change_start);
}

static void	ft_put_basic_line(t_image *img, t_vector start, t_vector end, t_bvector color)
{
	int	incremento;
	int	color;

	if (!d.mod)
		ft_put_pixel(*img, start.x, start.y, ft_calculate_color((t_bvector){start.z, end.z}, color));
	else
	{
		incremento = 1;
		if (d.mod < 0)
		{
			incremento = -1;
			d.mod *= -1;
		}
		while (d.mod--)
		{
			ft_put_pixel(*img, start.x, start.y, color);
			if (d.dir % 180)
				start.y += incremento;
			else
				start.x += incremento;
		}
	}
}

void	ft_put_line(t_image *img, t_point p0, t_point p1, int color)
{
	struct s_line_vars	vars;
	int					start;
	int					stop;
	int					tmp;
	int					main;

	start = p0.x;
	stop = p1.x;
	vars.dstart = stop - start;
	vars.dstop = p1.y - p0.y;
	if (vars.dstart == 0)
		return (ft_put_basic_line(img, p0, (t_dvector){vars.dstop, 90}, color));
	if (vars.dstop == 0)
		return (ft_put_basic_line(img, p0, (t_dvector){vars.dstart, 0}, color));
	tmp = p0.y;
	main = 1;
	if (ft_init(&vars, &stop, p1.y))
	{
		main = 0;
		start = p0.y;
		tmp = p0.x;
	}
	vars.d = (2 * vars.dstop) - vars.dstart;
	while (start != stop)
	{
		if (vars.d > 0)
		{
			vars.d -= 2 * vars.dstart;
			tmp += vars.icross;
		}
		vars.d += 2 * vars.dstop;
		start = ft_put_pixel_decorator(img, (t_point){start, tmp}, color, main) + vars.imain;
	}
}

void	ft_put_pixel(t_image img, int x, int y, int color)
{
	if ((0 <= x && x < WIDTH) && (0 <= y && y < HEIGHT))
		*(unsigned int *)(img.addr + (y * img.ll + x * (img.bpp / 8))) = color;
}
