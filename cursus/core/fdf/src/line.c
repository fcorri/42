/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:28:21 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/15 11:38:23 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static struct s_vars
{
	int	dmain;
	int	dcross;
	int	d;
	int	imain;
	int	icross;
};

static int	ft_init(struct s_vars *vars, int *stop, int y1)
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

static void	ft_put_basic_line(t_image img, t_point start, t_point d, int color)
{
	int	length;
	int	direction;

	length = ft_length(d);
	direction = ft_direction(d);
	if (!length)
	{
		ft_put_pixel(img, start.x, start.y, color);
		return ;
	}
	if (direction == 1)
		while (length--)
			ft_put_pixel(img, start.x, start.y++, color);
	else
		while (length--)
			ft_put_pixel(img, start.x++, start.y, color);
}

void	ft_put_line(t_image img, t_point p0, t_point p1, int color)
{
	struct s_line_vars	vars;
	int					start;
	int					stop;
	int					tmp;
	int					main;

	start = p0.x;
	stop = p1.x;
	vars.dmain = p1.x - p0.x;
	vars.dcross = p1.y - p0.y;
	if (vars.dmain == 0)
		return (ft_put_basic_line(img, p0, (t_point){vars.dcross, 90}, color));
	if (vars.dcross == 0)
		return (ft_put_basic_line(img, p0, (t_point){vars.dmain, 0}, color));
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
