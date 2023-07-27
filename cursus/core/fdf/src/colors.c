/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:42:25 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/26 20:10:02 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

t_color	ft_get_color(t_vars *vars, int s, int e, double range)
{
	(void) vars;
	if (range)
		return (e);
	return (s);
}

t_color	ft_add_color(t_color a, t_color b)
{
	return (
		(t_color)
		{
			a.t + b.t,
			a.r + b.r,
			a.g + b.g,
			a.b + b.b,
		});
}
