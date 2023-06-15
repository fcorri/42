/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:32:16 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/15 17:43:24 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

int	ft_error(char *callee, char *with_message)
{
	ft_printf("ERROR %s: %s\n", callee, with_message);
	return (1);
}

void	*ft_null_error(char *callee, char *with_message)
{
	ft_error(callee, with_message);
	return (NULL);
}

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
