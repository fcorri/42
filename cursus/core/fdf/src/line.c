/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:28:21 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/30 17:54:25 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static void	ft_put_pixel(t_image *img, t_vector3 p, int color)
{
	if ((0 <= p.x && p.x < WIDTH) && (0 <= p.y && p.y < HEIGHT))
		*(unsigned int *)(img->addr + (int) (((int)p.y) * img->ll + ((int)p.x) * (img->bpp / 8))) = color;
}

static int	ft_init_delta_incr_err_with(t_point p0, t_point p1, t_vector2 *delta, t_vector2 *incr)
{
	*delta = (t_vector2){ft_abs(p1.v.x - p0.v.x), -ft_abs(p1.v.y - p0.v.y)};
	*incr = (t_vector2){1, 1};
	if (p0.v.x >= p1.v.x)
		incr->x = -1;
	if (p0.v.y >= p1.v.y)
		incr->y = -1;
	return (delta->x + delta->y);
}

void    ft_put_line(t_image *image, t_point p0, t_point p1)
{
	int			steps;
	t_colors	colors;
	t_vector2	delta;
	t_vector2	incr;
	t_vector2	err;

	steps = ft_max(ft_abs(p1.v.x - p0.v.x), ft_abs(p1.v.y - p0.v.y));
	colors = ft_init_line_colors_with(p0.color, p1.color, steps);
	err.x = ft_init_delta_incr_err_with(p0, p1, &delta, &incr);
	while (steps-- >= 0)
	{
		ft_put_pixel(image, p0.v, ft_to_int(colors.start));
		err.y = err.x << 1;
		if (err.y >= delta.y)
		{
			err.x += delta.y;
			p0.v.x += incr.x;
		}
		if (err.y <= delta.x)
		{
			err.x += delta.x;
			p0.v.y += incr.y;
		}
		ft_add_colors(&colors);
	}
}
