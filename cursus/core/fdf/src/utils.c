/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:32:16 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/14 22:50:43 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *first, int *second)
{
	int	tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

void	ft_put_pixel(t_image img, int x, int y, int color)
{
	if ((0 <= x && x < X) && (0 <= y && y < Y))
		*(unsigned int *)(img.addr + (y * img.ll + x * (img.bpp / 8))) = color;
}
