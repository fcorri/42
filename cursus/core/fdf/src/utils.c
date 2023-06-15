/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:32:16 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/15 11:01:34 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

void	ft_swap(int *first, int *second)
{
	int	tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

void	ft_put_pixel(t_image img, int x, int y, int color)
{
	if ((0 <= x && x < WIDTH) && (0 <= y && y < HEIGHT))
		*(unsigned int *)(img.addr + (y * img.ll + x * (img.bpp / 8))) = color;
}
