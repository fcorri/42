/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:28:21 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/28 12:08:42 by fcorri           ###   ########.fr       */
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

int	ft_interpolate_colors(int s, int e, float i, float n)
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

void    ft_put_line(t_image *image, t_point p0, t_point p1)
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
