/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmogid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:36:49 by larmogid          #+#    #+#             */
/*   Updated: 2023/05/01 22:36:01 by larmogid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	bresenham_implem(t_fdf *fdf, t_point start, t_point end)
{
	float	x_step;
	float	y_step;
	int		max_steps;
	int		i_line;
	t_color	*color;

	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max_steps = (int)max(abs_value(x_step), abs_value(y_step));
	x_step /= max_steps;
	y_step /= max_steps;
	color = col_init(start, end);
	if (!color)
		cl_all(fdf);
	i_line = 0;
	while (i_line < max_steps)
	{
		start.color = get_color(color, i_line++, max_steps);
		if (start.x > 0 && start.y > 0 && start.x < WIN_WIDTH && start.y < \
				WIN_HEIGHT)
			pixel_to_image(fdf->image, start.x, start.y, start.color);
		start.x += x_step;
		start.y += y_step;
	}
	free(color);
}

void	pixel_to_image(t_image *image, float x, float y, int color)
{
	int	pixel;

	pixel = ((int)y * image->line_bytes) + ((int)x * 4);
	if (image->endian == 1)
	{
		image->buffer[pixel + 0] = (color >> 24);
		image->buffer[pixel + 1] = (color >> 16) & 0xff;
		image->buffer[pixel + 2] = (color >> 8) & 0xff;
		image->buffer[pixel + 3] = (color) & 0xff;
	}
	else if (image->endian == 0)
	{
		image->buffer[pixel + 0] = (color) & 0xff;
		image->buffer[pixel + 1] = (color >> 8) & 0xff;
		image->buffer[pixel + 2] = (color >> 16) & 0xff;
		image->buffer[pixel + 3] = (color >> 24);
	}
}

void	clear_image(t_image *image, int image_size)
{
	int	x;
	int	y;

	ft_bzero(image->buffer, image_size);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			pixel_to_image(image, x, y, BACKGROUND_DEFAULT);
			x++;
		}
		y++;
	}
}
