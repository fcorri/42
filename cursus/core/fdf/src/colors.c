/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:26:19 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/04 16:12:24 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

int	ft_to_int(t_v3 color)
{
	return (((int) color.x & R) | ((int) color.y & G) | ((int) color.z & B));
}

t_v3	ft_to_vector(int color)
{
	return ((t_v3){color & R, color & G, color & B});
}

void	ft_add_colors(t_lc *colors)
{
	colors->start.x += colors->step.x;
	colors->start.y += colors->step.y;
	colors->start.z += colors->step.z;
}

t_lc	ft_init_line_colors_with(int s, int e, float n)
{
	t_v3	output;

	if (!n || s == e)
		return ((t_lc){ft_to_vector(s), (t_v3){0, 0, 0}});
	output.x = ((e & R) - (s & R)) / n;
	output.y = ((e & G) - (s & G)) / n;
	output.z = ((e & B) - (s & B)) / n;
	return ((t_lc){ft_to_vector(s), output});
}

int	ft_interpolate_colors(int s, int e, float i, float n)
{
	uint8_t	tmps;
	uint8_t	tmpe;
	int		output;

	if (!n)
		return (s);
	tmps = (s >> 16) & 0xFF;
	tmpe = (e >> 16) & 0xFF;
	output = (int)((tmpe - tmps) * (i / n) + tmps) << 16;
	tmps = (s >> 8) & 0xFF;
	tmpe = (e >> 8) & 0xFF;
	output |= (int)((tmpe - tmps) * (i / n) + tmps) << 8;
	tmps = s & 0xFF;
	tmpe = e & 0xFF;
	output |= (int)((tmpe - tmps) * (i / n) + tmps);
	return (output);
}
