/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:28:21 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/27 13:18:45 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

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
