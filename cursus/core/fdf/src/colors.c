/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:26:19 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/30 18:06:02 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

int	ft_to_int(t_vector3 color)
{
	return (((int) color.x & RED) | ((int) color.y & GREEN) | ((int) color.z & BLUE));
}

t_vector3	ft_to_vector(int color)
{
	return ((t_vector3){color & RED, color & GREEN, color & BLUE});
}

void	ft_add_colors(t_colors *colors)
{
	colors->start.x += colors->step.x;
	colors->start.y += colors->step.y;
	colors->start.z += colors->step.z;
}

t_colors	ft_init_line_colors_with(int s, int e, float n)
{
	t_vector3	output;

	if (!n || s == e)
		return ((t_colors){ft_to_vector(s), (t_vector3){0, 0, 0}});
	output.x = ((e & RED) - (s & RED)) / n;
	output.y = ((e & GREEN) - (s & GREEN)) / n;
	output.z = ((e & BLUE) - (s & BLUE)) / n;
		return ((t_colors){ft_to_vector(s), output});
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
