/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:22:48 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/04 18:36:10 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

void	ft_zoom_on(t_vars *vars, int k)
{
	int	tmp;
	int	zoom;

	zoom = vars->map->zoom.x; 
	tmp = zoom * k;
	if (tmp == zoom * k)
		vars->map->zoom.x = tmp;
	zoom = vars->map->zoom.y;
	tmp = zoom * k;
	if (tmp == zoom * k)
		vars->map->zoom.y = tmp;
}

void	ft_zoom_off(t_vars *vars, int k)
{
	int	tmp;

	tmp = vars->map->zoom.x / k;
	if (!tmp)
		tmp = 1;
	vars->map->zoom.x = tmp;
	tmp = vars->map->zoom.y / k;
	if (!tmp)
		tmp = 1;
	vars->map->zoom.y = tmp;
}
