/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:18:31 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/31 20:23:38 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

void	ft_isometric(t_vars *vars)
{
	ft_restore_camera(vars);
	ft_rot(vars, (t_v3){0, 0, 1}, 45);
	ft_rot(vars, (t_v3){1, 0, 0}, 35.264);
}

void	ft_orthogonal(t_vars *vars)
{
	ft_restore_camera(vars);
}

void	ft_perspective(t_vars *vars)
{
	ft_restore_camera(vars);
}
